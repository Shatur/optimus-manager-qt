/*
 *  Copyright © 2019-2022 Hennadii Chernyshchyk <genaloner@gmail.com>
 *
 *  This file is part of Optimus Manager Qt.
 *
 *  Optimus Manager Qt is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Optimus Manager Qt is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Optimus Manager Qt. If not, see <https://www.gnu.org/licenses/>.
 */

#include "optimusmanager.h"

#include "daemonclient.h"
#include "session.h"
#include "settings/settingsdialog.h"

#include <QCoreApplication>
#include <QDBusArgument>
#include <QDBusInterface>
#include <QDirIterator>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMenu>
#include <QMessageBox>
#include <QMetaEnum>
#include <QProcess>
#include <QSettings>
#ifdef WITH_PLASMA
#include <KStatusNotifierItem>
#else
#include <QSystemTrayIcon>
#endif

#include <csignal>

OptimusManager::OptimusManager(QObject *parent)
    : QObject(parent)
    , m_contextMenu(new QMenu)
#ifdef WITH_PLASMA
    , m_trayIcon(new KStatusNotifierItem(this))
#else
    , m_trayIcon(new QSystemTrayIcon(this))
#endif
    , m_currentMode(detectGpu())
{
    // Set localization
    AppSettings appSettings;
    appSettings.setupLocalization();

    // Setup context menu
    m_openSettingsAction = m_contextMenu->addAction(QIcon::fromTheme(QStringLiteral("configure")), SettingsDialog::tr("Settings"), this, &OptimusManager::openSettings);
    m_contextMenu->addSeparator();

    const QMetaEnum modeEnum = QMetaEnum::fromType<OptimusSettings::Mode>();
    m_switchToIntegratedAction = m_contextMenu->addAction(tr("Switch to %1").arg(modeEnum.key(OptimusSettings::Integrated)), this, &OptimusManager::switchToIntegrated);
    m_switchToNvidiaAction = m_contextMenu->addAction(tr("Switch to %1").arg(modeEnum.key(OptimusSettings::Nvidia)), this, &OptimusManager::switchToNvidia);
    m_switchToHybridAction = m_contextMenu->addAction(tr("Switch to %1").arg(modeEnum.key(OptimusSettings::Hybrid)), this, &OptimusManager::switchToHybrid);
    m_contextMenu->addSeparator();

    m_exitAction = m_contextMenu->addAction(QIcon::fromTheme(QStringLiteral("application-exit")), tr("Quit"), QCoreApplication::instance(), &QCoreApplication::quit);

    // Setup tray
#ifdef WITH_PLASMA
    m_trayIcon->setStandardActionsEnabled(false);
    m_trayIcon->setToolTipTitle(QCoreApplication::applicationName());
    m_trayIcon->setCategory(KStatusNotifierItem::SystemServices);
    m_trayIcon->setToolTipSubTitle(tr("Current video card: %1").arg(QMetaEnum::fromType<OptimusSettings::Mode>().valueToKey(m_currentMode)));
#endif
    m_trayIcon->setContextMenu(m_contextMenu);

    loadSettings(appSettings);

#ifndef WITH_PLASMA
    m_trayIcon->show();
#endif
}

OptimusManager::~OptimusManager()
{
#ifndef WITH_PLASMA
    delete m_contextMenu; // QSystemTrayIcon does not take ownership of QMenu
#endif
}

void OptimusManager::switchToIntegrated()
{
    switchMode(OptimusSettings::Integrated);
}

void OptimusManager::switchToNvidia()
{
    switchMode(OptimusSettings::Nvidia);
}

void OptimusManager::switchToHybrid()
{
    switchMode(OptimusSettings::Hybrid);
}

void OptimusManager::openSettings()
{
    SettingsDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
        return;

    if (dialog.isLanguageChanged())
        retranslateUi();

    AppSettings settings;
    loadSettings(settings);
}

