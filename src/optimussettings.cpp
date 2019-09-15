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

const QMap<bool, QString> OptimusSettings::boolMap = { { false, QStringLiteral("no") },
                                                       { true, QStringLiteral("yes") } };
const QMap<OptimusSettings::SwitchingMethod, QString> OptimusSettings::switchingMethodMap = { { NoneMethod, QStringLiteral("none") },
                                                                                                { Nouveau, QStringLiteral("nouveau") },
                                                                                                { Bbswitch, QStringLiteral("bbswitch") },
                                                                                                { AcpiCall, QStringLiteral("acpi_call") } };
const QMap<OptimusSettings::PciReset, QString> OptimusSettings::pciResetMap = { { NoReset, boolMap[false] },
                                                                                { FunctionLevelReset, QStringLiteral("function_level") },
                                                                                { HotReset, QStringLiteral("hot_reset") } };
const QMap<OptimusSettings::Driver, QString> OptimusSettings::driverMap = { { Modesetting, QStringLiteral("modesetting") },
                                                                            { IntelDriver, QStringLiteral("intel") } };
const QMap<OptimusSettings::AccelMethod, QString> OptimusSettings::accelMethodMap = { { DefaultMethod, {} },
                                                                                      { SNA, QStringLiteral("sna") },
                                                                                      { XNA, QStringLiteral("xna") } };
const QMap<OptimusSettings::TearFree, QString> OptimusSettings::tearFreeMap = { { DefaultTearFree, {} },
                                                                                { EnableTearFree, boolMap[true] },
                                                                                { DisableTearFree, boolMap[false] } };
const QMap<OptimusSettings::GPU, QString> OptimusSettings::gpuMap = { { Intel, QStringLiteral("intel") },
                                                                      { Nvidia, QStringLiteral("nvidia") } };
const QMap<OptimusSettings::NvidiaOption, QString> OptimusSettings::nvidiaOptionMap = { { Overclocking, QStringLiteral("overclocking") },
                                                                                        { TripleBuffer, QStringLiteral("triple_buffer") } };

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
    if (QProcess::execute("pkexec", {"cp", "/tmp/optimus-manager.conf", "/etc/optimus-manager/optimus-manager.conf"}) != 0)
        return;

    if (!m_startupModeString.isEmpty()) {
        // Set startup mode
        DaemonClient client;
        client.connect();
        if (client.error()) {
            QMessageBox message;
            message.setIcon(QMessageBox::Warning);
            message.setText(tr("Unable to connect to optimus-manager daemon to send startup mode: %1").arg(client.errorString()));
            message.exec();
            return;
        }

        if (client.send(m_startupModeString) == -1) {
            QMessageBox message;
            message.setIcon(QMessageBox::Warning);
            message.setText(tr("Unable to send startup mode to optimus-manager daemon: %1").arg(client.errorString()));
            message.exec();
        }
    }
}

OptimusSettings::GPU OptimusSettings::startupMode() const
{
    QFile file("/var/lib/optimus-manager/startup_mode");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox message(QMessageBox::Warning, SingleApplication::applicationName(), tr("Unable to open startup mode file"));
        message.exec();
        return defaultStartupMode();
    }

    QByteArray modeString = file.readAll();
    if (modeString.back() == '\n')
        modeString.chop(1);

    return gpuMap.key(modeString, defaultStartupMode());
}

void OptimusSettings::setStartupMode(GPU mode)
{
    m_startupModeString = gpuMap[mode];
}

OptimusSettings::GPU OptimusSettings::defaultStartupMode()
{
    return Intel;
}

OptimusSettings::SwitchingMethod OptimusSettings::switchingMethod() const
{
    const QString method = m_settings->value("optimus/switching").toString();
    return switchingMethodMap.key(method, defaultSwitchingMethod());
}

void OptimusSettings::setSwitchingMethod(OptimusSettings::SwitchingMethod method)
{
    m_settings->setValue("optimus/switching", switchingMethodMap[method]);
}

OptimusSettings::SwitchingMethod OptimusSettings::defaultSwitchingMethod()
{
    return NoneMethod;
}

bool OptimusSettings::isPciPowerControlEnabled() const
{
    const QString powerControlString = m_settings->value("optimus/pci_power_control").toString();
    return boolMap.key(powerControlString, defaultPciPowerControlEnabled());
}

void OptimusSettings::setPciPowerControlEnabled(bool enable)
{
    m_settings->setValue("optimus/pci_power_control", boolMap[enable]);
}

bool OptimusSettings::defaultPciPowerControlEnabled()
{
    return false;
}

bool OptimusSettings::isPciRemoveEnabled() const
{
    const QString pciRemoveString = m_settings->value("optimus/pci_remove").toString();
    return boolMap.key(pciRemoveString, defaultPciRemoveEnabled());
}

void OptimusSettings::setPciRemoveEnabled(bool enable)
{
    m_settings->setValue("optimus/pci_remove", boolMap[enable]);
}

bool OptimusSettings::defaultPciRemoveEnabled()
{
    return false;
}

OptimusSettings::PciReset OptimusSettings::pciReset() const
{
    const QString pciResetString = m_settings->value("optimus/pci_reset").toString();
    return pciResetMap.key(pciResetString, defaultPciReset());
}

void OptimusSettings::setPciReset(PciReset type)
{
    m_settings->setValue("optimus/pci_reset", pciResetMap[type]);
}

OptimusSettings::PciReset OptimusSettings::defaultPciReset()
{
    return NoReset;
}

