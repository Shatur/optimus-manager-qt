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
        QMessageBox message(QMessageBox::Warning, SingleApplication::applicationName(), tr("Unable to connect to optimus-manager daemon to send startup mode: %1").arg(client.errorString()));
        message.exec();
        return;
    }

    if (client.send(m_startupModeString) == -1) {
        QMessageBox message(QMessageBox::Warning, SingleApplication::applicationName(), tr("Unable to send startup mode to optimus-manager daemon: %1").arg(client.errorString()));
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
    if (modeString.back() == '\n')
        modeString.chop(1);

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
        m_startupModeString = QStringLiteral("startup_intel");
        break;
    case Nvidia:
        m_startupModeString = QStringLiteral("startup_nvidia");
        break;
    case NvidiaOnce:
        m_startupModeString = QStringLiteral("startup_nvidia_once");
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
        backendString = QStringLiteral("none");
        break;
    case Nouveau:
        backendString = QStringLiteral("nouveau");
        break;
    case Bbswitch:
        backendString = QStringLiteral("bbswitch");
        break;
    }

    m_settings->setValue("optimus/switching", backendString);
}

bool OptimusSettings::isPciPowerControlEnabled() const
{
    const QString powerControlString = m_settings->value("optimus/pci_power_control", boolToOption(true)).toString();
    return optionToBool(powerControlString);
}

void OptimusSettings::setPciPowerControlEnabled(bool enable)
{
    m_settings->setValue("optimus/pci_power_control", boolToOption(enable));
}

bool OptimusSettings::isAutoLogoutEnabled() const
{
    const QString terminateSessionsString = m_settings->value("optimus/auto_logout", boolToOption(true)).toString();
    return optionToBool(terminateSessionsString);
}

void OptimusSettings::setAutoLogoutEnabled(bool enable)
{
    m_settings->setValue("optimus/auto_logout", boolToOption(enable));
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
        driverString = QStringLiteral("modesetting");
        break;
    case IntelDriver:
        driverString = QStringLiteral("intel");
        break;
    }

    m_settings->setValue("intel/driver", driverString);
}

OptimusSettings::AccelMethod OptimusSettings::intelAccelMethod() const
{
    const QString accelMethodString = m_settings->value("intel/accel", QString()).toString();

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
        accelMethodString = QStringLiteral("sna");
        break;
    case XNA:
        accelMethodString = QStringLiteral("xna");
        break;
    default:
        break;
    }

    m_settings->setValue("intel/accel", accelMethodString);
}

OptimusSettings::TearFree OptimusSettings::intelTearFree() const
{
    const QString tearFreeString = m_settings->value("intel/tearfree", QString()).toString();

    // Parse tearfree
    if (tearFreeString == boolToOption(true))
        return EnableTearFree;
    if (tearFreeString == boolToOption(false))
        return DisableTearFree;
    return DefaultTearFree;
}

void OptimusSettings::setIntelTearFree(OptimusSettings::TearFree tearFree)
{
    QString tearFreeString;
    switch (tearFree) {
    case EnableTearFree:
        tearFreeString = boolToOption(true);
        break;
    case DisableTearFree:
        tearFreeString = boolToOption(false);
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
    const QString modesetString = m_settings->value("intel/modeset", boolToOption(true)).toString();
    return optionToBool(modesetString);
}

void OptimusSettings::setIntelModesetEnabled(bool enabled)
{
    m_settings->setValue("intel/modeset", boolToOption(enabled));
}

bool OptimusSettings::isNvidiaModesetEnabled() const
{
    const QString modesetString = m_settings->value("nvidia/modeset", boolToOption(true)).toString();
    return optionToBool(modesetString);
}

void OptimusSettings::setNvidiaModesetEnabled(bool enabled)
{
    m_settings->setValue("nvidia/modeset", boolToOption(enabled));
}

bool OptimusSettings::isNvidiaPatEnabled() const
{
    const QString patString = m_settings->value("nvidia/PAT", boolToOption(true)).toString();
    return optionToBool(patString);
}

void OptimusSettings::setNvidiaPatEnabled(bool enabled)
{
    m_settings->setValue("nvidia/PAT", boolToOption(enabled));
}

int OptimusSettings::nvidiaDpi() const
{
    return m_settings->value("nvidia/DPI", 96).toInt();
}

void OptimusSettings::setNvidiaDpi(int dpi)
{
    if (dpi == 0)
        m_settings->setValue("nvidia/DPI", QString());
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

    if (optionsStrings.empty())
        m_settings->remove("nvidia/options");
    else
        m_settings->setValue("nvidia/options", optionsStrings);
}

QString OptimusSettings::boolToOption(bool value)
{
    return value ? QStringLiteral("yes") : QStringLiteral("no");
}

bool OptimusSettings::optionToBool(const QString &option)
{
    return option == "yes";
}
