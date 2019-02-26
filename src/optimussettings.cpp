#include "optimussettings.h"

#include <QProcess>
#include <QFile>
#include <QSettings>
#include <QDebug>

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

    QProcess process;
    process.setProgram("pkexec");
    process.setArguments({"cp", "/tmp/optimus-manager.conf", "/etc/optimus-manager/optimus-manager.conf"});
    process.start();
    process.waitForFinished();
}

OptimusSettings::SwitchingBackend OptimusSettings::switchingBackend() const
{
    const QString backend = m_settings->value("optimus/switching", "nouveau").toString();

    // Parse mode
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
    const QString controlString = enable ? "yes" : "no";
    m_settings->setValue("optimus/login_manager_control", controlString);
}

bool OptimusSettings::isPciPowerControlEnabled() const
{
    const QString controlString = m_settings->value("optimus/pci_power_control", "yes").toString();

    return controlString == "yes";
}

void OptimusSettings::setPciPowerControlEnabled(bool enable)
{
    const QString controlString = enable ? "yes" : "no";
    m_settings->setValue("optimus/pci_power_control", controlString);
}

bool OptimusSettings::isPciResetEnabled() const
{
    const QString controlString = m_settings->value("optimus/pci_reset", "yes").toString();

    return controlString == "yes";
}

void OptimusSettings::setPciResetEnabled(bool enable)
{
    const QString controlString = enable ? "yes" : "no";
    m_settings->setValue("optimus/pci_reset", controlString);
}

OptimusSettings::Driver OptimusSettings::intelDriver() const
{
    const QString backend = m_settings->value("intel/driver", "modesetting").toString();

    // Parse mode
    if (backend == "modesetting")
        return Modesetting;
    return IntelDriver;
}

void OptimusSettings::setIntelDriver(OptimusSettings::Driver driver)
{
    QString backendString;
    switch (driver) {
    case Modesetting:
        backendString = "modesetting";
        break;
    case IntelDriver:
        backendString = "intel";
        break;
    }

    m_settings->setValue("intel/driver", backendString);
}

OptimusSettings::AccelMethod OptimusSettings::intelAccelMethod() const
{
    const QString backend = m_settings->value("intel/accel", "").toString();

    // Parse mode
    if (backend == "sna")
        return SNA;
    if (backend == "xna")
        return XNA;
    return DefaultMethod;
}

void OptimusSettings::setIntelAccelMethod(OptimusSettings::AccelMethod method)
{
    QString methodString;
    switch (method) {
    case SNA:
        methodString = "sna";
        break;
    case XNA:
        methodString = "xna";
        break;
    default:
        break;
    }

    m_settings->setValue("intel/accel", methodString);
}

OptimusSettings::TearFree OptimusSettings::intelTearFree() const
{
    const QString backend = m_settings->value("intel/tearfree", "").toString();

    // Parse mode
    if (backend == "yes")
        return EnableTearFree;
    if (backend == "no")
        return DisableTearFree;
    return DefaultTearFree;
}

void OptimusSettings::setIntelTearFree(OptimusSettings::TearFree tearFree)
{
    QString methodString;
    switch (tearFree) {
    case EnableTearFree:
        methodString = "yes";
        break;
    case DisableTearFree:
        methodString = "no";
        break;
    default:
        break;
    }

    m_settings->setValue("intel/tearfree", methodString);
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
    const QString controlString = m_settings->value("intel/modeset", "yes").toString();

    return controlString == "yes";
}

void OptimusSettings::setIntelModesetEnabled(bool enabled)
{
    const QString controlString = enabled ? "yes" : "no";
    m_settings->setValue("intel/modeset", controlString);
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
    const QString controlString = m_settings->value("nvidia/modeset", "yes").toString();

    return controlString == "yes";
}

void OptimusSettings::setNvidiaModesetEnabled(bool enabled)
{
    const QString controlString = enabled ? "yes" : "no";
    m_settings->setValue("nvidia/modeset", controlString);
}

bool OptimusSettings::isNvidiaPatEnabled() const
{
    const QString controlString = m_settings->value("nvidia/PAT", "yes").toString();

    return controlString == "yes";
}

void OptimusSettings::setNvidiaPatEnabled(bool enabled)
{
    const QString controlString = enabled ? "yes" : "no";
    m_settings->setValue("nvidia/PAT", controlString);
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
    const QStringList optionStrings = m_settings->value("nvidia/options", "overclocking").toStringList();

    // Parse mode
    NvidiaOptions options;
    if (optionStrings.contains("overclocking"))
        options |= Overclocking;
    if (optionStrings.contains("triple_buffer"))
        options |= TrippleBuffer;

    return options;
}

void OptimusSettings::setNvidiaOptions(NvidiaOptions options)
{
    QStringList optionStrings;

    if (options.testFlag(Overclocking))
        optionStrings.append("overclocking");

    if (options.testFlag(TrippleBuffer))
        optionStrings.append("triple_buffer");

    m_settings->setValue("nvidia/options", optionStrings);
}