void OptimusManager::showNotification(const QString &title, const QString &message)
{
#ifdef WITH_PLASMA
    m_trayIcon->showMessage(title, message, m_trayIcon->iconName());
#else
    m_trayIcon->showMessage(title, message);
#endif
}

void OptimusManager::loadSettings(AppSettings &appSettings)
{
    // Context menu icons
    m_switchToIntegratedAction->setIcon(appSettings.modeIcon(OptimusSettings::Integrated));
    m_switchToNvidiaAction->setIcon(appSettings.modeIcon(OptimusSettings::Nvidia));
    m_switchToHybridAction->setIcon(appSettings.modeIcon(OptimusSettings::Hybrid));

    // Tray icon
    QString modeIconName = appSettings.modeIconName(m_currentMode);
    if (!QIcon::hasThemeIcon(modeIconName) && !QFileInfo::exists(modeIconName)) {
        modeIconName = AppSettings::defaultModeIconName(m_currentMode);
        appSettings.setModeIconName(m_currentMode, modeIconName);
        showNotification(tr("Invalid icon"), tr("The specified icon '%1' for the current GPU is invalid. The default icon will be used.").arg(modeIconName));
    }
#ifdef WITH_PLASMA
    m_trayIcon->setIconByName(modeIconName);
    m_trayIcon->setToolTipIconByName(m_trayIcon->iconName());
#else
    m_trayIcon->setIcon(QIcon::fromTheme(modeIconName));
#endif
}

void OptimusManager::retranslateUi()
{
#ifdef WITH_PLASMA
    m_trayIcon->setToolTipSubTitle(tr("Current video card: %1").arg(QMetaEnum::fromType<OptimusSettings::Mode>().valueToKey(m_currentMode)));
#endif
    m_openSettingsAction->setText(SettingsDialog::tr("Settings"));

    const QMetaEnum modeEnum = QMetaEnum::fromType<OptimusSettings::Mode>();
    m_switchToIntegratedAction->setText(tr("Switch to %1").arg(modeEnum.key(OptimusSettings::Integrated)));
    m_switchToNvidiaAction->setText(tr("Switch to %1").arg(modeEnum.key(OptimusSettings::Nvidia)));
    m_switchToHybridAction->setText(tr("Switch to %1").arg(modeEnum.key(OptimusSettings::Hybrid)));

    m_exitAction->setText(tr("Quit"));
}

