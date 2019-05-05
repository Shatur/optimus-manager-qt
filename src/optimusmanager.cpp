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
#include "optimussettings.h"
#include "settingsdialog.h"
#include "singleapplication.h"
#include "daemonclient.h"

#include <QProcess>
#include <QFileInfo>
#include <QDebug>
#include <QMenu>
#include <QMessageBox>
#include <QMetaEnum>
#ifdef PLASMA
#include <KStatusNotifierItem>
#else
#include <QSystemTrayIcon>
#include <QDBusInterface>
#endif

OptimusManager::OptimusManager(QObject *parent) :
    QObject(parent)
{
    detectGpu(); // Detect current GPU

    // Setup context menu
    m_contextMenu = new QMenu;
    m_contextMenu->addAction(QIcon::fromTheme("preferences-system"), SettingsDialog::tr("Settings"), this, &OptimusManager::openSettings);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(tr("Switch to Intel"), this, &OptimusManager::switchToIntel);
    m_contextMenu->addAction(tr("Switch to Nvidia"), this, &OptimusManager::switchToNvidia);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(QIcon::fromTheme("application-exit"), tr("Exit"), SingleApplication::instance(), &SingleApplication::quit);

    // Setup tray
#ifdef PLASMA
    m_trayIcon = new KStatusNotifierItem(this);
    m_trayIcon->setStandardActionsEnabled(false);
    m_trayIcon->setToolTipTitle(SingleApplication::applicationName());
    m_trayIcon->setCategory(KStatusNotifierItem::SystemServices);
    m_trayIcon->setToolTipSubTitle(tr("Current videocard: ") + QMetaEnum::fromType<GPU>().valueToKey(m_currentGpu));
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
    switchGpu(Intel);
}

