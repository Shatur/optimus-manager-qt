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
#include <QTranslator>

QTranslator AppSettings::s_appTranslator;

AppSettings::AppSettings(QObject *parent)
    : QSettings(parent)
{
}

void AppSettings::initTranslator()
{
    applyLocale(language());
    SingleApplication::installTranslator(&s_appTranslator);
}

QLocale::Language AppSettings::language() const
{
    return value("Locale", defaultLocale()).value<QLocale::Language>();
}

void AppSettings::setLocale(QLocale::Language lang)
{
    if (lang == language())
        return;

    setValue("Locale", lang);
    applyLocale(lang);
}

QLocale::Language AppSettings::defaultLocale()
{
    return QLocale::AnyLanguage;
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

bool AppSettings::defaultAutostartEnabled()
{
    return false;
}

bool AppSettings::isConfirmSwitching() const
{
    return value("ConfirmSwitching", defaultConfirmSwitching()).toBool();
}

void AppSettings::setConfirmSwitching(bool confirm)
{
    setValue("ConfirmSwitching", confirm);
}

bool AppSettings::defaultConfirmSwitching()
{
    return true;
}

QString AppSettings::gpuIconName(DaemonClient::GPU gpu) const
{
    switch (gpu) {
    case DaemonClient::Intel:
        return value("IntelIcon", defaultTrayIconName(DaemonClient::Intel)).toString();
    case DaemonClient::Nvidia:
        return value("NvidiaIcon", defaultTrayIconName(DaemonClient::Nvidia)).toString();
    case DaemonClient::Hybrid:
        return value("HybridIcon", defaultTrayIconName(DaemonClient::Hybrid)).toString();
    }

    qFatal("Unknown GPU");
}

void AppSettings::setGpuIconName(DaemonClient::GPU gpu, const QString &name)
{
    switch (gpu) {
    case DaemonClient::Intel:
        setValue("IntelIcon", name);
        break;
    case DaemonClient::Nvidia:
        setValue("NvidiaIcon", name);
        break;
    case DaemonClient::Hybrid:
        setValue("HybridIcon", name);
    }
}

QString AppSettings::defaultTrayIconName(DaemonClient::GPU trayStatus)
{
    switch (trayStatus) {
    case DaemonClient::Intel:
        return QStringLiteral("prime-intel");
    case DaemonClient::Nvidia:
        return QStringLiteral("prime-nvidia");
    case DaemonClient::Hybrid:
        return QStringLiteral("prime-hybrid");
    }

    return QString();
}

void AppSettings::applyLocale(QLocale::Language lang)
{
    if (lang == QLocale::AnyLanguage)
        QLocale::setDefault(QLocale::system());
    else
        QLocale::setDefault(QLocale(lang));

    s_appTranslator.load(QLocale(), "optimus-manager", "_", ":/i18n");
}