void OptimusManager::switchMode(OptimusSettings::Mode switchingMode)
{
    const AppSettings appSettings;
    const OptimusSettings optimusSettings;

    // Confirm message
    if (appSettings.isConfirmSwitching()) {
        QMessageBox message;
        message.setStandardButtons(QMessageBox::Apply | QMessageBox::Cancel);
        message.setIcon(QMessageBox::Question);
        message.setText(tr("You are about to switch GPU."));
        if (optimusSettings.isAutoLogoutEnabled())
            message.setInformativeText(tr("You will be automatically logged out to apply the changes."));
        else
            message.setInformativeText(tr("After applying the settings, you will need to manually re-login to change the video card."));
        if (message.exec() != QMessageBox::Apply)
            return;
    }

    // Check if daemon is active
    if (const QString daemon = QStringLiteral("optimus-manager.service"); !isServiceActive(daemon) && !QFileInfo::exists(QStringLiteral("/var/service/optimus-manager/run"))) {
        QMessageBox message;
        message.setIcon(QMessageBox::Critical);
        message.setText(tr("The %1 is not running.").arg(daemon));
        message.setInformativeText(tr("Please enable and start it with:\n'%1'\n'%2'")
                                       .arg("sudo systemctl enable optimus-manager", "sudo systemctl start optimus-manager"));
        message.exec();
        return;
    }

    // Check if power switching enabled
    if (optimusSettings.switchingMethod() == OptimusSettings::NoneMethod
        && !optimusSettings.isPciPowerControlEnabled()
        && optimusSettings.nvidiaDynamicPowerManagement() == OptimusSettings::No) {
        QMessageBox message;
        message.setIcon(QMessageBox::Warning);
        message.setText(tr("No power management option is currently enabled"));
        message.setInformativeText(tr("Switching between GPUs will work but you will likely experience poor battery life.<br>"
                                      "Follow <a href='https://github.com/Askannz/optimus-manager/wiki/A-guide--to-power-management-options'>these</a> instructions"
                                      " to enable power management."));
        message.exec();
    }

    // Check if bbswitch module is available
    if (optimusSettings.switchingMethod() == OptimusSettings::Bbswitch) {
        if (const QString bbswitch = QStringLiteral("bbswitch"); !isModuleAvailable(bbswitch)) {
            QMessageBox message;
            message.setIcon(QMessageBox::Warning);
            message.setText(tr("The %1 module does not seem to be available for the current kernel.").arg(bbswitch));
            message.setInformativeText(tr("Power switching will not work.\n"
                                          "You can set '%1' for GPU switching in settings or install bbswitch for"
                                          " the default kernel with '%2' or for all kernels with '%3'.")
                                           .arg("nouveau", "sudo pacman -S bbswitch", "sudo pacman -S bbswitch-dkms"));
            message.exec();
        }
    }

    // Check if nvidia module is available
    if (switchingMode == OptimusSettings::Nvidia) {
        if (const QString nvidia = QStringLiteral("nvidia"); !isModuleAvailable(nvidia)) {
            QMessageBox message;
            message.setIcon(QMessageBox::Question);
            message.setText(tr("The %1 module does not seem to be available for the current kernel.").arg(nvidia));
            message.setInformativeText(tr("It is likely the Nvidia driver was not properly installed. GPU switching will probably fail, continue anyway?"));
            message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            if (message.exec() == QMessageBox::No)
                return;
        }
    }

    // Check if GDM is patched
    if (currentDisplayManager() == QLatin1String("/usr/bin/gdm") && !isGdmPatched()) {
        QMessageBox message;
        message.setIcon(QMessageBox::Question);
        message.setText(tr("Looks like you're using a non-patched version of the GNOME Display Manager (GDM)."));
        message.setInformativeText(tr("GDM need to be patched for Prime switching. Follow <a href='https://github.com/Askannz/optimus-manager'>this</a>"
                                      " instructions to install a patched version. Without a patched GDM version, GPU switching will likely fail.\n"
                                      "Continue anyway?"));
        message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (message.exec() == QMessageBox::No)
            return;
    }

    // Check number of sessions
    const QVector<Session> sessions = activeSessions();
    if (const int activeSessions = sessionsCountWithoutGdm(sessions); activeSessions > 1) {
        QMessageBox message;
        message.setIcon(QMessageBox::Question);
        message.setText(tr("Multiple running sessions detected."));
        message.setInformativeText(tr("There are %1 other desktop sessions open. The GPU switch will not become"
                                      " effective until you have manually logged out from ALL desktop sessions.\n"
                                      "Continue?")
                                       .arg(activeSessions - 1));
        message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (message.exec() == QMessageBox::No)
            return;
    }

    // Check if Wayland sessions are running
    for (const Session &session : sessions) {
        const QDBusInterface sessionInterface(QStringLiteral("org.freedesktop.login1"), session.sessionObjectPath.path(),
                                              QStringLiteral("org.freedesktop.login1.Session"), QDBusConnection::systemBus());
        if (sessionInterface.property("Type").toString() == QLatin1String("wayland")) {
            QMessageBox message;
            message.setIcon(QMessageBox::Question);
            message.setText(tr("Wayland session found."));
            message.setInformativeText(tr("Session %1, started by %2, is a Wayland session."
                                          " Wayland is not supported by Optimus Manager, so GPU switching may fail.\n"
                                          "Continue anyway?")
                                           .arg(QString::number(session.userId), session.userName));
            message.setStandardButtons(QMessageBox::Yes | QMessageBox::YesToAll | QMessageBox::No);
            message.exec();
            if (message.result() == QMessageBox::No)
                return;
            if (message.result() == QMessageBox::YesToAll)
                break;
        }
    }

    // Check if Bumblebee service is active
    if (const QString bumblebeed = QStringLiteral("bumblebeed.service"); isServiceActive(bumblebeed)) {
        QMessageBox message;
        message.setIcon(QMessageBox::Question);
        message.setText(tr("The %1 is running.").arg(bumblebeed));
        message.setInformativeText(tr("This can interfere with Optimus Manager. Before attempting a GPU switch, it is recommended that you disable"
                                      " this service with '%1' and reboot your computer.\n"
                                      "Ignore this warning and proceed with GPU switching now?")
                                       .arg(QStringLiteral("sudo systemctl disable bumblebeed.service")));
        message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (message.exec() == QMessageBox::No)
            return;
    }

    // Check if the default xorg config is exists
    if (const QString xorgConfig QStringLiteral("/etc/X11/xorg.conf"); QFileInfo::exists(xorgConfig)) {
        QMessageBox message;
        message.setIcon(QMessageBox::Question);
        message.setText(tr("Found a Xorg config file at '%1'.").arg(xorgConfig));
        message.setInformativeText(tr("If you did not create it yourself, it was likely generated by your distribution or by an Nvidia utility.\n"
                                      "This file may contain hard-coded GPU configuration that could interfere with Optimus Manager,"
                                      " so it is recommended that you delete it before proceeding.\n"
                                      "Ignore this warning and proceed with GPU switching?"));
        message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (message.exec() == QMessageBox::No)
            return;
    }

    // Check if the Manjaro MHWD config is exists
    if (const QString mhwdConfig = QStringLiteral("/etc/X11/xorg.conf.d/90-mhwd.conf"); QFileInfo::exists(mhwdConfig)) {
        QMessageBox message;
        message.setIcon(QMessageBox::Question);
        message.setText(tr("Found a Xorg config file at '%1'.").arg(mhwdConfig));
        message.setInformativeText(tr("This file was auto-generated by the Manjaro driver utility (MHWD). This will likely interfere with GPU switching,"
                                      " so Optimus Manager will delete this file automatically if you proceded with GPU switching.\n"
                                      "Proceed?"));
        message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (message.exec() == QMessageBox::No)
            return;
    }

    // Check if the Xorg driver is installed
    if (switchingMode == OptimusSettings::Integrated
        && optimusSettings.intelDriver() == OptimusSettings::Intel && !QFileInfo::exists(QStringLiteral("/usr/lib/xorg/modules/drivers/intel_drv.so"))
        && optimusSettings.amdDriver() == OptimusSettings::Amd && !QFileInfo::exists(QStringLiteral("/usr/lib/xorg/modules/drivers/amdgpu_drv.so"))) {
        QMessageBox message;
        message.setIcon(QMessageBox::Question);
        message.setText(tr("The Xorg driver is not installed."));
        message.setInformativeText(tr("Optimus Manager will use '%1' driver instead. You can change '%2' driver to '%1' in settings or"
                                      " install '%2' driver from the '%3' package.\n"
                                      "Continue anyway?")
                                       .arg("modesetting", "Intel/AMD", "xf86-video-intel/xf86-video-amdgpu"));
        message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (message.exec() == QMessageBox::No)
            return;
    }

    // Connect to Optimus Manager daemon
    DaemonClient client;
    client.connect();
    if (client.error()) {
        QMessageBox message;
        message.setIcon(QMessageBox::Critical);
        message.setText(DaemonClient::tr("Unable to connect to Optimus Manager daemon: %1").arg(client.errorString()));
        message.exec();
        return;
    }

    // Send GPU string to Optimus Manager daemon
    client.setGpu(switchingMode);
    if (client.error()) {
        QMessageBox message;
        message.setIcon(QMessageBox::Critical);
        message.setText(DaemonClient::tr("Unable to send GPU name to switch to Optimus Manager daemon: %1").arg(client.errorString()));
        message.exec();
        return;
    }

    if (optimusSettings.isAutoLogoutEnabled())
        logout();
    else
        showNotification(tr("Configuration successfully applied"), tr("Your GPU will be switched after next login."));
}

