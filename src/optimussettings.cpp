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

#include "optimussettings.h"
#include "daemonclient.h"
#include "singleapplication.h"

#include <QProcess>
#include <QFile>
#include <QSettings>
#include <QDebug>
#include <QMessageBox>

OptimusSettings::OptimusSettings(QObject *parent) :
    QObject(parent)
{
    QFile configFile("/etc/optimus-manager/optimus-manager.conf");
    if (configFile.exists())
        configFile.copy("/tmp/optimus-manager.conf");

    m_settings = new QSettings("/tmp/optimus-manager.conf", QSettings::IniFormat, this);
}

OptimusSettings::~OptimusSettings()
{
    QFile::remove("/tmp/optimus-manager.conf");
}

void OptimusSettings::apply()
{
    m_settings->sync();

    // Move generated settings to config path
    QProcess process;
    process.setProgram("pkexec");
    process.setArguments({"cp", "/tmp/optimus-manager.conf", "/etc/optimus-manager/optimus-manager.conf"});
    process.start();
    process.waitForFinished();

    if (m_startupModeString.isEmpty())
        return;

    // Set startup mode
    DaemonClient client;
    client.connect();
    if (client.error()) {
        QMessageBox message(QMessageBox::Warning, SingleApplication::applicationName(), tr("Unable to connect to optimus-manager daemon to send startup mode: ") + client.errorString());
        message.exec();
        return;
    }

    if (client.send(m_startupModeString) == -1) {
        QMessageBox message(QMessageBox::Warning, SingleApplication::applicationName(), tr("Unable to send startup mode to optimus-manager daemon: ") + client.errorString());
        message.exec();
    }
}

OptimusSettings::StartupMode OptimusSettings::startupMode() const
{
    QFile file("/var/lib/optimus-manager/startup_mode");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox message(QMessageBox::Warning, SingleApplication::applicationName(), tr("Unable to open startup mode file"));
        message.exec();
        return Intel;
    }

    QByteArray modeString = file.readAll();
    if (modeString == "intel")
        return Intel;

    if (modeString == "nvidia")
        return Nvidia;

    if (modeString == "nvidia_once")
        return NvidiaOnce;

    QMessageBox message(QMessageBox::Warning, SingleApplication::applicationName(), tr("Unknown mode in startup file"));
    message.exec();
    return Intel;
}

void OptimusSettings::setStartupMode(OptimusSettings::StartupMode mode)
{
    switch (mode) {
    case Intel:
        m_startupModeString = "startup_intel";
        break;
    case Nvidia:
        m_startupModeString = "startup_nvidia";
        break;
    case NvidiaOnce:
        m_startupModeString = "startup_nvidia_once";
        break;
    }
}

OptimusSettings::SwitchingBackend OptimusSettings::switchingBackend() const
{
    const QString backend = m_settings->value("optimus/switching", "nouveau").toString();

    // Parse backend
    if (backend == "nouveau")
        return Nouveau;
    if (backend == "bbswitch")
        return Bbswitch;
    return NoneBackend;
}

void OptimusSettings::setSwitchingBackend(OptimusSettings::SwitchingBackend backend)
{
    QString backendString;
    switch (backend) {
    case NoneBackend:
        backendString = "none";
        break;
    case Nouveau:
        backendString = "nouveau";
        break;
    case Bbswitch:
        backendString = "bbswitch";
        break;
    }

    m_settings->setValue("optimus/switching", backendString);
}

bool OptimusSettings::isLoginManagerControl() const
{
    const QString controlString = m_settings->value("optimus/login_manager_control", "yes").toString();

    return controlString == "yes";
}

void OptimusSettings::setLoginManagerControl(bool enable)
{
    const QString loginControlString = enable ? "yes" : "no";
    m_settings->setValue("optimus/login_manager_control", loginControlString);
}

bool OptimusSettings::isPciPowerControlEnabled() const
{
    const QString powerControlString = m_settings->value("optimus/pci_power_control", "yes").toString();

    return powerControlString == "yes";
}

void OptimusSettings::setPciPowerControlEnabled(bool enable)
{
    const QString powerControlString = enable ? "yes" : "no";
    m_settings->setValue("optimus/pci_power_control", powerControlString);
}

bool OptimusSettings::isPciResetEnabled() const
{
    const QString pciResetString = m_settings->value("optimus/pci_reset", "yes").toString();

    return pciResetString == "yes";
}

void OptimusSettings::setPciResetEnabled(bool enable)
{
    const QString pciResetString = enable ? "yes" : "no";

    m_settings->setValue("optimus/pci_reset", pciResetString);
}

bool OptimusSettings::isTerminateSesionsEnabled() const
{
    const QString terminateSessionsString = m_settings->value("optimus/terminate_sessions", "yes").toString();

    return terminateSessionsString == "yes";
}

void OptimusSettings::setTerminateSesionsEnabled(bool enable)
{
    const QString terminateSessionsString = enable ? "yes" : "no";

    m_settings->setValue("optimus/terminate_sessions", terminateSessionsString);
}

bool OptimusSettings::isKillX11Enabled() const
{
    const QString killX11String = m_settings->value("optimus/kill_x11", "yes").toString();

    return killX11String == "yes";
}

void OptimusSettings::setKillX11Enabled(bool enable)
{
    const QString killX11String = enable ? "yes" : "no";

    m_settings->setValue("optimus/kill_x11", killX11String);
}

