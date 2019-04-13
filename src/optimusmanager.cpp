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

    // Show a message that the application is already running
    connect(qobject_cast<SingleApplication*>(SingleApplication::instance()), &SingleApplication::instanceStarted, this, &OptimusManager::showAppRunningMessage);

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

void OptimusManager::showAppRunningMessage()
{
    auto message = new QMessageBox(QMessageBox::Information, "Optimus Manager", tr("The application is already running"));
    message->setAttribute(Qt::WA_DeleteOnClose); // Need to allocate on heap to avoid crash!
    message->show();
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

void OptimusManager::switchGpu(OptimusManager::GPU gpu)
{
    const OptimusSettings settings;

    // Confirm message
    QMessageBox confirmMessage;
    confirmMessage.setStandardButtons(QMessageBox::Apply | QMessageBox::Cancel);
    confirmMessage.setIcon(QMessageBox::Question);
    if (settings.isLoginManagerControl())
        confirmMessage.setText(tr("You are about to switch GPUs. This will restart the display manager and all your applications will be closed."));
    else
        confirmMessage.setText(tr("You are about to switch GPUs. After applying the settings, you will need to manually restart the login manager to change the video card."));
    confirmMessage.exec();
    if (confirmMessage.result() != QMessageBox::Apply)
        return;

    // Check if daemon is acrive
    DaemonClient client;
    if (!client.isDaemonActive()) {
        QMessageBox daemonMessage;
        daemonMessage.setIcon(QMessageBox::Critical);
        daemonMessage.setText(tr("The optimus-manager service is not running. Please enable and start it with:") +
                              "\nsudo systemctl enable optimus-manager"
                              "\nsudo systemctl start optimus-manager");
        daemonMessage.exec();
        return;
    }

    // Check configuration
    switch (settings.switchingBackend()) {
    case OptimusSettings::Bbswitch:
        if (!isModuleAvailable("bbswitch")) {
            QMessageBox moduleMessage;
            moduleMessage.setIcon(QMessageBox::Critical);
            moduleMessage.setText(tr("bbswitch is enabled in the configuration file but the bbswitch module does"
                                  " not seem to be available for the current kernel. Power switching will not work.\n"
                                  "You can install bbswitch for the default kernel with \"sudo pacman -S bbswitch\" or"
                                  " for all kernels with \"sudo pacman -S bbswitch-dkms\"."));
            moduleMessage.exec();
            return;
        }
        break;
    case OptimusSettings::Nouveau:
        if (!isModuleAvailable("nouveau")) {
            QMessageBox moduleMessage;
            moduleMessage.setIcon(QMessageBox::Question);
            moduleMessage.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            moduleMessage.setText(tr("The nvidia module does not seem to be available for the current kernel."
                                     " It is likely the Nvidia driver was not properly installed. GPU switching will probably fail,"
                                     " continue anyway?"));
            moduleMessage.exec();
            if (moduleMessage.result() != QMessageBox::Yes)
                return;
        }
        break;
    default:
        break;
    }

    // Connect to optimus-manager daemon
    client.connect();
    if (client.error()) {
        QMessageBox connectMessage;
        connectMessage.setIcon(QMessageBox::Critical);
        connectMessage.setText(tr("Unable to connect to optimus-manager daemon to switch GPU: ") + client.errorString());
        connectMessage.exec();
        return;
    }

    // Send GPU string to optimus-manager daemon
    QString gpuString;
    switch (gpu) {
    case Intel:
        gpuString = "intel";
        break;
    case Nvidia:
        gpuString = "nvidia";
        break;
    }

    if (client.send(gpuString) == -1) {
        QMessageBox sendMessage;
        sendMessage.setIcon(QMessageBox::Critical);
        sendMessage.setText(tr("Unable to send GPU to switch to optimus-manager daemon: ") + client.errorString());
        sendMessage.exec();
    }

    if (!settings.isLoginManagerControl()) {
        const AppSettings appSettings;
        showNotification(tr("Configuration successfully applied. Your GPU will be switched after the login manager is restarted."), appSettings.gpuIconName(gpu));
    }
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
