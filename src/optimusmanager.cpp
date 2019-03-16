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

#include <QProcess>
#include <QFileInfo>
#include <QDebug>
#include <QMenu>
#include <QMessageBox>
#include <QMetaEnum>
#ifdef KDE
#include <KStatusNotifierItem>
#else
#include <QSystemTrayIcon>
#endif

OptimusManager::OptimusManager(QObject *parent) :
    QObject(parent)
{
    loadCurrentMode(); // Detect current GPU

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
#ifdef KDE
    m_trayIcon = new KStatusNotifierItem(this);
    m_trayIcon->setStandardActionsEnabled(false);
    m_trayIcon->setToolTipTitle(SingleApplication::applicationName());
    m_trayIcon->setCategory(KStatusNotifierItem::SystemServices);
    m_trayIcon->setToolTipSubTitle(tr("Current videocard: ") + QMetaEnum::fromType<Mode>().valueToKey(m_currentMode));
#else
    m_trayIcon = new QSystemTrayIcon(this);
#endif
    m_trayIcon->setContextMenu(m_contextMenu);

    loadSettings();

#ifndef KDE
    m_trayIcon->show();
#endif
}

OptimusManager::~OptimusManager()
{
#ifndef KDE
    delete m_contextMenu;
#endif
}

QIcon OptimusManager::contextMenuModeIcon(const QString &iconName)
{
    if (QIcon::hasThemeIcon(iconName))
        return QIcon::fromTheme(iconName);

    return QIcon(iconName);
}

QIcon OptimusManager::trayModeIcon(const QString &iconName)
{
    const QIcon icon = contextMenuModeIcon(iconName);
    if (icon.availableSizes().isEmpty())
        return QIcon::fromTheme(QStringLiteral("dialog-error"));

    return icon;
}

QString OptimusManager::trayModeIconName(const QString &iconName)
{
    if (QIcon::hasThemeIcon(iconName) || QFile::exists(iconName))
        return iconName;

    return QStringLiteral("dialog-error");
}

void OptimusManager::switchToIntel()
{
    switchMode(Intel);
}

void OptimusManager::switchToNvidia()
{
    switchMode(Nvidia);
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

void OptimusManager::loadCurrentMode()
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
        m_currentMode = Nvidia;
        break;
    case 1:
        m_currentMode = Intel;
        break;
    default:
        qFatal("Unable to detect mode");
    }
}

void OptimusManager::loadSettings()
{
    AppSettings settings;
    const QString modeIconName = settings.modeIconName(m_currentMode);

    // Context menu icons
    m_contextMenu->actions().at(2)->setIcon(contextMenuModeIcon(settings.modeIconName(Intel)));
    m_contextMenu->actions().at(3)->setIcon(contextMenuModeIcon(settings.modeIconName(Nvidia)));

    // Tray icon
#ifdef KDE
    m_trayIcon->setIconByName(trayModeIconName(modeIconName));
    m_trayIcon->setToolTipIconByName(m_trayIcon->iconName());
#else
    m_trayIcon->setIcon(trayModeIcon(modeIconName));
#endif
}

void OptimusManager::retranslateUi()
{
#ifdef KDE
    m_trayIcon->setToolTipSubTitle(tr("Current videocard: ") + QMetaEnum::fromType<Mode>().valueToKey(m_currentMode));
#endif
    m_contextMenu->actions().at(0)->setText(SettingsDialog::tr("Settings"));
    m_contextMenu->actions().at(2)->setText(tr("Switch to Intel"));
    m_contextMenu->actions().at(3)->setText(tr("Switch to Nvidia"));
    m_contextMenu->actions().at(5)->setText(tr("Exit"));
}

void OptimusManager::switchMode(OptimusManager::Mode mode)
{
    QMessageBox confirmMessage;
    confirmMessage.setStandardButtons(QMessageBox::Apply | QMessageBox::Cancel);
    confirmMessage.setIcon(QMessageBox::Question);

    const OptimusSettings settings;
    if (settings.isLoginManagerControl())
        confirmMessage.setText(tr("You are about to switch GPUs. This will restart the display manager and all your applications will be closed."));
    else
        confirmMessage.setText(tr("You are about to switch GPUs. After applying the settings, you will need to manually restart the login manager to change the video card."));

    confirmMessage.exec();
    if (confirmMessage.result() != QMessageBox::Apply)
        return;

    QProcess process;
    process.setProgram("optimus-manager");
    switch (mode) {
    case Intel:
        process.setArguments({"--switch", "intel", "--no-confirm"});
        break;
    case Nvidia:
        process.setArguments({"--switch", "nvidia", "--no-confirm"});
        break;
    }

    process.start();
    process.waitForFinished();
}
