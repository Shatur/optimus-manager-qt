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

#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include "appsettings.h"
#include "daemonclient.h"
#include "optimusmanager.h"
#include "optimussettings.h"
#include "singleapplication.h"

#include <QFileDialog>
#include <QMessageBox>
#ifdef PLASMA
#include <KIconDialog>
#endif

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    connect(ui->dialogButtonBox->button(QDialogButtonBox::RestoreDefaults), &QPushButton::clicked, this, &SettingsDialog::restoreDefaults);
    ui->logoLabel->setPixmap(QIcon::fromTheme(QStringLiteral("optimus-manager")).pixmap(512, 512));
    ui->versionGuiLabel->setText(SingleApplication::applicationVersion());
    ui->versionLabel->setText(optimusManagerVersion());

    // Set languages data
    ui->languageComboBox->addItem(tr("<System language>"), QLocale::AnyLanguage);
    ui->languageComboBox->addItem(QIcon(QStringLiteral(":/flags/de.svg")), QStringLiteral("Deutsch"), QLocale::German);
    ui->languageComboBox->addItem(QIcon(QStringLiteral(":/flags/en.svg")), QStringLiteral("English"), QLocale::English);
    ui->languageComboBox->addItem(QIcon(QStringLiteral(":/flags/es.svg")), QStringLiteral("Español"), QLocale::Spanish);
    ui->languageComboBox->addItem(QIcon(QStringLiteral(":/flags/hu.svg")), QStringLiteral("Magyar"), QLocale::Hungarian);
    ui->languageComboBox->addItem(QIcon(QStringLiteral(":/flags/br.svg")), QStringLiteral("Português (Brasil)"), QLocale::Portuguese);
    ui->languageComboBox->addItem(QIcon(QStringLiteral(":/flags/fi.svg")), QStringLiteral("Suomalainen"), QLocale::Finnish);
    ui->languageComboBox->addItem(QIcon(QStringLiteral(":/flags/tr.svg")), QStringLiteral("Türk"), QLocale::Turkish);
    ui->languageComboBox->addItem(QIcon(QStringLiteral(":/flags/ru.svg")), QStringLiteral("Русский"), QLocale::Russian);
    ui->languageComboBox->addItem(QIcon(QStringLiteral(":/flags/cn.svg")), QStringLiteral("简体中文 (中国)"), QLocale::Chinese);

    loadAppSettings();

    auto [path, type] = OptimusSettings::detectConfigPath();
    ui->optimusConfigTypeComboBox->setCurrentIndex(type);
    ui->optimusConfigPathEdit->setText(path);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

bool SettingsDialog::isLanguageChanged() const
{
    return m_languageChanged;
}

void SettingsDialog::accept()
{
    // Check Optimus Manager config path
    const QString configPath = configurationPath();
    if (configPath.isEmpty()) {
        QMessageBox message;
        message.setIcon(QMessageBox::Critical);
        message.setText(tr("Optimus Manager temporary configuration file path cannot be empty"));
        message.exec();
        return;
    }
    if (configPath == OptimusSettings::permanentConfigPath()) {
        QMessageBox message;
        message.setIcon(QMessageBox::Critical);
        message.setText(tr("Optimus Manager temporary configuration file path cannot be a permanent configuration file path"));
        message.exec();
        return;
    }

    saveOptimusSettings(configPath);

    DaemonClient client;
    client.connect();
    if (client.error()) {
        QMessageBox message;
        message.setIcon(QMessageBox::Critical);
        message.setText(DaemonClient::tr("Unable to connect to Optimus Manager daemon: %1").arg(client.errorString()));
        message.exec();
        return;
    }

    if (ui->optimusConfigTypeComboBox->currentIndex() == OptimusSettings::Permanent) {
        QFile configFile(configPath);
        if (!configFile.open(QIODevice::ReadOnly)) {
            QMessageBox message;
            message.setIcon(QMessageBox::Critical);
            message.setText(tr("Unable to read data from generated configuration"));
            message.exec();
            return;
        }

        QTextStream configStream(&configFile);
        const QString configData = configStream.readAll();
        configFile.remove();

        client.setConfig(configData);
        client.setTempConfig({});
    } else {
        client.setTempConfig(configPath);
    }

    if (client.error()) {
        QMessageBox message;
        message.setIcon(QMessageBox::Critical);
        message.setText(DaemonClient::tr("Unable to send configuration file to Optimus Manager daemon: %1").arg(client.errorString()));
        message.exec();
        return;
    }

    saveAppSettings();

    QDialog::accept();
}