void OptimusManager::switchToNvidia()
{
    switchGpu(Nvidia);
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

void OptimusManager::detectGpu()
{
    if (!QFileInfo::exists("/usr/bin/glxinfo"))
        qFatal("Unable to find glxinfo, try to install extra/mesa-demos package");

    QProcess process;
    process.setProgram("bash");
    process.setArguments({"-c", "glxinfo | grep NVIDIA"});
    process.start();
    process.waitForFinished();

    switch (process.exitCode()) {
    case 0:
        m_currentGpu = Nvidia;
        break;
    case 1:
        m_currentGpu = Intel;
        break;
    default:
        qFatal("Unable to detect GPU");
    }
}

void OptimusManager::loadSettings()
{
    AppSettings settings;

    // Context menu icons
    m_contextMenu->actions().at(2)->setIcon(trayGpuIcon(settings.gpuIconName(Intel)));
    m_contextMenu->actions().at(3)->setIcon(trayGpuIcon(settings.gpuIconName(Nvidia)));

    // Tray icon
    QString gpuIconName = settings.gpuIconName(m_currentGpu);
#ifdef PLASMA
    if (!QIcon::hasThemeIcon(gpuIconName) && !QFileInfo::exists(gpuIconName)) {
        gpuIconName = AppSettings::defaultTrayIconName(m_currentGpu);
        settings.setGpuIconName(m_currentGpu, gpuIconName);
        showNotification(tr("The specified icon '%1' for the current GPU is invalid. The default icon will be used.").arg(gpuIconName), gpuIconName);
    }
    m_trayIcon->setIconByName(gpuIconName);
    m_trayIcon->setToolTipIconByName(m_trayIcon->iconName());
#else
    QIcon trayIcon = trayGpuIcon(gpuIconName);
    if (trayIcon.isNull()) {
        const QString defaultIconName = AppSettings::defaultTrayIconName(m_currentGpu);
        settings.setGpuIconName(m_currentGpu, defaultIconName);
        trayIcon = QIcon::fromTheme(defaultIconName);
        showNotification(tr("The specified icon '%1' for the current GPU is invalid. The default icon will be used.").arg(gpuIconName), defaultIconName);
    }
    m_trayIcon->setIcon(trayIcon);
#endif
}

void OptimusManager::retranslateUi()
{
#ifdef PLASMA
    m_trayIcon->setToolTipSubTitle(tr("Current videocard: ") + QMetaEnum::fromType<GPU>().valueToKey(m_currentGpu));
#endif
    m_contextMenu->actions().at(0)->setText(SettingsDialog::tr("Settings"));
    m_contextMenu->actions().at(2)->setText(tr("Switch to Intel"));
    m_contextMenu->actions().at(3)->setText(tr("Switch to Nvidia"));
    m_contextMenu->actions().at(5)->setText(tr("Exit"));
}

void OptimusManager::switchGpu(OptimusManager::GPU switchingGpu)
{
    const AppSettings appSettings;
    const OptimusSettings settings;

    // Confirm message
    if (appSettings.isConfirmSwitching()) {
        QMessageBox message;
        message.setStandardButtons(QMessageBox::Apply | QMessageBox::Cancel);
        message.setIcon(QMessageBox::Question);
        message.setText(tr("You are about to switch GPU."));
        if (settings.isAutoLogoutEnabled())
            message.setInformativeText(tr("You will be automatically logged out to apply the changes."));
        else
            message.setInformativeText(tr("After applying the settings, you will need to manually re-login to change the video card."));
        if (message.exec() != QMessageBox::Apply)
            return;
    }

    // Check if daemon is active
    if (!isServiceActive(QStringLiteral("optimus-manager.service"))) {
        QMessageBox message;
        message.setIcon(QMessageBox::Critical);
        message.setText(tr("The Optimus Manager service is not running."));
        message.setInformativeText(tr("Please enable and start it with:\n'%1'\n'%2'")
                                   .arg("sudo systemctl enable optimus-manager")
                                   .arg("sudo systemctl start optimus-manager"));
        message.exec();
        return;
    }

    // Check if bbswitch module is available
    if (settings.switchingBackend() == OptimusSettings::Bbswitch && !isModuleAvailable("bbswitch")) {
        QMessageBox message;
        message.setIcon(QMessageBox::Warning);
        message.setText(tr("The %1 module does not seem to be available for the current kernel.").arg("bbswitch"));
        message.setInformativeText(tr("Power switching will not work.\n"
                                      "You can set '%1' for GPU switching in settings or install bbswitch for"
                                      "the default kernel with '%2' or for all kernels with '%3'.")
                                   .arg("nouveau")
                                   .arg("sudo pacman -S bbswitch")
                                   .arg("sudo pacman -S bbswitch-dkms"));
        message.exec();
    }

    // Check if nvidia module is available
    if (switchingGpu == OptimusManager::Nvidia && !isModuleAvailable("nvidia")) {
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

    // TODO: check if current session is wayland

    // Check if Bumblebee service is active
    if (isServiceActive(QLatin1String("bumblebeed.service"))) {
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
    if (switchingGpu == Intel && settings.intelDriver() == OptimusSettings::IntelDriver && !QFileInfo::exists("/usr/lib/xorg/modules/drivers/intel_drv.so")) {
        QMessageBox message;
        message.setIcon(QMessageBox::Question);
        message.setText(tr("The Xorg driver '%1' is not installed.").arg("intel"));
        message.setInformativeText(tr("Optimus Manager will use '%1' driver instead. You can change driver in settings or install the"
                                      " '%2' driver from the package '%3'.\n"
                                      "Continue anyway?")
                                   .arg("modesetting")
                                   .arg("intel")
                                   .arg("xf86-video-intel"));
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
    if (client.send(gpuString(switchingGpu)) == -1) {
        QMessageBox message;
        message.setIcon(QMessageBox::Critical);
        message.setText(tr("Unable to send GPU name to switch to Optimus Manager daemon: %1").arg(client.errorString()));
        message.exec();
    }

    if (!settings.isAutoLogoutEnabled())
        showNotification(tr("Configuration successfully applied. Your GPU will be switched after next login."), appSettings.gpuIconName(switchingGpu));
}

QString OptimusManager::gpuString(GPU gpu)
{
    QString gpuString;
    switch (gpu) {
    case Intel:
        gpuString = QStringLiteral("intel");
        break;
    case Nvidia:
        gpuString = QStringLiteral("nvidia");
        break;
    }

    return gpuString;
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
    QDBusConnection connection = QDBusConnection::systemBus();
    QDBusInterface systemd("org.freedesktop.systemd1", "/org/freedesktop/systemd1", "org.freedesktop.systemd1.Manager", connection);

    const QDBusObjectPath optimusManagerPath = systemd.call("GetUnit", serviceName).arguments().at(0).value<QDBusObjectPath>();
    if (optimusManagerPath.path().isEmpty())
        return false;

    const QDBusInterface optimusManager("org.freedesktop.systemd1", optimusManagerPath.path(), "org.freedesktop.systemd1.Unit", connection);
    return optimusManager.property("SubState").toString() == "running";
}

QString OptimusManager::currentDisplayManager()
{
    const QSettings settings("/etc/systemd/system/display-manager.service", QSettings::IniFormat);
    return settings.value("Service/ExecStart").toString();
}

bool OptimusManager::isGdmPatched()
{
    if (QFileInfo::exists("/etc/gdm/Prime") || QFileInfo::exists("/etc/gdm3/Prime"))
        return true;

    return false;
}