OptimusSettings::Mode OptimusManager::detectGpu()
{
    QFile stateFile(QStringLiteral("/var/lib/optimus-manager/tmp/state.json"));
    if (!stateFile.open(QIODevice::ReadOnly))
        qFatal("Unable to open Optimus Manager state file");

    QJsonParseError jsonError = {};
    const QJsonDocument jsonDocument = QJsonDocument::fromJson(stateFile.readAll(), &jsonError);
    if (jsonError.error != QJsonParseError::NoError)
        qFatal("Unable to parse Optimus Manager state file: %s", qPrintable(jsonError.errorString()));

    QJsonValue modeValue = jsonDocument.object().value("current_mode");
    if (modeValue.type() != QJsonValue::String)
        qFatal("Unable to read current mode from Optimus Manager state file");

    const QString currentMode = modeValue.toString();
    if (currentMode == QLatin1String("integrated"))
        return OptimusSettings::Integrated;
    if (currentMode == QLatin1String("nvidia"))
        return OptimusSettings::Nvidia;
    if (currentMode == QLatin1String("hybrid"))
        return OptimusSettings::Hybrid;

    qFatal("Unknown GPU mode: %s", qPrintable(currentMode));
}

bool OptimusManager::isModuleAvailable(const QString &moduleName)
{
    QFile modulesFile(QStringLiteral("/lib/modules/%1/modules.dep").arg(QSysInfo::kernelVersion()));
    if (!modulesFile.open(QIODevice::ReadOnly))
        return false;

    while (!modulesFile.atEnd()) {
        const QByteArray moduleInfo = modulesFile.readLine().trimmed();
        if (moduleInfo.startsWith('#')) // Ignore comment lines
            continue;

        if (QFileInfo(moduleInfo.left(moduleInfo.indexOf(':'))).baseName() == moduleName)
            return true;
    }

    return false;
}

