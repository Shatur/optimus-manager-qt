#include "appsettings.h"
#include "singleapplication.h"

#include <QStandardPaths>
#include <QFileInfo>
#include <QDebug>
#include <QIcon>

AppSettings::AppSettings(QObject *parent) :
    QSettings(parent)
{
}

void AppSettings::initTranslator()
{
    applyLocale(locale());
    SingleApplication::installTranslator(&m_appTranslator);
}

QLocale::Language AppSettings::locale()
{
    return value("Locale", QLocale::AnyLanguage).value<QLocale::Language>();
}

void AppSettings::setLocale(QLocale::Language lang)
{
    if (lang == locale())
        return;

    setValue("Locale", lang);
    applyLocale(lang);
}

bool AppSettings::isAutostartEnabled() const
{
    return QFileInfo::exists(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/autostart/orson.desktop");
}

void AppSettings::setAutostartEnabled(bool enabled)
{
    QFile autorunFile(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/autostart/orson.desktop");

    if (enabled) {
        // Create autorun file
        if (!autorunFile.exists()) {
            constexpr char desktopFileName[] = "/usr/share/applications/optimus-manager-qt.desktop";

            if (!QFile::copy(desktopFileName, autorunFile.fileName()))
                qCritical() << tr("Unable to create autorun file from ") + desktopFileName;
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

QString AppSettings::modeIconName(OptimusManager::Mode mode) const
{
    switch (mode) {
    case OptimusManager::Intel:
        return value("IntelIcon", defaultTrayIconName(OptimusManager::Intel)).toString();
    case OptimusManager::Nvidia:
        return value("NvidiaIcon", defaultTrayIconName(OptimusManager::Nvidia)).toString();
    }

    qFatal("Unknown mode");
}

QIcon AppSettings::modeIcon(OptimusManager::Mode mode) const
{
    const QString iconName = modeIconName(mode);

    if (QIcon::hasThemeIcon(iconName))
        return QIcon::fromTheme(iconName);

    return QIcon(iconName);
}

void AppSettings::setModeIconName(OptimusManager::Mode mode, const QString &name)
{
    switch (mode) {
    case OptimusManager::Intel:
        setValue("IntelIcon", name);
        break;
    case OptimusManager::Nvidia:
        setValue("NvidiaIcon", name);
        break;
    }
}

void AppSettings::applyLocale(QLocale::Language lang)
{
    if (lang == QLocale::AnyLanguage)
        QLocale::setDefault(QLocale::system());
    else
        QLocale::setDefault(QLocale(lang));

    m_appTranslator.load(QLocale(), "optimus-manager", "_", ":/translations");
}
