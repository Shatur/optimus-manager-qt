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

#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "appsettings.h"
#include "optimusmanager.h"
#include "optimussettings.h"
#include "singleapplication.h"

#include <QFileDialog>
#include <QStandardItemModel>
#include <QPushButton>
#include <QMessageBox>
#include <QTemporaryFile>
#ifdef PLASMA
#include <KIconDialog>
#endif

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    connect(ui->dialogButtonBox->button(QDialogButtonBox::RestoreDefaults), &QPushButton::clicked, this, &SettingsDialog::restoreDefaults);
    ui->logoLabel->setPixmap(QIcon::fromTheme("optimus-manager").pixmap(512, 512));
    ui->versionGuiLabel->setText(SingleApplication::applicationVersion());
    ui->versionLabel->setText(optimusManagerVersion());

    // Set languages data
    ui->languageComboBox->setItemData(0, QLocale::AnyLanguage);
    ui->languageComboBox->setItemData(1, QLocale::Chinese);
    ui->languageComboBox->setItemData(2, QLocale::English);
    ui->languageComboBox->setItemData(3, QLocale::Finnish);
    ui->languageComboBox->setItemData(4, QLocale::German);
    ui->languageComboBox->setItemData(5, QLocale::Portuguese);
    ui->languageComboBox->setItemData(6, QLocale::Russian);
    ui->languageComboBox->setItemData(7, QLocale::Spanish);
    ui->languageComboBox->setItemData(8, QLocale::Turkish);

    loadSettings();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

bool SettingsDialog::languageChanged() const
{
    return m_languageChanged;
}

void SettingsDialog::accept()
{
    // Check if language changed
    AppSettings appSettings;
    const auto language = ui->languageComboBox->currentData().value<QLocale::Language>();
    if (language != appSettings.language()) {
        appSettings.setLocale(language);
        m_languageChanged = true;
    }

    // General settings
    appSettings.setAutostartEnabled(ui->autostartCheckBox->isChecked());
    appSettings.setConfirmSwitching(ui->confirmSwitchingCheckBox->isChecked());
    appSettings.setGpuIconName(DaemonClient::Intel, ui->intelIconEdit->text());
    appSettings.setGpuIconName(DaemonClient::Nvidia, ui->nvidiaIconEdit->text());
    appSettings.setGpuIconName(DaemonClient::Hybrid, ui->hybridIconEdit->text());

    QString optimusConfigPath;
    QTemporaryFile temporaryFile;
    if (ui->optimusConfigTypeComboBox->currentIndex() == OptimusSettings::Permanent) {
        temporaryFile.open();
        QFile::copy(OptimusSettings::permanentConfigPath(), temporaryFile.fileName());
        optimusConfigPath = temporaryFile.fileName();
    } else {
        optimusConfigPath = ui->optimusConfigPathEdit->text();
    }

    // Optimus settings
    OptimusSettings optimusSettings(optimusConfigPath);
    optimusSettings.setSwitchingMethod(static_cast<OptimusSettings::SwitchingMethod>(ui->switchingMethodComboBox->currentIndex()));
    optimusSettings.setPciReset(static_cast<OptimusSettings::PciReset>(ui->pciResetComboBox->currentIndex()));
    optimusSettings.setPciPowerControlEnabled(ui->pciPowerControlCheckBox->isChecked());
    optimusSettings.setPciRemoveEnabled(ui->pciRemoveCheckBox->isChecked());
    optimusSettings.setAutoLogoutEnabled(ui->autoLogoutCheckBox->isChecked());

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

    OptimusSettings::NvidiaOptions nvidiaOptions;
    nvidiaOptions.setFlag(OptimusSettings::Overclocking, ui->nvidiaOverclockingCheckBox->isChecked());
    nvidiaOptions.setFlag(OptimusSettings::TripleBuffer, ui->nvidiaTripleBuffercheckBox->isChecked());
    optimusSettings.setNvidiaOptions(nvidiaOptions);

    DaemonClient client;
    client.connect();
    if (client.error()) {
        QMessageBox message;
        message.setIcon(QMessageBox::Warning);
        message.setText(DaemonClient::tr("Unable to connect to Optimus Manager daemon: %1").arg(client.errorString()));
        message.exec();
        return;
    }

    optimusSettings.sync();
    if (ui->optimusConfigTypeComboBox->currentIndex() == OptimusSettings::Permanent) {
        client.setConfig(optimusSettings.fileName());
        client.setTempConfig({});
    } else {
        client.setTempConfig(optimusSettings.fileName());
    }
    if (client.error()) {
        QMessageBox message;
        message.setIcon(QMessageBox::Warning);
        message.setText(DaemonClient::tr("Unable to send configuration file to Optimus Manager daemon: %1").arg(client.errorString()));
        message.exec();
        return;
    }

    client.setStartupMode(static_cast<DaemonClient::GPU>(ui->startupModeComboBox->currentIndex()));
    if (client.error()) {
        QMessageBox message;
        message.setIcon(QMessageBox::Warning);
        message.setText(DaemonClient::tr("Unable to send startup mode to Optimus Manager daemon: %1").arg(client.errorString()));
        message.exec();
        return;
    }

    QDialog::accept();
}

