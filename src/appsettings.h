/*
 *  Copyright © 2019-2021 Hennadii Chernyshchyk <genaloner@gmail.com>
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
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a get of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include "optimussettings.h"

#include <QLocale>

class QTranslator;
class QSettings;

class AppSettings : QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(AppSettings)

public:
    explicit AppSettings(QObject *parent = nullptr);

    // General settings
    void setupLocalization() const;
    QLocale locale() const;
    void setLocale(const QLocale &locale);
    static QLocale defaultLocale();

    static bool isAutostartEnabled();
    static void setAutostartEnabled(bool enabled);
    static bool defaultAutostartEnabled();

    bool isConfirmSwitching() const;
    void setConfirmSwitching(bool confirm);
    static bool defaultConfirmSwitching();

    QIcon modeIcon(OptimusSettings::Mode mode) const;
    QString modeIconName(OptimusSettings::Mode mode) const;
    void setModeIconName(OptimusSettings::Mode mode, const QString &name);
    static QString defaultModeIconName(OptimusSettings::Mode mode);

private:
    static void applyLocale(const QLocale &locale);

    QSettings *m_settings;

    static QTranslator s_appTranslator;
};

#endif // APPSETTINGS_H