void SettingsDialog::browseIntelIcon()
{
    browseIcon(ui->intelIconEdit);
}

void SettingsDialog::browseNvidiaIcon()
{
    browseIcon(ui->nvidiaIconEdit);
}

void SettingsDialog::browseHybridIcon()
{
    browseIcon(ui->hybridIconEdit);
}

void SettingsDialog::previewIntelIcon(const QString &fileName)
{
    const QIcon icon = OptimusManager::trayGpuIcon(fileName);
    ui->intelIconButton->setIcon(icon);
}

void SettingsDialog::previewNvidiaIcon(const QString &fileName)
{
    const QIcon icon = OptimusManager::trayGpuIcon(fileName);
    ui->nvidiaIconButton->setIcon(icon);
}

void SettingsDialog::previewHybridIcon(const QString &fileName)
{
    const QIcon icon = OptimusManager::trayGpuIcon(fileName);
    ui->hybridIconButton->setIcon(icon);
}

void SettingsDialog::disableAutoStartupModes(int startupMode)
{
    if (startupMode == OptimusSettings::Auto) {
        ui->batteryStartupModeComboBox->setEnabled(true);
        ui->batteryStartupModeLabel->setEnabled(true);
        ui->externalPowerStartupModeComboBox->setEnabled(true);
        ui->externalPowerStartupModeLabel->setEnabled(true);
    } else {
        ui->batteryStartupModeComboBox->setEnabled(false);
        ui->batteryStartupModeLabel->setEnabled(false);
        ui->externalPowerStartupModeComboBox->setEnabled(false);
        ui->externalPowerStartupModeLabel->setEnabled(false);
    }
}

void SettingsDialog::disableSwitchingMethodIgnored(int switchingMethod)
{
    switch (switchingMethod) {
    case OptimusSettings::NoneMethod:
        ui->pciPowerControlCheckBox->setEnabled(true);
        ui->intelModesetCheckBox->setEnabled(false);
        if (ui->pciResetComboBox->currentIndex() != OptimusSettings::HotReset)
            ui->pciRemoveCheckBox->setEnabled(true); // Can be disabled by Hot reset option
        break;
    case OptimusSettings::Nouveau:
        ui->pciPowerControlCheckBox->setEnabled(true);
        ui->intelModesetCheckBox->setEnabled(true);
        ui->pciRemoveCheckBox->setEnabled(false);
        break;
    case OptimusSettings::Bbswitch:
        ui->pciPowerControlCheckBox->setEnabled(false);
        ui->intelModesetCheckBox->setEnabled(false);
        ui->pciRemoveCheckBox->setEnabled(false);
        break;
    case OptimusSettings::AcpiCall:
        ui->pciPowerControlCheckBox->setEnabled(false);
        ui->intelModesetCheckBox->setEnabled(false);
        if (ui->pciResetComboBox->currentIndex() != OptimusSettings::HotReset)
            ui->pciRemoveCheckBox->setEnabled(true);
    }
}

void SettingsDialog::disablePciResetIgnored(int pciResetType)
{
    if (pciResetType == OptimusSettings::HotReset)
        ui->pciRemoveCheckBox->setEnabled(false);
    else if (ui->switchingMethodComboBox->currentIndex() != OptimusSettings::Bbswitch && ui->switchingMethodComboBox->currentIndex() != OptimusSettings::Nouveau)
        ui->pciRemoveCheckBox->setEnabled(true); // Can be disabled by switching method
}

