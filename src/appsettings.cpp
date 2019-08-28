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

#include "appsettings.h"
#include "singleapplication.h"

#include <QStandardPaths>
#include <QFileInfo>
#include <QDebug>
#include <QIcon>

QTranslator AppSettings::m_appTranslator;

AppSettings::AppSettings(QObject *parent) :
    QSettings(parent)
{
}

void AppSettings::initTranslator()
{
    applyLocale(language());
    SingleApplication::installTranslator(&m_appTranslator);
}

QLocale::Language AppSettings::language() const
{
    return value("Locale", QLocale::AnyLanguage).value<QLocale::Language>();
}

void AppSettings::setLocale(QLocale::Language lang)
{
    if (lang == language())
        return;

    setValue("Locale", lang);
    applyLocale(lang);
}

bool AppSettings::isAutostartEnabled() const
{
    return QFileInfo::exists(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/autostart/optimus-manager-qt.desktop");
}

void AppSettings::setAutostartEnabled(bool enabled)
{
    QFile autorunFile(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/autostart/optimus-manager-qt.desktop");

    if (enabled) {
        // Create autorun file
        if (!autorunFile.exists()) {
            const QString desktopFileName = QStringLiteral("/usr/share/applications/optimus-manager-qt.desktop");

            if (!QFile::copy(desktopFileName, autorunFile.fileName()))
                qCritical() << tr("Unable to create autorun file from '%1'").arg(desktopFileName);
        }
    } else {
        // Remove autorun file
        if(autorunFile.exists())
            autorunFile.remove();
    }
}

bool AppSettings::isConfirmSwitching() const
{
    return value("ConfirmSwitching", true).toBool();
}

void AppSettings::setConfirmSwitching(bool confirm)
{
    setValue("ConfirmSwitching", confirm);
}

QString AppSettings::gpuIconName(OptimusSettings::GPU gpu) const
{
    switch (gpu) {
    case OptimusSettings::Intel:
        return value("IntelIcon", defaultTrayIconName(OptimusSettings::Intel)).toString();
    case OptimusSettings::Nvidia:
        return value("NvidiaIcon", defaultTrayIconName(OptimusSettings::Nvidia)).toString();
    }

    qFatal("Unknown GPU");
}

void AppSettings::setGpuIconName(OptimusSettings::GPU gpu, const QString &name)
{
    switch (gpu) {
    case OptimusSettings::Intel:
        setValue("IntelIcon", name);
        break;
    case OptimusSettings::Nvidia:
        setValue("NvidiaIcon", name);
        break;
    }
}

QString AppSettings::defaultTrayIconName(OptimusSettings::GPU trayStatus)
{
    switch (trayStatus) {
    case OptimusSettings::Intel:
        return QStringLiteral("prime-intel");
    case OptimusSettings::Nvidia:
        return QStringLiteral("prime-nvidia");
    }

    return QString();
}

void AppSettings::applyLocale(QLocale::Language lang)
{
    if (lang == QLocale::AnyLanguage)
        QLocale::setDefault(QLocale::system());
    else
        QLocale::setDefault(QLocale(lang));

    m_appTranslator.load(QLocale(), "optimus-manager", "_", ":/translations");
}
