#include "optimusmanager.h"
#include "appsettings.h"
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
    // Setup context menu
    const AppSettings settings;
    m_contextMenu = new QMenu;
    m_contextMenu->addAction(QIcon::fromTheme("preferences-system"), SettingsDialog::tr("Settings"), this, &OptimusManager::openSettings);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(settings.modeIcon(Intel), tr("Switch to Intel"), this, &OptimusManager::switchToIntel);
    m_contextMenu->addAction(settings.modeIcon(Nvidia), tr("Switch to Nvidia"), this, &OptimusManager::switchToNvidia);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(QIcon::fromTheme("application-exit"), tr("Exit"), SingleApplication::instance(), &SingleApplication::quit);

    // Setup tray
    const Mode mode = currentMode();
#ifdef KDE
    m_trayIcon = new KStatusNotifierItem(this);
    m_trayIcon->setStandardActionsEnabled(false);
    m_trayIcon->setToolTipTitle(SingleApplication::applicationName());
    m_trayIcon->setCategory(KStatusNotifierItem::SystemServices);
    m_trayIcon->setIconByName(settings.modeIconName(mode));
    m_trayIcon->setToolTipIconByName(m_trayIcon->iconName());
    m_trayIcon->setToolTipSubTitle(tr("Current videocard: ") + QMetaEnum::fromType<Mode>().valueToKey(mode));
#else
    m_trayIcon = new QSystemTrayIcon(this);
    m_trayIcon->setIcon(settings.modeIcon(mode));
    m_trayIcon->show();
#endif
    m_trayIcon->setContextMenu(m_contextMenu);
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
    if (dialog.languageChanged())
        retranslateUi();
}

void OptimusManager::switchMode(OptimusManager::Mode mode)
{
    QMessageBox confirmMessage;
    confirmMessage.setText(tr("You are about to switch GPUs. This will restart the display manager and all your applications WILL CLOSE."));
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

void OptimusManager::retranslateUi()
{
    m_trayIcon->setToolTipSubTitle(tr("Current videocard: ") + QMetaEnum::fromType<Mode>().valueToKey(currentMode()));
    m_contextMenu->actions().at(0)->setText(SettingsDialog::tr("Settings"));
    m_contextMenu->actions().at(2)->setText(tr("Switch to Intel"));
    m_contextMenu->actions().at(3)->setText(tr("Switch to Nvidia"));
    m_contextMenu->actions().at(5)->setText(tr("Exit"));
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
