#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include "optimusmanager.h"

#include <QSettings>

class AppSettings : QSettings
{
public:
    AppSettings(QObject *parent = nullptr);

    bool isAutostartEnabled() const;
    void setAutostartEnabled(bool enabled);

    bool isConfirmSwitching() const;
    void setConfirmSwitching(bool confirm);

    QString modeIconName(OptimusManager::Mode mode) const;
    QIcon modeIcon(OptimusManager::Mode mode) const;
    void setModeIconName(OptimusManager::Mode mode, const QString &name);
    static constexpr const char *defaultTrayIconName(OptimusManager::Mode trayStatus);
};

constexpr const char *AppSettings::defaultTrayIconName(OptimusManager::Mode trayStatus)
{
    switch (trayStatus) {
    case OptimusManager::Intel:
        return "prime-intel";
    case OptimusManager::Nvidia:
        return "prime-nvidia";
    }

    return nullptr;
}

#endif // APPSETTINGS_H