void SettingsDialog::restoreDefaults()
{
    // General settings
    ui->languageComboBox->setCurrentIndex(AppSettings::defaultLocale());
    ui->autostartCheckBox->setChecked(AppSettings::defaultAutostartEnabled());
    ui->confirmSwitchingCheckBox->setChecked(AppSettings::defaultConfirmSwitching());
    ui->intelIconEdit->setText(AppSettings::defaultTrayIconName(DaemonClient::Intel));
    ui->nvidiaIconEdit->setText(AppSettings::defaultTrayIconName(DaemonClient::Nvidia));
    ui->hybridIconEdit->setText(AppSettings::defaultTrayIconName(DaemonClient::Hybrid));

    // Optimus settings
    ui->startupModeComboBox->setCurrentIndex(DaemonClient::defaultStartupMode());
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

    const OptimusSettings::NvidiaOptions nvidiaOptions = OptimusSettings::defaultNvidiaOptions();
    ui->nvidiaOverclockingCheckBox->setChecked(nvidiaOptions.testFlag(OptimusSettings::Overclocking));
    ui->nvidiaTripleBuffercheckBox->setChecked(nvidiaOptions.testFlag(OptimusSettings::TripleBuffer));
}

void SettingsDialog::loadSettings()
{
    // General settings
    const AppSettings settings;
    ui->languageComboBox->setCurrentIndex(ui->languageComboBox->findData(settings.language()));
    ui->autostartCheckBox->setChecked(settings.isAutostartEnabled());
    ui->confirmSwitchingCheckBox->setChecked(settings.isConfirmSwitching());
    ui->intelIconEdit->setText(settings.gpuIconName(DaemonClient::Intel));
    ui->nvidiaIconEdit->setText(settings.gpuIconName(DaemonClient::Nvidia));
    ui->hybridIconEdit->setText(settings.gpuIconName(DaemonClient::Hybrid));

    // Configuration files settings
    ui->startupModeComboBox->setCurrentIndex(DaemonClient::startupMode());

    auto [path, type] = OptimusSettings::detectConfigPath();
    ui->optimusConfigTypeComboBox->setCurrentIndex(type);
    ui->optimusConfigPathEdit->setText(path);
}

void SettingsDialog::browseIntelIcon()
{
    chooseIcon(ui->intelIconEdit);
}

void SettingsDialog::browseNvidiaIcon()
{
    chooseIcon(ui->nvidiaIconEdit);
}

void SettingsDialog::browseHybridIcon()
{
    chooseIcon(ui->hybridIconEdit);
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

void SettingsDialog::disableSwitchingMethodIgnored(int index)
{
    switch (index) {
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
        break;
    }
}

void SettingsDialog::disablePciResetIgnored(int index)
{
    if (index == OptimusSettings::HotReset)
        ui->pciRemoveCheckBox->setEnabled(false);
    else if (ui->switchingMethodComboBox->currentIndex() != OptimusSettings::Bbswitch && ui->switchingMethodComboBox->currentIndex() != OptimusSettings::Nouveau)
        ui->pciRemoveCheckBox->setEnabled(true); // Can be disabled by switching method
}

void SettingsDialog::disableIntelDriverIgnored(int index)
{
    if (index == OptimusSettings::IntelDriver) {
        ui->intelAccelMethodComboBox->setEnabled(true);
        ui->intelTearFreeComboBox->setEnabled(true);
    } else {
        ui->intelAccelMethodComboBox->setEnabled(false);
        ui->intelTearFreeComboBox->setEnabled(false);
    }
}

void SettingsDialog::disableOptimusPath(int configType)
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

    if (dialog.exec())
        ui->optimusConfigPathEdit->setText(dialog.selectedFiles().first());
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

    const OptimusSettings::NvidiaOptions nvidiaOptions = optimusSettings.nvidiaOptions();
    ui->nvidiaOverclockingCheckBox->setChecked(nvidiaOptions.testFlag(OptimusSettings::Overclocking));
    ui->nvidiaTripleBuffercheckBox->setChecked(nvidiaOptions.testFlag(OptimusSettings::TripleBuffer));
}

void SettingsDialog::chooseIcon(QLineEdit *iconNameEdit)
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

    if (dialog.exec())
        iconNameEdit->setText(dialog.selectedFiles().first());
#endif
}

// Parse Optimus Manager version
QString SettingsDialog::optimusManagerVersion()
{
    // Parse Optimus Manager version
    QFile optimusManagerBin("/usr/bin/optimus-manager-daemon");
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