void SettingsDialog::disableIntelDriverIgnored(int intelDriver)
{
    if (intelDriver == OptimusSettings::IntelDriver) {
        ui->intelAccelMethodComboBox->setEnabled(true);
        ui->intelTearFreeComboBox->setEnabled(true);
    } else {
        ui->intelAccelMethodComboBox->setEnabled(false);
        ui->intelTearFreeComboBox->setEnabled(false);
    }
}

void SettingsDialog::loadOptimusConfigType(int configType)
{
    if (configType == OptimusSettings::Permanent) {
        ui->optimusConfigPathEdit->setText(OptimusSettings::permanentConfigPath());
        ui->optimusConfigPathEdit->setEnabled(false);
        ui->optimusConfigPathLabel->setEnabled(false);
        ui->browseOptimusConfigButton->setEnabled(false);
    } else {
        ui->optimusConfigPathEdit->clear();
        ui->optimusConfigPathEdit->setEnabled(true);
        ui->optimusConfigPathLabel->setEnabled(true);
        ui->browseOptimusConfigButton->setEnabled(true);
    }
}

void SettingsDialog::browseTempConfigPath()
{
    QFileDialog dialog(this, tr("Select temporary configuration file"));
    dialog.setNameFilter(tr("Config files (*.conf);;All files(*)"));

    const QFileInfo previousName = ui->optimusConfigPathEdit->text();
    dialog.setDirectory(previousName.exists() ? previousName.path() : QDir::homePath());

    if (dialog.exec() == QDialog::Accepted)
        ui->optimusConfigPathEdit->setText(dialog.selectedFiles().constFirst());
}

void SettingsDialog::exportOptimusConfig()
{
    QFileDialog dialog(this, tr("Export Optimus Manager settings"));
    dialog.setNameFilter(tr("Config files (*.conf);;All files(*)"));
    dialog.setAcceptMode(QFileDialog::AcceptSave);

    const QFileInfo previousName = ui->optimusConfigPathEdit->text();
    dialog.setDirectory(previousName.exists() ? previousName.path() : QDir::homePath());

    if (dialog.exec() == QDialog::Accepted)
        saveOptimusSettings(dialog.selectedFiles().constFirst());
}

void SettingsDialog::importOptimusConfig()
{
    QFileDialog dialog(this, tr("Import Optimus Manager settings"));
    dialog.setNameFilter(tr("Config files (*.conf);;All files(*)"));
    dialog.setFileMode(QFileDialog::ExistingFile);

    const QFileInfo previousName = ui->optimusConfigPathEdit->text();
    dialog.setDirectory(previousName.exists() ? previousName.path() : QDir::homePath());

    if (dialog.exec() == QDialog::Accepted)
        loadOptimusSettings(dialog.selectedFiles().constFirst());
}

void SettingsDialog::loadOptimusSettingsPath(const QString &path)
{
    ui->exportOptimusConfigButton->setEnabled(!path.isEmpty());
    ui->importOptimusConfigButton->setEnabled(!path.isEmpty());

    loadOptimusSettings(path);
}

