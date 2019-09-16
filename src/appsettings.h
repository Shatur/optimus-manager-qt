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

#include "daemonclient.h"

#include <QSettings>
#include <QTranslator>
#include <QLocale>

class QTranslator;

class AppSettings : QSettings
{
    Q_OBJECT
    Q_DISABLE_COPY(AppSettings)

public:
    AppSettings(QObject *parent = nullptr);

    // General settings
    void initTranslator();
    QLocale::Language language() const;
    void setLocale(QLocale::Language lang);
    static QLocale::Language defaultLocale();

    bool isAutostartEnabled() const;
    void setAutostartEnabled(bool enabled);
    static bool defaultAutostartEnabled();

    bool isConfirmSwitching() const;
    void setConfirmSwitching(bool confirm);
    static bool defaultConfirmSwitching();

    QString gpuIconName(DaemonClient::GPU gpu) const;
    void setGpuIconName(DaemonClient::GPU gpu, const QString &name);
    static QString defaultTrayIconName(DaemonClient::GPU trayStatus);

private:
    void applyLocale(QLocale::Language lang);
    static QTranslator m_appTranslator;
};

#endif // APPSETTINGS_H