bool OptimusSettings::isKillLogindEnabled() const
{
    const QString killLogindString = m_settings->value("optimus/kill_logind", "yes").toString();

    return killLogindString == "yes";
}

void OptimusSettings::setKillLogindEnabled(bool enable)
{
    const QString killLogindString = enable ? "yes" : "no";

    m_settings->setValue("optimus/kill_logind", killLogindString);
}

OptimusSettings::Driver OptimusSettings::intelDriver() const
{
    const QString driverString = m_settings->value("intel/driver", "modesetting").toString();

    // Parse driver
    if (driverString == "modesetting")
        return Modesetting;
    return IntelDriver;
}

void OptimusSettings::setIntelDriver(OptimusSettings::Driver driver)
{
    QString driverString;
    switch (driver) {
    case Modesetting:
        driverString = "modesetting";
        break;
    case IntelDriver:
        driverString = "intel";
        break;
    }

    m_settings->setValue("intel/driver", driverString);
}

OptimusSettings::AccelMethod OptimusSettings::intelAccelMethod() const
{
    const QString accelMethodString = m_settings->value("intel/accel", "").toString();

    // Parse method
    if (accelMethodString == "sna")
        return SNA;
    if (accelMethodString == "xna")
        return XNA;
    return DefaultMethod;
}

void OptimusSettings::setIntelAccelMethod(OptimusSettings::AccelMethod method)
{
    QString accelMethodString;
    switch (method) {
    case SNA:
        accelMethodString = "sna";
        break;
    case XNA:
        accelMethodString = "xna";
        break;
    default:
        break;
    }

    m_settings->setValue("intel/accel", accelMethodString);
}

OptimusSettings::TearFree OptimusSettings::intelTearFree() const
{
    const QString tearFreeString = m_settings->value("intel/tearfree", "").toString();

    // Parse tearfree
    if (tearFreeString == "yes")
        return EnableTearFree;
    if (tearFreeString == "no")
        return DisableTearFree;
    return DefaultTearFree;
}

void OptimusSettings::setIntelTearFree(OptimusSettings::TearFree tearFree)
{
    QString tearFreeString;
    switch (tearFree) {
    case EnableTearFree:
        tearFreeString = "yes";
        break;
    case DisableTearFree:
        tearFreeString = "no";
        break;
    default:
        break;
    }

    m_settings->setValue("intel/tearfree", tearFreeString);
}

OptimusSettings::DRI OptimusSettings::intelDri() const
{
    return m_settings->value("intel/DRI", DRI3).value<DRI>();
}

void OptimusSettings::setIntelDri(OptimusSettings::DRI dri)
{
    m_settings->setValue("intel/DRI", dri);
}

bool OptimusSettings::isIntelModesetEnabled() const
{
    const QString modesetString = m_settings->value("intel/modeset", "yes").toString();

    return modesetString == "yes";
}

void OptimusSettings::setIntelModesetEnabled(bool enabled)
{
    const QString modesetString = enabled ? "yes" : "no";
    m_settings->setValue("intel/modeset", modesetString);
}

OptimusSettings::DRI OptimusSettings::nvidiaDri() const
{
    return m_settings->value("nvidia/DRI", DRI3).value<DRI>();
}

void OptimusSettings::setNvidiaDri(OptimusSettings::DRI dri)
{
    m_settings->setValue("nvidia/DRI", dri);
}

bool OptimusSettings::isNvidiaModesetEnabled() const
{
    const QString modesetString = m_settings->value("nvidia/modeset", "yes").toString();

    return modesetString == "yes";
}

void OptimusSettings::setNvidiaModesetEnabled(bool enabled)
{
    const QString modesetString = enabled ? "yes" : "no";
    m_settings->setValue("nvidia/modeset", modesetString);
}

bool OptimusSettings::isNvidiaPatEnabled() const
{
    const QString patString = m_settings->value("nvidia/PAT", "yes").toString();

    return patString == "yes";
}

void OptimusSettings::setNvidiaPatEnabled(bool enabled)
{
    const QString patString = enabled ? "yes" : "no";
    m_settings->setValue("nvidia/PAT", patString);
}

int OptimusSettings::nvidiaDpi() const
{
    return m_settings->value("nvidia/DPI", 0).toInt();
}

void OptimusSettings::setNvidiaDpi(int dpi)
{
    if (dpi == 0)
        m_settings->setValue("nvidia/DPI", "");
    else
        m_settings->setValue("nvidia/DPI", dpi);
}

OptimusSettings::NvidiaOptions OptimusSettings::nvidiaOptions() const
{
    const QStringList optionsStrings = m_settings->value("nvidia/options", "overclocking").toStringList();

    // Parse options
    NvidiaOptions options;
    if (optionsStrings.contains("overclocking"))
        options |= Overclocking;
    if (optionsStrings.contains("triple_buffer"))
        options |= TripleBuffer;

    return options;
}

void OptimusSettings::setNvidiaOptions(NvidiaOptions options)
{
    QStringList optionsStrings;

    if (options.testFlag(Overclocking))
        optionsStrings.append("overclocking");

    if (options.testFlag(TripleBuffer))
        optionsStrings.append("triple_buffer");

    m_settings->setValue("nvidia/options", optionsStrings);
}