void SettingsDialog::restoreDefaults()
{
    // General settings
    ui->languageComboBox->setCurrentIndex(AppSettings::defaultLanguage());
    ui->autostartCheckBox->setChecked(AppSettings::defaultAutostartEnabled());
    ui->confirmSwitchingCheckBox->setChecked(AppSettings::defaultConfirmSwitching());
    ui->intelIconEdit->setText(AppSettings::defaultTrayIconName(OptimusSettings::Intel));
    ui->nvidiaIconEdit->setText(AppSettings::defaultTrayIconName(OptimusSettings::Nvidia));
    ui->hybridIconEdit->setText(AppSettings::defaultTrayIconName(OptimusSettings::Hybrid));

    // Configuration files settings
    ui->optimusConfigTypeComboBox->setCurrentIndex(OptimusSettings::defaultConfigType());

    // Optimus settings
    ui->startupModeComboBox->setCurrentIndex(OptimusSettings::defaultStartupMode());
    ui->switchingMethodComboBox->setCurrentIndex(OptimusSettings::defaultSwitchingMethod());
    ui->pciResetComboBox->setCurrentIndex(OptimusSettings::defaultPciReset());
    ui->pciPowerControlCheckBox->setChecked(OptimusSettings::defaultPciPowerControlEnabled());
    ui->pciRemoveCheckBox->setChecked(OptimusSettings::defaultPciRemoveEnabled());
    ui->autoLogoutCheckBox->setChecked(OptimusSettings::defaultAutoLogoutEnabled());

    // Intel settings
    ui->intelDriverComboBox->setCurrentIndex(OptimusSettings::defaultIntelDriver());
    ui->intelAccelMethodComboBox->setCurrentIndex(OptimusSettings::defaultIntelAccelMethod());
    ui->intelTearFreeComboBox->setCurrentIndex(OptimusSettings::defaultIntelTearFree());
    ui->intelDriComboBox->setCurrentIndex(OptimusSettings::defaultIntelDri());
    ui->intelModesetCheckBox->setChecked(OptimusSettings::defaultIntelModesetEnabled());

    // Nvidia settings
    ui->nvidiaDpiSpinBox->setValue(OptimusSettings::defaultNvidiaDpi());
    ui->nvidiaModesetCheckBox->setChecked(OptimusSettings::defaultNvidiaModesetEnabled());
    ui->nvidiaPatCheckBox->setChecked(OptimusSettings::defaultNvidiaPatEnabled());
    ui->nvidiaIgnoreAbiCheckBox->setChecked(OptimusSettings::defaultNvidiaIgnoreAbi());
    ui->nvidiaAllowExternalGpusCheckBox->setChecked(OptimusSettings::defaultNvidiaAllowExternalGpus());

    const OptimusSettings::NvidiaOptions nvidiaOptions = OptimusSettings::defaultNvidiaOptions();
    ui->nvidiaOverclockingCheckBox->setChecked(nvidiaOptions.testFlag(OptimusSettings::Overclocking));
    ui->nvidiaTripleBuffercheckBox->setChecked(nvidiaOptions.testFlag(OptimusSettings::TripleBuffer));
}

void SettingsDialog::loadAppSettings()
{
    // General settings
    const AppSettings settings;
    ui->languageComboBox->setCurrentIndex(ui->languageComboBox->findData(settings.language()));
    ui->autostartCheckBox->setChecked(AppSettings::isAutostartEnabled());
    ui->confirmSwitchingCheckBox->setChecked(settings.isConfirmSwitching());
    ui->intelIconEdit->setText(settings.gpuIconName(OptimusSettings::Intel));
    ui->nvidiaIconEdit->setText(settings.gpuIconName(OptimusSettings::Nvidia));
    ui->hybridIconEdit->setText(settings.gpuIconName(OptimusSettings::Hybrid));
}

void SettingsDialog::saveAppSettings()
{
    // Check if language changed
    AppSettings appSettings;
    const auto language = ui->languageComboBox->currentData().value<QLocale::Language>();
    if (language != appSettings.language()) {
        appSettings.setLanguage(language);
        m_languageChanged = true;
    }

    // General settings
    AppSettings::setAutostartEnabled(ui->autostartCheckBox->isChecked());
    appSettings.setConfirmSwitching(ui->confirmSwitchingCheckBox->isChecked());
    appSettings.setGpuIconName(OptimusSettings::Intel, ui->intelIconEdit->text());
    appSettings.setGpuIconName(OptimusSettings::Nvidia, ui->nvidiaIconEdit->text());
    appSettings.setGpuIconName(OptimusSettings::Hybrid, ui->hybridIconEdit->text());
}

