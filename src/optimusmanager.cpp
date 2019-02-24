#include "optimusmanager.h"
#include "appsettings.h"
#include "settingsdialog.h"
#include "singleapplication.h"

#include <QSystemTrayIcon>
#include <QProcess>
#include <QFileInfo>
#include <QDebug>
#include <QMenu>
#include <QMessageBox>

OptimusManager::OptimusManager(QObject *parent) :
    QObject(parent)
{
    // Setup context menu
    const AppSettings settings;
    m_contextMenu = new QMenu;
    m_contextMenu->addAction(QIcon::fromTheme("preferences-system"), "Settings", this, &OptimusManager::openSettings);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(settings.modeIcon(Intel), "Switch to Intel", this, &OptimusManager::switchToIntel);
    m_contextMenu->addAction(settings.modeIcon(Nvidia), "Switch to Nvidia", this, &OptimusManager::switchToNvidia);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(QIcon::fromTheme("application-exit"), "Exit", SingleApplication::instance(), &SingleApplication::quit);

    // Setup tray
    m_trayIcon = new QSystemTrayIcon(this);
    m_trayIcon->setContextMenu(m_contextMenu);
    switch (currentMode()) {
    case Intel:
        m_trayIcon->setIcon(settings.modeIcon(Intel));
        break;
    case Nvidia:
        m_trayIcon->setIcon(settings.modeIcon(Nvidia));
        break;
    }
    m_trayIcon->show();
}

OptimusManager::~OptimusManager()
{
    delete m_contextMenu;
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
    dialog.exec();
}

void OptimusManager::switchMode(OptimusManager::Mode mode)
{
    QMessageBox confirmMessage;
    confirmMessage.setText("You are about to switch GPUs. This will restart the display manager and all your applications WILL CLOSE.");
    confirmMessage.setStandardButtons(QMessageBox::Apply | QMessageBox::Cancel);
    confirmMessage.setIcon(QMessageBox::Question);
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

OptimusManager::Mode OptimusManager::currentMode()
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
        return Nvidia;
    case 1:
        return Intel;
    default:
        qFatal("Unable to detect mode");
    }
}