bool OptimusManager::isServiceActive(const QString &serviceName)
{
    QDBusInterface systemd(QStringLiteral("org.freedesktop.systemd1"), QStringLiteral("/org/freedesktop/systemd1"),
                           QStringLiteral("org.freedesktop.systemd1.Manager"), QDBusConnection::systemBus());

    const auto optimusManagerPath = systemd.call(QStringLiteral("GetUnit"), serviceName).arguments().at(0).value<QDBusObjectPath>();
    if (optimusManagerPath.path().isEmpty())
        return false;

    const QDBusInterface optimusManager(QStringLiteral("org.freedesktop.systemd1"), optimusManagerPath.path(),
                                        QStringLiteral("org.freedesktop.systemd1.Unit"), QDBusConnection::systemBus());
    return optimusManager.property("SubState").toString() == QLatin1String("running");
}

bool OptimusManager::isGdmPatched()
{
    return QFileInfo::exists(QStringLiteral("/etc/gdm/Prime")) || QFileInfo::exists(QStringLiteral("/etc/gdm3/Prime"));
}

QString OptimusManager::currentDisplayManager()
{
    const QSettings displayManager(QStringLiteral("/etc/systemd/system/display-manager.service"), QSettings::IniFormat);
    return displayManager.value(QStringLiteral("Service/ExecStart")).toString();
}

