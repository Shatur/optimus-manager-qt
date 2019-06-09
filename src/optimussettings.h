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

#ifndef OPTIMUSSETTINGS_H
#define OPTIMUSSETTINGS_H

#include <QObject>
#include <QFlags>

class QSettings;

class OptimusSettings : private QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(OptimusSettings)

public:
    enum SwitchingBackend {
        NoneBackend,
        Nouveau,
        Bbswitch
    };
    enum StartupMode {
        Intel,
        Nvidia,
        NvidiaOnce
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
        TripleBuffer = 2
    };
    Q_DECLARE_FLAGS(NvidiaOptions, NvidiaOption)

    OptimusSettings(QObject *parent = nullptr);
    ~OptimusSettings() override;

    void apply();

    StartupMode startupMode() const;
    void setStartupMode(StartupMode mode);

    // Optimus
    SwitchingBackend switchingBackend() const;
    void setSwitchingBackend(SwitchingBackend backend);

    bool isPciPowerControlEnabled() const;
    void setPciPowerControlEnabled(bool enable);

    bool isAutoLogoutEnabled() const;
    void setAutoLogoutEnabled(bool enable);

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
    bool isNvidiaModesetEnabled() const;
    void setNvidiaModesetEnabled(bool enabled);

    bool isNvidiaPatEnabled() const;
    void setNvidiaPatEnabled(bool enabled);

    int nvidiaDpi() const;
    void setNvidiaDpi(int dpi);

    NvidiaOptions nvidiaOptions() const;
    void setNvidiaOptions(NvidiaOptions options);

private:
    static QString boolToOption(bool value);
    static bool optionToBool(const QString &option);

    QString m_startupModeString;
    QSettings *m_settings;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(OptimusSettings::NvidiaOptions)

#endif // OPTIMUSSETTINGS_H