bool OptimusSettings::isAutoLogoutEnabled() const
{
    const QString terminateSessionsString = m_settings->value("optimus/auto_logout").toString();
    return boolMap.key(terminateSessionsString, defaultAutoLogoutEnabled());
}

void OptimusSettings::setAutoLogoutEnabled(bool enable)
{
    m_settings->setValue("optimus/auto_logout", boolMap[enable]);
}

bool OptimusSettings::defaultAutoLogoutEnabled()
{
    return true;
}

OptimusSettings::Driver OptimusSettings::intelDriver() const
{
    const QString driverString = m_settings->value("intel/driver").toString();
    return driverMap.key(driverString, defaultIntelDriver());
}

void OptimusSettings::setIntelDriver(OptimusSettings::Driver driver)
{
    m_settings->setValue("intel/driver", driverMap[driver]);
}

OptimusSettings::Driver OptimusSettings::defaultIntelDriver()
{
    return Modesetting;
}

OptimusSettings::AccelMethod OptimusSettings::intelAccelMethod() const
{
    const QString accelMethodString = m_settings->value("intel/accel").toString();
    return accelMethodMap.key(accelMethodString, defaultIntelAccelMethod());
}

void OptimusSettings::setIntelAccelMethod(OptimusSettings::AccelMethod method)
{
    m_settings->setValue("intel/accel", accelMethodMap[method]);
}

OptimusSettings::AccelMethod OptimusSettings::defaultIntelAccelMethod()
{
    return DefaultMethod;
}

OptimusSettings::TearFree OptimusSettings::intelTearFree() const
{
    const QString tearFreeString = m_settings->value("intel/tearfree").toString();
    return tearFreeMap.key(tearFreeString, defaultIntelTearFree());
}

void OptimusSettings::setIntelTearFree(OptimusSettings::TearFree tearFree)
{
    m_settings->setValue("intel/tearfree", tearFreeMap[tearFree]);
}

OptimusSettings::TearFree OptimusSettings::defaultIntelTearFree()
{
    return DefaultTearFree;
}

OptimusSettings::DRI OptimusSettings::intelDri() const
{
    return m_settings->value("intel/DRI", defaultIntelDri()).value<DRI>();
}

void OptimusSettings::setIntelDri(OptimusSettings::DRI dri)
{
    m_settings->setValue("intel/DRI", dri);
}

OptimusSettings::DRI OptimusSettings::defaultIntelDri()
{
    return DRI3;
}

bool OptimusSettings::isIntelModesetEnabled() const
{
    const QString modesetString = m_settings->value("intel/modeset").toString();
    return boolMap.key(modesetString, defaultIntelModesetEnabled());
}

void OptimusSettings::setIntelModesetEnabled(bool enabled)
{
    m_settings->setValue("intel/modeset", boolMap[enabled]);
}

bool OptimusSettings::defaultIntelModesetEnabled()
{
    return true;
}

bool OptimusSettings::isNvidiaModesetEnabled() const
{
    const QString modesetString = m_settings->value("nvidia/modeset").toString();
    return boolMap.key(modesetString, defaultNvidiaModesetEnabled());
}

void OptimusSettings::setNvidiaModesetEnabled(bool enabled)
{
    m_settings->setValue("nvidia/modeset", boolMap[enabled]);
}

bool OptimusSettings::defaultNvidiaModesetEnabled()
{
    return true;
}

bool OptimusSettings::isNvidiaPatEnabled() const
{
    const QString patString = m_settings->value("nvidia/PAT").toString();
    return boolMap.key(patString, defaultNvidiaPatEnabled());
}

void OptimusSettings::setNvidiaPatEnabled(bool enabled)
{
    m_settings->setValue("nvidia/PAT", boolMap[enabled]);
}

bool OptimusSettings::defaultNvidiaPatEnabled()
{
    return true;
}

int OptimusSettings::nvidiaDpi() const
{
    return m_settings->value("nvidia/DPI", defaultNvidiaDpi()).toInt();
}

void OptimusSettings::setNvidiaDpi(int dpi)
{
    if (dpi == 0)
        m_settings->setValue("nvidia/DPI", {});
    else
        m_settings->setValue("nvidia/DPI", dpi);
}

int OptimusSettings::defaultNvidiaDpi()
{
    return 96;
}

OptimusSettings::NvidiaOptions OptimusSettings::nvidiaOptions() const
{
    const QStringList optionStrings = m_settings->value("nvidia/options", nvidiaOptionsToStrings(defaultNvidiaOptions())).toStringList();
    return stringToNvidiaOptions(optionStrings);
}

void OptimusSettings::setNvidiaOptions(NvidiaOptions options)
{
    m_settings->setValue("nvidia/options", nvidiaOptionsToStrings(options));
}

OptimusSettings::NvidiaOptions OptimusSettings::defaultNvidiaOptions()
{
    return Overclocking;
}

QStringList OptimusSettings::nvidiaOptionsToStrings(NvidiaOptions options)
{
    QStringList optionStrings;
    for (auto it = nvidiaOptionMap.cbegin(); it != nvidiaOptionMap.cend(); ++it) {
        if (options.testFlag(it.key()))
            optionStrings.append(it.value());
    }

    return optionStrings;
}

OptimusSettings::NvidiaOptions OptimusSettings::stringToNvidiaOptions(const QStringList &optionStrings)
{
    NvidiaOptions options;
    for (auto it = nvidiaOptionMap.cbegin(); it != nvidiaOptionMap.cend(); ++it) {
        if (optionStrings.contains(it.value()))
            options |= it.key();
    }

    return options;
}
