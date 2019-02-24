#ifndef OPTIMUSSETTINGS_H
#define OPTIMUSSETTINGS_H

#include <QObject>
#include <QFlags>

class QSettings;

class OptimusSettings : private QObject
{
public:
    enum SwitchingBackend {
        NoneBackend,
        Nouveau,
        Bbswitch
    };
    enum Driver {
        Modesetting,
        IntelDriver
    };
    enum AccelMethod {
        DefaultMethod,
        SNA,
        XNA
    };
    enum TearFree {
        DefaultTearFree,
        EnableTearFree,
        DisableTearFree
    };
    enum DRI {
        DRI2 = 2,
        DRI3 = 3,
    };
    Q_ENUM(DRI)
    enum NvidiaOption {
        Overclocking = 1,
        TrippleBuffer = 2
    };
    Q_DECLARE_FLAGS(NvidiaOptions, NvidiaOption)

    OptimusSettings(QObject *parent = nullptr);
    ~OptimusSettings() override;

    void apply();

    // Optimus
    SwitchingBackend switchingBackend() const;
    void setSwitchingBackend(SwitchingBackend backend);

    bool isLoginManagerControl() const;
    void setLoginManagerControl(bool enable);

    bool isPciPowerControlEnabled() const;
    void setPciPowerControlEnabled(bool enable);

    bool isPciResetEnabled() const;
    void setPciResetEnabled(bool enable);

    // Intel
    Driver intelDriver() const;
    void setIntelDriver(Driver driver);

    AccelMethod intelAccelMethod() const;
    void setIntelAccelMethod(AccelMethod method);

    TearFree intelTearFree() const;
    void setIntelTearFree(TearFree tearFree);

    DRI intelDri() const;
    void setIntelDri(DRI dri);

    bool isIntelModesetEnabled() const;
    void setIntelModesetEnabled(bool enabled);

    // Nvidia
    DRI nvidiaDri() const;
    void setNvidiaDri(DRI dri);

    bool isNvidiaModesetEnabled() const;
    void setNvidiaModesetEnabled(bool enabled);

    bool isNvidiaPatEnabled() const;
    void setNvidiaPatEnabled(bool enabled);

    int nvidiaDpi() const;
    void setNvidiaDpi(int dpi);

    NvidiaOptions nvidiaOptions() const;
    void setNvidiaOptions(NvidiaOptions options);

private:
    QSettings *m_settings;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(OptimusSettings::NvidiaOptions)

#endif // OPTIMUSSETTINGS_H