void SettingsDialog::loadOptimusSettings(const QString &path)
{
    // Optimus settings
    const OptimusSettings optimusSettings(path);
    ui->switchingMethodComboBox->setCurrentIndex(optimusSettings.switchingMethod());
    ui->pciResetComboBox->setCurrentIndex(optimusSettings.pciReset());
    ui->pciPowerControlCheckBox->setChecked(optimusSettings.isPciPowerControlEnabled());
    ui->pciRemoveCheckBox->setChecked(optimusSettings.isPciRemoveEnabled());
    ui->autoLogoutCheckBox->setChecked(optimusSettings.isAutoLogoutEnabled());
    ui->startupModeComboBox->setCurrentIndex(optimusSettings.startupMode());
    ui->batteryStartupModeComboBox->setCurrentIndex(optimusSettings.batteryStartupMode());
    ui->externalPowerStartupModeComboBox->setCurrentIndex(optimusSettings.externalPowerStartupMode());

    // Intel settings
    ui->intelDriverComboBox->setCurrentIndex(optimusSettings.intelDriver());
    ui->intelAccelMethodComboBox->setCurrentIndex(optimusSettings.intelAccelMethod());
    ui->intelTearFreeComboBox->setCurrentIndex(optimusSettings.intelTearFree());
    ui->intelDriComboBox->setCurrentText(QString::number(optimusSettings.intelDri()));
    ui->intelModesetCheckBox->setChecked(optimusSettings.isIntelModesetEnabled());

    // Nvidia settings
    ui->nvidiaDpiSpinBox->setValue(optimusSettings.nvidiaDpi());
    ui->nvidiaModesetCheckBox->setChecked(optimusSettings.isNvidiaModesetEnabled());
    ui->nvidiaPatCheckBox->setChecked(optimusSettings.isNvidiaPatEnabled());
    ui->nvidiaIgnoreAbiCheckBox->setChecked(optimusSettings.isNvidiaIgnoreAbi());
    ui->nvidiaAllowExternalGpusCheckBox->setChecked(optimusSettings.isNvidiaAllowExternalGpus());

    const OptimusSettings::NvidiaOptions nvidiaOptions = optimusSettings.nvidiaOptions();
    ui->nvidiaOverclockingCheckBox->setChecked(nvidiaOptions.testFlag(OptimusSettings::Overclocking));
    ui->nvidiaTripleBuffercheckBox->setChecked(nvidiaOptions.testFlag(OptimusSettings::TripleBuffer));
}

