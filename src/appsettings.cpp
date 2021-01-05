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

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QGuiApplication>
#include <QStandardPaths>
#include <QTranslator>

QTranslator AppSettings::s_appTranslator;

AppSettings::AppSettings(QObject *parent)
    : QSettings(parent)
{
}

void AppSettings::setupLocalization() const
{
    applyLanguage(language());
    QCoreApplication::installTranslator(&s_appTranslator);
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
    applyLanguage(lang);
}

QLocale::Language AppSettings::defaultLanguage()
{
    return QLocale::AnyLanguage;
}

bool AppSettings::isAutostartEnabled()
{
    return QFileInfo::exists(QStringLiteral("%1/autostart/%2").arg(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation), QGuiApplication::desktopFileName()));
}

void AppSettings::setAutostartEnabled(bool enabled)
{
    QDir autostartDir(QStringLiteral("%1/autostart").arg(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation)));

    if (enabled) {
        // Create autorun file
        if (autostartDir.exists(QGuiApplication::desktopFileName()))
            return;

        if (!autostartDir.exists()) {
            if (!autostartDir.mkpath(QStringLiteral("."))) {
                qCritical() << tr("Unable to create %1").arg(autostartDir.path());
                return;
            }
        }

        const QString desktopFileName = QStringLiteral("/usr/share/applications/%1").arg(QGuiApplication::desktopFileName());
        if (!QFile::copy(desktopFileName, autostartDir.filePath(QGuiApplication::desktopFileName())))
            qCritical() << tr("Unable to copy %1 to %2").arg(desktopFileName, autostartDir.path());
    } else if (autostartDir.exists(QGuiApplication::desktopFileName())) {
        // Remove autorun file
        if (!autostartDir.remove(QGuiApplication::desktopFileName()))
            qCritical() << tr("Unable to remove %1 from %2").arg(QGuiApplication::desktopFileName(), autostartDir.path());
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

QString AppSettings::gpuIconName(Gpu gpu) const
{
    switch (gpu) {
    case IntelGpu:
        return value(QStringLiteral("IntelIcon"), defaultTrayIconName(IntelGpu)).toString();
    case AmdGpu:
        return value(QStringLiteral("AmdIcon"), defaultTrayIconName(AmdGpu)).toString();
    case NvidiaGpu:
        return value(QStringLiteral("NvidiaIcon"), defaultTrayIconName(NvidiaGpu)).toString();
    case HybridGpu:
        return value(QStringLiteral("HybridIcon"), defaultTrayIconName(HybridGpu)).toString();
    default:
        qFatal("Unknown GPU");
    }
}

void AppSettings::setGpuIconName(Gpu gpu, const QString &name)
{
    switch (gpu) {
    case IntelGpu:
        setValue(QStringLiteral("IntelIcon"), name);
        break;
    case AmdGpu:
        setValue(QStringLiteral("AmdIcon"), name);
        break;
    case NvidiaGpu:
        setValue(QStringLiteral("NvidiaIcon"), name);
        break;
    case HybridGpu:
        setValue(QStringLiteral("HybridIcon"), name);
        break;
    default:
        qFatal("Unknown GPU");
    }
}

QString AppSettings::defaultTrayIconName(Gpu trayStatus)
{
    switch (trayStatus) {
    case AmdGpu:
        return QStringLiteral("prime-amd");
    case IntelGpu:
        return QStringLiteral("prime-intel");
    case NvidiaGpu:
        return QStringLiteral("prime-nvidia");
    case HybridGpu:
        return QStringLiteral("prime-hybrid");
    default:
        qFatal("Unknown GPU");
    }
}

void AppSettings::applyLanguage(QLocale::Language lang)
{
    const QLocale locale = lang == QLocale::AnyLanguage ? QLocale::system() : lang;
    QLocale::setDefault(locale);
    s_appTranslator.load(locale, QStringLiteral(PROJECT_NAME), QStringLiteral("_"), QStandardPaths::locate(QStandardPaths::AppDataLocation, QStringLiteral("translations"), QStandardPaths::LocateDirectory));
}
