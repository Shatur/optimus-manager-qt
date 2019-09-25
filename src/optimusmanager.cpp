/*
 *  Copyright © 2019 Hennadii Chernyshchyk <genaloner@gmail.com>
 *
 *  This file is part of Optimus Manager Qt.
 *
 *  Optimus Manager Qt is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a get of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "optimusmanager.h"
#include "appsettings.h"
#include "settingsdialog.h"
#include "singleapplication.h"
#include "optimussettings.h"
#include "daemonclient.h"
#include "x11deleters.h"

#include <QtX11Extras/QX11Info>
#include <QProcess>
#include <QFileInfo>
#include <QMenu>
#include <QMessageBox>
#include <QMetaEnum>
#include <QDBusArgument>
#include <QDBusInterface>
#ifdef PLASMA
#include <KStatusNotifierItem>
#else
#include <QSystemTrayIcon>
#endif

OptimusManager::OptimusManager(QObject *parent) :
    QObject(parent)
{
    // Detect current GPU
    m_currentGpu = detectGpu();

    // Setup context menu
    m_contextMenu = new QMenu;
    m_contextMenu->addAction(QIcon::fromTheme("preferences-system"), SettingsDialog::tr("Settings"), this, &OptimusManager::openSettings);
    m_contextMenu->addSeparator();

    const QMetaEnum gpuEnum = QMetaEnum::fromType<DaemonClient::GPU>();
    m_contextMenu->addAction(tr("Switch to %1").arg(gpuEnum.key(DaemonClient::Intel)), this, &OptimusManager::switchToIntel);
    m_contextMenu->addAction(tr("Switch to %1").arg(gpuEnum.key(DaemonClient::Nvidia)), this, &OptimusManager::switchToNvidia);
    m_contextMenu->addAction(tr("Switch to %1").arg(gpuEnum.key(DaemonClient::Hybrid)), this, &OptimusManager::switchToHybrid);
    m_contextMenu->addSeparator();

    m_contextMenu->addAction(QIcon::fromTheme("application-exit"), tr("Exit"), SingleApplication::instance(), &SingleApplication::quit);

    // Setup tray
#ifdef PLASMA
    m_trayIcon = new KStatusNotifierItem(this);
    m_trayIcon->setStandardActionsEnabled(false);
    m_trayIcon->setToolTipTitle(SingleApplication::applicationName());
    m_trayIcon->setCategory(KStatusNotifierItem::SystemServices);
    m_trayIcon->setToolTipSubTitle(tr("Current videocard: %1").arg(QMetaEnum::fromType<DaemonClient::GPU>().valueToKey(m_currentGpu)));
#else
    m_trayIcon = new QSystemTrayIcon(this);
#endif
    m_trayIcon->setContextMenu(m_contextMenu);

    loadSettings();

#ifndef PLASMA
    m_trayIcon->show();
#endif
}

OptimusManager::~OptimusManager()
{
#ifndef PLASMA
    delete m_contextMenu;
#endif
}

QIcon OptimusManager::trayGpuIcon(const QString &iconName)
{
    if (QIcon::hasThemeIcon(iconName))
        return QIcon::fromTheme(iconName);

    if (QFileInfo::exists(iconName))
        return QIcon(iconName);

    return QIcon();
}

void OptimusManager::switchToIntel()
{
    switchGpu(DaemonClient::Intel);
}

void OptimusManager::switchToNvidia()
{
    switchGpu(DaemonClient::Nvidia);
}

void OptimusManager::switchToHybrid()
{
    switchGpu(DaemonClient::Hybrid);
}

void OptimusManager::openSettings()
{
    SettingsDialog dialog;
    if (!dialog.exec())
        return;

    if (dialog.languageChanged())
        retranslateUi();

    loadSettings();
}

void OptimusManager::showNotification(const QString &message, const QString &iconName, int interval)
{
#ifdef PLASMA
    m_trayIcon->showMessage(SingleApplication::applicationName(), message, iconName, interval);
#else
    QDBusInterface notify("org.freedesktop.Notifications", "/org/freedesktop/Notifications", "org.freedesktop.Notifications");
    QVariantList notifyArguments;
    notifyArguments << SingleApplication::applicationName(); // Set program name
    notifyArguments << QVariant(QVariant::UInt);
    notifyArguments << iconName; // Icon
    notifyArguments << SingleApplication::applicationName(); // Title
    notifyArguments << message; // Body
    notifyArguments << QStringList();
    notifyArguments << QVariantMap();
    notifyArguments << interval; // Show interval
    notify.callWithArgumentList(QDBus::AutoDetect, "Notify", notifyArguments);
#endif
}

void OptimusManager::loadSettings()
{
    AppSettings appSettings;

    // Context menu icons
    m_contextMenu->actions().at(2)->setIcon(trayGpuIcon(appSettings.gpuIconName(DaemonClient::Intel)));
    m_contextMenu->actions().at(3)->setIcon(trayGpuIcon(appSettings.gpuIconName(DaemonClient::Nvidia)));
    m_contextMenu->actions().at(4)->setIcon(trayGpuIcon(appSettings.gpuIconName(DaemonClient::Hybrid)));

    // Tray icon
    QString gpuIconName = appSettings.gpuIconName(m_currentGpu);
#ifdef PLASMA
    if (!QIcon::hasThemeIcon(gpuIconName) && !QFileInfo::exists(gpuIconName)) {
        gpuIconName = AppSettings::defaultTrayIconName(m_currentGpu);
        appSettings.setGpuIconName(m_currentGpu, gpuIconName);
        showNotification(tr("The specified icon '%1' for the current GPU is invalid. The default icon will be used.").arg(gpuIconName), gpuIconName);
    }
    m_trayIcon->setIconByName(gpuIconName);
    m_trayIcon->setToolTipIconByName(m_trayIcon->iconName());
#else
    QIcon trayIcon = trayGpuIcon(gpuIconName);
    if (trayIcon.isNull()) {
        const QString defaultIconName = AppSettings::defaultTrayIconName(m_currentGpu);
        appSettings.setGpuIconName(m_currentGpu, defaultIconName);
        trayIcon = QIcon::fromTheme(defaultIconName);
        showNotification(tr("The specified icon '%1' for the current GPU is invalid. The default icon will be used.").arg(gpuIconName), defaultIconName);
    }
    m_trayIcon->setIcon(trayIcon);
#endif
}

void OptimusManager::retranslateUi()
{
#ifdef PLASMA
    m_trayIcon->setToolTipSubTitle(tr("Current videocard: %1").arg(QMetaEnum::fromType<DaemonClient::GPU>().valueToKey(m_currentGpu)));
#endif
    m_contextMenu->actions().at(0)->setText(SettingsDialog::tr("Settings"));
    m_contextMenu->actions().at(2)->setText(tr("Switch to Intel"));
    m_contextMenu->actions().at(3)->setText(tr("Switch to Nvidia"));
    m_contextMenu->actions().at(5)->setText(tr("Exit"));
}

void OptimusManager::switchGpu(DaemonClient::GPU switchingGpu)
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

    // Check if power switching enabled
    if (optimusSettings.switchingMethod() == OptimusSettings::NoneMethod && !optimusSettings.isPciPowerControlEnabled()) {
        QMessageBox message;
        message.setIcon(QMessageBox::Warning);
        message.setText(tr("No power management option is currently enabled"));
        message.setInformativeText(tr("Switching between GPUs will work but you will likely experience poor battery life."));
        message.exec();
    }

    // Check if daemon is active
    if (!isServiceActive(QStringLiteral("optimus-manager.service"))) {
        QMessageBox message;
        message.setIcon(QMessageBox::Critical);
        message.setText(tr("The Optimus Manager service is not running."));
        message.setInformativeText(tr("Please enable and start it with:\n'%1'\n'%2'")
                                   .arg("sudo systemctl enable optimus-manager", "sudo systemctl start optimus-manager"));
        message.exec();
        return;
    }

    // Check if bbswitch module is available
    if (optimusSettings.switchingMethod() == OptimusSettings::Bbswitch && !isModuleAvailable("bbswitch")) {
        QMessageBox message;
        message.setIcon(QMessageBox::Warning);
        message.setText(tr("The %1 module does not seem to be available for the current kernel.").arg("bbswitch"));
        message.setInformativeText(tr("Power switching will not work.\n"
                                      "You can set '%1' for GPU switching in settings or install bbswitch for"
                                      "the default kernel with '%2' or for all kernels with '%3'.")
                                   .arg("nouveau", "sudo pacman -S bbswitch", "sudo pacman -S bbswitch-dkms"));
        message.exec();
    }

    // Check if nvidia module is available
    if (switchingGpu == DaemonClient::Nvidia && !isModuleAvailable("nvidia")) {
        QMessageBox message;
        message.setIcon(QMessageBox::Question);
        message.setText(tr("The %1 module does not seem to be available for the current kernel.").arg("nvidia"));
        message.setInformativeText(tr("It is likely the Nvidia driver was not properly installed. GPU switching will probably fail, continue anyway?"));
        message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (message.exec() == QMessageBox::No)
            return;
    }

    // Check if GDM is patched
    if (currentDisplayManager() == "/usr/bin/gdm" && !isGdmPatched()) {
        QMessageBox message;
        message.setIcon(QMessageBox::Question);
        message.setText(tr("Looks like you're using a non-patched version of the Gnome Display Manager (GDM)."));
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
                                      "Continue?").arg(activeSessions - 1));
        message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (message.exec() == QMessageBox::No)
            return;
    }

    // Check if Wayland sessions are running
    for (const Session &session : sessions) {
        const QDBusInterface sessionInterface("org.freedesktop.login1", session.sessionObjectPath.path(), "org.freedesktop.login1.Session", QDBusConnection::systemBus());
        if (sessionInterface.property("Type").toString() == "wayland") {
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
    if (isServiceActive(QStringLiteral("bumblebeed.service"))) {
        QMessageBox message;
        message.setIcon(QMessageBox::Question);
        message.setText(tr("The Bumblebee service (%1) is running.").arg("bumblebeed.service"));
        message.setInformativeText(tr("This can interfere with Optimus Manager. Before attempting a GPU switch, it is recommended that you disable"
                                      " this service with '%1' and reboot your computer.\n"
                                      "Ignore this warning and proceed with GPU switching now?")
                                   .arg("sudo systemctl disable bumblebeed.service"));
        message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (message.exec() == QMessageBox::No)
            return;
    }

    // Check if the default xorg config is exists
    if (QFileInfo::exists("/etc/X11/xorg.conf")) {
        QMessageBox message;
        message.setIcon(QMessageBox::Question);
        message.setText(tr("Found a Xorg config file at '%1'.").arg("/etc/X11/xorg.conf"));
        message.setInformativeText(tr("If you did not create it yourself, it was likely generated by your distribution or by an Nvidia utility.\n"
                                      "This file may contain hard-coded GPU configuration that could interfere with Optimus Manager,"
                                      " so it is recommended that you delete it before proceeding.\n"
                                      "Ignore this warning and proceed with GPU switching?"));
        message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (message.exec() == QMessageBox::No)
            return;
    }

    // Check if the Manjaro MHWD config is exists
    if (QFileInfo::exists("/etc/X11/xorg.conf.d/90-mhwd.conf")) {
        QMessageBox message;
        message.setIcon(QMessageBox::Question);
        message.setText(tr("Found a Xorg config file at '%1'.").arg("/etc/X11/xorg.conf.d/90-mhwd.conf"));
        message.setInformativeText(tr("This file was auto-generated by the Manjaro driver utility (MHWD). This will likely interfere with GPU switching,"
                                      " so Optimus Manager will delete this file automatically if you proceded with GPU switching.\n"
                                      "Proceed?"));
        message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (message.exec() == QMessageBox::No)
            return;
    }

    // Check if the Xorg driver 'intel' is installed
    if (switchingGpu == DaemonClient::Intel
            && optimusSettings.intelDriver() == OptimusSettings::IntelDriver
            && !QFileInfo::exists("/usr/lib/xorg/modules/drivers/intel_drv.so")) {
        QMessageBox message;
        message.setIcon(QMessageBox::Question);
        message.setText(tr("The Xorg driver '%1' is not installed.").arg("intel"));
        message.setInformativeText(tr("Optimus Manager will use '%1' driver instead. You can change driver in settings or install the"
                                      " '%2' driver from the package '%3'.\n"
                                      "Continue anyway?")
                                   .arg("modesetting", "intel", "xf86-video-intel"));
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
        message.setText(tr("Unable to connect to Optimus Manager daemon to switch GPU: %1").arg(client.errorString()));
        message.exec();
        return;
    }

    // Send GPU string to Optimus Manager daemon
    if (!client.setGpu(switchingGpu)) {
        QMessageBox message;
        message.setIcon(QMessageBox::Critical);
        message.setText(tr("Unable to send GPU name to switch to Optimus Manager daemon: %1").arg(client.errorString()));
        message.exec();
    }

    if (optimusSettings.isAutoLogoutEnabled())
        logout();
    else
        showNotification(tr("Configuration successfully applied. Your GPU will be switched after next login."), appSettings.gpuIconName(switchingGpu));
}

DaemonClient::GPU OptimusManager::detectGpu()
{
    const unsigned long root = RootWindow(QX11Info::display(), QX11Info::appScreen());

    QScopedPointer<XRRScreenResources, ScreenResourcesDeleter> screenResources(XRRGetScreenResourcesCurrent(QX11Info::display(), root));
    if (screenResources.isNull())
        qFatal("Unable to get screen resources");

    QScopedPointer<XRRProviderResources, ProviderResourcesDeleter> providerResources(XRRGetProviderResources(QX11Info::display(), root));
    if (providerResources.isNull())
        qFatal("Unable to get provider resources");

    QScopedPointer<XRRProviderInfo, ProviderInfoDeleter> providerInfo(XRRGetProviderInfo(QX11Info::display(), screenResources.data(), providerResources->providers[0]));
    if (qstrcmp(providerInfo->name, "NVIDIA-0") == 0)
        return DaemonClient::Nvidia;

    if (qstrcmp(providerInfo->name, "modesetting") == 0 || qstrcmp(providerInfo->name, "Intel") == 0) {
        if (providerResources->nproviders == 1)
            return DaemonClient::Intel;

        for (int i = 1; i < providerResources->nproviders; ++i) {
            providerInfo.reset(XRRGetProviderInfo(QX11Info::display(), screenResources.data(), providerResources->providers[i]));
            if (qstrcmp(providerInfo->name, "NVIDIA-G0") == 0)
                return DaemonClient::Hybrid;
        }
    }

    qFatal("Unable to detect GPU");
}

bool OptimusManager::isModuleAvailable(const QString &moduleName)
{
    QProcess process;
    process.setProgram("modinfo");
    process.setArguments({moduleName});
    process.start();
    process.waitForFinished();

    return process.exitCode() == 0;
}

bool OptimusManager::isServiceActive(const QString &serviceName)
{
    QDBusInterface systemd("org.freedesktop.systemd1", "/org/freedesktop/systemd1", "org.freedesktop.systemd1.Manager", QDBusConnection::systemBus());

    const auto optimusManagerPath = systemd.call("GetUnit", serviceName).arguments().at(0).value<QDBusObjectPath>();
    if (optimusManagerPath.path().isEmpty())
        return false;

    const QDBusInterface optimusManager("org.freedesktop.systemd1", optimusManagerPath.path(), "org.freedesktop.systemd1.Unit", QDBusConnection::systemBus());
    return optimusManager.property("SubState").toString() == "running";
}

bool OptimusManager::isGdmPatched()
{
    return QFileInfo::exists("/etc/gdm/Prime") || QFileInfo::exists("/etc/gdm3/Prime");
}

QString OptimusManager::currentDisplayManager()
{
    const QSettings displayManager("/etc/systemd/system/display-manager.service", QSettings::IniFormat);
    return displayManager.value("Service/ExecStart").toString();
}

QVector<OptimusManager::Session> OptimusManager::activeSessions()
{
    // Get list of sessions
    QDBusInterface logind("org.freedesktop.login1", "/org/freedesktop/login1", "org.freedesktop.login1.Manager", QDBusConnection::systemBus());
    const auto sessionList = logind.call("ListSessions").arguments().at(0).value<QDBusArgument>();

    // Demarshall data
    QVector<Session> activeSessions;
    sessionList.beginArray();
    while (!sessionList.atEnd()) {
        Session session;
        sessionList.beginStructure();
        sessionList >> session.sessionId >> session.userId >> session.userName >> session.seatId >> session.sessionObjectPath;
        sessionList.endStructure();
        activeSessions << session;
    }
    sessionList.endArray();

    return activeSessions;
}

// Return number of sessions, ignore gdm user
int OptimusManager::sessionsCountWithoutGdm(const QVector<OptimusManager::Session> &sessions)
{
    int sessionCount = 0;
    for (const Session &session : sessions) {
        if (session.userName == "gdm")
            continue;

        ++sessionCount;
    }

    return sessionCount;
}

void OptimusManager::logout()
{
    QDBusInterface kde("org.kde.ksmserver", "/KSMServer", "org.kde.KSMServerInterface");
    kde.call("logout", 0, 3, 3);

    QDBusInterface gnome("org.gnome.SessionManager", "/org/gnome/SessionManager", "org.gnome.SessionManager");
    gnome.call("Logout", 1U);

    QDBusInterface xfce("org.xfce.SessionManager", "/org/xfce/SessionManager", "org.xfce.Session.Manager");
    xfce.call("Logout", false, true);

    QDBusInterface deepin("com.deepin.SessionManager", "/com/deepin/SessionManager", "com.deepin.SessionManager");
    deepin.call("RequestLogout");

    QProcess::execute("i3-msg", {"exit"});

    QProcess::execute("sway-msg", {"exit"});

    QProcess::execute("openbox", {"--exit"});

    QProcess::execute("awesome-client", {"\"awesome.quit()\""});

    QProcess::execute("bspc", {"quit"});
}