void SettingsDialog::saveOptimusSettings(const QString &path) const
{
    // Optimus settings
    OptimusSettings optimusSettings(path);
    optimusSettings.setSwitchingMethod(static_cast<OptimusSettings::SwitchingMethod>(ui->switchingMethodComboBox->currentIndex()));
    optimusSettings.setPciReset(static_cast<OptimusSettings::PciReset>(ui->pciResetComboBox->currentIndex()));
    optimusSettings.setPciPowerControlEnabled(ui->pciPowerControlCheckBox->isChecked());
    optimusSettings.setPciRemoveEnabled(ui->pciRemoveCheckBox->isChecked());
    optimusSettings.setAutoLogoutEnabled(ui->autoLogoutCheckBox->isChecked());
    optimusSettings.setStartupMode(static_cast<OptimusSettings::GPU>(ui->startupModeComboBox->currentIndex()));
    optimusSettings.setBatteryStartupMode(static_cast<OptimusSettings::GPU>(ui->batteryStartupModeComboBox->currentIndex()));
    optimusSettings.setExternalPowerStartupMode(static_cast<OptimusSettings::GPU>(ui->externalPowerStartupModeComboBox->currentIndex()));

    // Intel settings
    optimusSettings.setIntelDriver(static_cast<OptimusSettings::Driver>(ui->intelDriverComboBox->currentIndex()));
    optimusSettings.setIntelAccelMethod(static_cast<OptimusSettings::AccelMethod>(ui->intelAccelMethodComboBox->currentIndex()));
    optimusSettings.setIntelTearFree(static_cast<OptimusSettings::TearFree>(ui->intelTearFreeComboBox->currentIndex()));
    optimusSettings.setIntelDri(static_cast<OptimusSettings::DRI>(ui->intelDriComboBox->currentText().toInt()));
    optimusSettings.setIntelModesetEnabled(ui->intelModesetCheckBox->isChecked());

    // Nvidia settings
    optimusSettings.setNvidiaDpi(ui->nvidiaDpiSpinBox->value());
    optimusSettings.setNvidiaModesetEnabled(ui->nvidiaModesetCheckBox->isChecked());
    optimusSettings.setNvidiaPatEnabled(ui->nvidiaPatCheckBox->isChecked());
    optimusSettings.setNvidiaIgnoreAbi(ui->nvidiaIgnoreAbiCheckBox->isChecked());
    optimusSettings.setNvidiaAllowExternalGpus(ui->nvidiaAllowExternalGpusCheckBox->isChecked());

    OptimusSettings::NvidiaOptions nvidiaOptions;
    nvidiaOptions.setFlag(OptimusSettings::Overclocking, ui->nvidiaOverclockingCheckBox->isChecked());
    nvidiaOptions.setFlag(OptimusSettings::TripleBuffer, ui->nvidiaTripleBuffercheckBox->isChecked());
    optimusSettings.setNvidiaOptions(nvidiaOptions);
}

void SettingsDialog::browseIcon(QLineEdit *iconNameEdit)
{
#ifdef PLASMA
    KIconDialog dialog(this);
    dialog.setup(KIconLoader::Panel, KIconLoader::StatusIcon);

    const QString iconName = dialog.openDialog();
    if (!iconName.isEmpty())
        iconNameEdit->setText(iconName);
#else
    QFileDialog dialog(this, tr("Select icon"));
    dialog.setNameFilter(tr("Images (*.png *.jpg *.bmp);;All files(*)"));
    dialog.setFileMode(QFileDialog::ExistingFile);

    const QFileInfo previousName = iconNameEdit->text();
    dialog.setDirectory(previousName.exists() ? previousName.path() : QDir::homePath());

    if (dialog.exec() == QDialog::Accepted)
        iconNameEdit->setText(dialog.selectedFiles().constFirst());
#endif
}

QString SettingsDialog::configurationPath() const
{
    if (ui->optimusConfigTypeComboBox->currentIndex() == OptimusSettings::Permanent) {
        // Create a temporary file that will be used for sending to the daemon
        const QString path = QDir::tempPath() + QStringLiteral("/optimus-manager.conf");
        QFile::copy(OptimusSettings::permanentConfigPath(), path);
        return path;
    }

    return ui->optimusConfigPathEdit->text();
}

// Parse Optimus Manager version
QString SettingsDialog::optimusManagerVersion()
{
    // Parse Optimus Manager version
    QFile optimusManagerBin(QStringLiteral("/usr/bin/optimus-manager-daemon"));
    if (!optimusManagerBin.open(QIODevice::ReadOnly)) {
        QMessageBox message;
        message.setIcon(QMessageBox::Critical);
        message.setText(tr("Unable to find Optimus Manager daemon."));
        message.setInformativeText(tr("Please check the integrity of the package that provides Optimus Manager."));
        message.exec();
        return tr("Not found!");
    }

    const QByteArray data = optimusManagerBin.readAll();
    const QByteArray optimusManagerString = "optimus-manager==";
    const int versionStartIndex = data.indexOf(optimusManagerString) + optimusManagerString.size();
    const int versionEndIndex = data.indexOf('\'', versionStartIndex);

    return data.mid(versionStartIndex, versionEndIndex - versionStartIndex);
}
