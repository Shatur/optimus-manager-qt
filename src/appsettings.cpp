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

#include "appsettings.h"

#include "cmake.h"
#include "singleapplication.h"

#include <QFileInfo>
#include <QStandardPaths>
#include <QTranslator>

QTranslator AppSettings::s_appTranslator;

AppSettings::AppSettings(QObject *parent)
    : QSettings(parent)
{
}

void AppSettings::setupLocalization() const
{
    loadLanguage(language());
    SingleApplication::installTranslator(&s_appTranslator);
}

QLocale::Language AppSettings::language() const
{
    return value(QStringLiteral("Language"), defaultLanguage()).value<QLocale::Language>();
}

void AppSettings::setLanguage(QLocale::Language lang)
{
    if (lang == language())
        return;

    setValue(QStringLiteral("Language"), lang);
    loadLanguage(lang);
}

QLocale::Language AppSettings::defaultLanguage()
{
    return QLocale::AnyLanguage;
}

bool AppSettings::isAutostartEnabled()
{
    return QFileInfo::exists(QStringLiteral("%1/autostart/%2").arg(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation)));
}

void AppSettings::setAutostartEnabled(bool enabled)
{
    QFile autorunFile(QStringLiteral("%1/autostart/%2").arg(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation)));

    if (enabled) {
        // Create autorun file
        if (!autorunFile.exists()) {
            const QString desktopFileName = QStringLiteral("/usr/share/applications/%1").arg(SingleApplication::desktopFileName());

            if (!QFile::copy(desktopFileName, autorunFile.fileName()))
                qCritical() << tr("Unable to create autorun file from '%1'").arg(desktopFileName);
        }
    } else {
        // Remove autorun file
        if (autorunFile.exists())
            autorunFile.remove();
    }
}

bool AppSettings::defaultAutostartEnabled()
{
    return false;
}

bool AppSettings::isConfirmSwitching() const
{
    return value(QStringLiteral("ConfirmSwitching"), defaultConfirmSwitching()).toBool();
}

void AppSettings::setConfirmSwitching(bool confirm)
{
    setValue(QStringLiteral("ConfirmSwitching"), confirm);
}

bool AppSettings::defaultConfirmSwitching()
{
    return true;
}

QString AppSettings::gpuIconName(OptimusSettings::GPU gpu) const
{
    switch (gpu) {
    case OptimusSettings::Integrated:
        return value(QStringLiteral("IntegratedIcon"), defaultTrayIconName(OptimusSettings::Integrated)).toString();
    case OptimusSettings::Nvidia:
        return value(QStringLiteral("NvidiaIcon"), defaultTrayIconName(OptimusSettings::Nvidia)).toString();
    case OptimusSettings::Hybrid:
        return value(QStringLiteral("HybridIcon"), defaultTrayIconName(OptimusSettings::Hybrid)).toString();
    default:
        qFatal("Unknown GPU");
    }
}

void AppSettings::setGpuIconName(OptimusSettings::GPU gpu, const QString &name)
{
    switch (gpu) {
    case OptimusSettings::Integrated:
        setValue(QStringLiteral("IntegratedIcon"), name);
        break;
    case OptimusSettings::Nvidia:
        setValue(QStringLiteral("NvidiaIcon"), name);
        break;
    case OptimusSettings::Hybrid:
        setValue(QStringLiteral("HybridIcon"), name);
        break;
    default:
        qFatal("Unknown GPU");
    }
}

QString AppSettings::defaultTrayIconName(OptimusSettings::GPU trayStatus)
{
    switch (trayStatus) {
    case OptimusSettings::Integrated:
        return QStringLiteral("prime-integrated");
    case OptimusSettings::Nvidia:
        return QStringLiteral("prime-nvidia");
    case OptimusSettings::Hybrid:
        return QStringLiteral("prime-hybrid");
    default:
        qFatal("Unknown GPU");
    }
}

void AppSettings::loadLanguage(QLocale::Language lang)
{
    if (lang == QLocale::AnyLanguage)
        QLocale::setDefault(QLocale::system());
    else
        QLocale::setDefault(QLocale(lang));

    s_appTranslator.load(QLocale(), QStringLiteral(PROJECT_NAME), QStringLiteral("_"), QStandardPaths::locate(QStandardPaths::AppDataLocation, QStringLiteral("translations"), QStandardPaths::LocateDirectory));
}
