/*
 *  Copyright © 2019-2020 Hennadii Chernyshchyk <genaloner@gmail.com>
 *
 *  This file is part of Optimus Manager Qt.
 *
 *  Optimus Manager Qt is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Optimus Manager Qt is distributed in the hope that it will be useful,
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

#include <QLocale>
#include <QSettings>

class QTranslator;

class AppSettings : QSettings
{
    Q_OBJECT
    Q_DISABLE_COPY(AppSettings)

public:
    enum Gpu {
        IntelGpu,
        AmdGpu,
        NvidiaGpu,
        HybridGpu
    };
    Q_ENUM(Gpu)

    explicit AppSettings(QObject *parent = nullptr);

    // General settings
    void setupLocalization() const;
    QLocale::Language language() const;
    void setLanguage(QLocale::Language lang);
    static QLocale::Language defaultLanguage();

    static bool isAutostartEnabled();
    static void setAutostartEnabled(bool enabled);
    static bool defaultAutostartEnabled();

    bool isConfirmSwitching() const;
    void setConfirmSwitching(bool confirm);
    static bool defaultConfirmSwitching();

    QString gpuIconName(Gpu gpu) const;
    void setGpuIconName(Gpu gpu, const QString &name);
    static QString defaultTrayIconName(Gpu trayStatus);

private:
    static void loadLanguage(QLocale::Language lang);
    static QTranslator s_appTranslator;
};

#endif // APPSETTINGS_H
