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

#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include "optimusmanager.h"

#include <QSettings>
#include <QTranslator>
#include <QLocale>

class QTranslator;

class AppSettings : QSettings
{
    Q_OBJECT

public:
    AppSettings(QObject *parent = nullptr);

    // General settings
    void initTranslator();
    QLocale::Language language() const;
    void setLocale(QLocale::Language lang);

    bool isAutostartEnabled() const;
    void setAutostartEnabled(bool enabled);

    bool isConfirmSwitching() const;
    void setConfirmSwitching(bool confirm);

    QString modeIconName(OptimusManager::Mode mode) const;
    void setModeIconName(OptimusManager::Mode mode, const QString &name);
    static constexpr const char *defaultTrayIconName(OptimusManager::Mode trayStatus);

private:
    void applyLocale(QLocale::Language lang);
    static QTranslator m_appTranslator;
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