QVector<Session> OptimusManager::activeSessions()
{
    // Get list of sessions
    QDBusInterface logind(QStringLiteral("org.freedesktop.login1"), QStringLiteral("/org/freedesktop/login1"),
                          QStringLiteral("org.freedesktop.login1.Manager"), QDBusConnection::systemBus());
    const auto sessionList = logind.call(QStringLiteral("ListSessions")).arguments().at(0).value<QDBusArgument>();

    // Demarshall data
    QVector<Session> activeSessions;
    sessionList.beginArray();
    while (!sessionList.atEnd()) {
        Session session;
        sessionList.beginStructure();
        sessionList >> session.sessionId >> session.userId >> session.userName >> session.seatId >> session.sessionObjectPath;
        sessionList.endStructure();
        activeSessions << qMove(session);
    }
    sessionList.endArray();

    return activeSessions;
}

// Return number of sessions, ignore gdm user
int OptimusManager::sessionsCountWithoutGdm(const QVector<Session> &sessions)
{
    int sessionCount = 0;
    for (const Session &session : sessions) {
        if (session.userName == QLatin1String("gdm"))
            continue;

        ++sessionCount;
    }

    return sessionCount;
}

void OptimusManager::logout()
{
    QDBusInterface kde(QStringLiteral("org.kde.ksmserver"), QStringLiteral("/KSMServer"), QStringLiteral("org.kde.KSMServerInterface"));
    if (kde.call(QStringLiteral("logout"), 0, 3, 3).type() == QDBusMessage::ReplyMessage)
        return;

    QDBusInterface gnome(QStringLiteral("org.gnome.SessionManager"), QStringLiteral("/org/gnome/SessionManager"), QStringLiteral("org.gnome.SessionManager"));
    if (gnome.call(QStringLiteral("Logout"), 1U).type() == QDBusMessage::ReplyMessage)
        return;

    QDBusInterface xfce(QStringLiteral("org.xfce.SessionManager"), QStringLiteral("/org/xfce/SessionManager"), QStringLiteral("org.xfce.Session.Manager"));
    if (xfce.call(QStringLiteral("Logout"), false, true).type() == QDBusMessage::ReplyMessage)
        return;

    QDBusInterface deepin(QStringLiteral("com.deepin.SessionManager"), QStringLiteral("/com/deepin/SessionManager"), QStringLiteral("com.deepin.SessionManager"));
    if (deepin.call(QStringLiteral("RequestLogout")).type() == QDBusMessage::ReplyMessage)
        return;

    if (QProcess::execute(QStringLiteral("i3-msg"), {QStringLiteral("exit")}) == 0)
        return;

    if (QProcess::execute(QStringLiteral("sway-msg"), {QStringLiteral("exit")}) == 0)
        return;

    if (QProcess::execute(QStringLiteral("openbox"), {QStringLiteral("--exit")}) == 0)
        return;

    if (QProcess::execute(QStringLiteral("awesome-client"), {QStringLiteral("awesome.quit()")}) == 0)
        return;

    if (QProcess::execute(QStringLiteral("bspc"), {QStringLiteral("quit")}) == 0)
        return;

    killProcess("/usr/bin/lxsession");
    killProcess("/usr/bin/dwm");
    killProcess("/usr/local/bin/dwm");
    killProcess("/usr/bin/qtile-cmd -o cmd -f shutdown");
}

bool OptimusManager::killProcess(const QByteArray &name)
{
    for (QDirIterator it(QStringLiteral("/proc"), QDir::NoDotAndDotDot | QDir::Dirs); it.hasNext();) {
        const QDir process = it.next();

        bool isNumber;
        pid_t pid = process.dirName().toInt(&isNumber);
        if (!isNumber)
            continue;

        QFile processName(process.filePath(QStringLiteral("cmdline")));
        processName.open(QIODevice::ReadOnly);
        const QByteArray processPath = processName.readLine();
        if (!processPath.isEmpty() && processPath.chopped(1) == name) {
            kill(pid, SIGTERM);
            return true;
        }
    }

    return false;
}
