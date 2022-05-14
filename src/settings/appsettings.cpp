/*
 *  Copyright © 2019-2022 Hennadii Chernyshchyk <genaloner@gmail.com>
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

#include "appsettings.h"

#include "cmake.h"

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QGuiApplication>
#include <QIcon>
#include <QLibraryInfo>
#include <QSettings>
#include <QStandardPaths>
#include <QTranslator>

QTranslator AppSettings::s_appTranslator;
QTranslator AppSettings::s_qtTranslator;

AppSettings::AppSettings(QObject *parent)
    : QObject(parent)
    , m_settings(new QSettings(this))
{
}

void AppSettings::setupLocalization() const
{
    applyLocale(locale());
    QCoreApplication::installTranslator(&s_appTranslator);
    QCoreApplication::installTranslator(&s_qtTranslator);
}

QLocale AppSettings::locale() const
{
    return m_settings->value(QStringLiteral("Locale"), defaultLocale()).value<QLocale>();
}

void AppSettings::setLocale(const QLocale &locale)
{
    m_settings->setValue(QStringLiteral("Locale"), locale);
    applyLocale(locale);
}

QLocale AppSettings::defaultLocale()
{
    return QLocale::c(); // C locale is used as the system language on apply
}

bool AppSettings::isAutostartEnabled() const
{
    return m_settings->value(QStringLiteral("AutostartEnabled"), defaultAutostartEnabled()).toBool();
}

void AppSettings::setAutostartEnabled(bool enabled)
{
    m_settings->setValue(QStringLiteral("AutostartEnabled"), enabled);
}

bool AppSettings::defaultAutostartEnabled()
{
    return false;
}

bool AppSettings::isConfirmSwitching() const
{
    return m_settings->value(QStringLiteral("ConfirmSwitching"), defaultConfirmSwitching()).toBool();
}

void AppSettings::setConfirmSwitching(bool confirm)
{
    m_settings->setValue(QStringLiteral("ConfirmSwitching"), confirm);
}

bool AppSettings::defaultConfirmSwitching()
{
    return true;
}

QIcon AppSettings::modeIcon(OptimusSettings::Mode mode) const
{
    return QIcon::fromTheme(modeIconName(mode), QIcon::fromTheme(defaultModeIconName(mode)));
}

QString AppSettings::modeIconName(OptimusSettings::Mode mode) const
{
    switch (mode) {
    case OptimusSettings::Integrated:
        return m_settings->value(QStringLiteral("IntegratedIcon"), defaultModeIconName(mode)).toString();
    case OptimusSettings::Nvidia:
        return m_settings->value(QStringLiteral("NvidiaIcon"), defaultModeIconName(mode)).toString();
    case OptimusSettings::Hybrid:
        return m_settings->value(QStringLiteral("HybridIcon"), defaultModeIconName(mode)).toString();
    default:
        qFatal("Unknown GPU");
    }
}

void AppSettings::setModeIconName(OptimusSettings::Mode mode, const QString &name)
{
    switch (mode) {
    case OptimusSettings::Integrated:
        m_settings->setValue(QStringLiteral("IntegratedIcon"), name);
        break;
    case OptimusSettings::Nvidia:
        m_settings->setValue(QStringLiteral("NvidiaIcon"), name);
        break;
    case OptimusSettings::Hybrid:
        m_settings->setValue(QStringLiteral("HybridIcon"), name);
        break;
    default:
        qFatal("Unknown GPU");
    }
}

QString AppSettings::defaultModeIconName(OptimusSettings::Mode mode)
{
    switch (mode) {
    case OptimusSettings::Integrated:
        return QStringLiteral("cpu-symbolic");
    case OptimusSettings::Nvidia:
        return QStringLiteral("prime-nvidia");
    case OptimusSettings::Hybrid:
        return QStringLiteral("prime-hybrid");
    default:
        qFatal("Unknown GPU");
    }
}

void AppSettings::applyLocale(const QLocale &locale)
{
    const QLocale newLocale = locale == defaultLocale() ? QLocale::system() : locale;
    QLocale::setDefault(newLocale);
    s_appTranslator.load(newLocale, QStringLiteral(PROJECT_NAME), QStringLiteral("_"), QStandardPaths::locate(QStandardPaths::AppDataLocation, QStringLiteral("translations"), QStandardPaths::LocateDirectory));
    s_qtTranslator.load(newLocale, QStringLiteral("qt"), QStringLiteral("_"), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
}
