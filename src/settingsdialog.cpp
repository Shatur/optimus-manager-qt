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
    appSettings.setGpuIconName(OptimusSettings::Intel, ui->intelIconEdit->text());
    appSettings.setGpuIconName(OptimusSettings::Nvidia, ui->nvidiaIconEdit->text());

    // Optimus settings
    OptimusSettings optimusSettings;
    optimusSettings.setStartupMode(static_cast<OptimusSettings::GPU>(ui->startupModeComboBox->currentIndex()));
    optimusSettings.setSwitchingBackend(static_cast<OptimusSettings::SwitchingBackend>(ui->switchingBackendComboBox->currentIndex()));
    optimusSettings.setPciPowerControlEnabled(ui->pciPowerControlCheckBox->isChecked());
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

    optimusSettings.apply();

    QDialog::accept();
}

void SettingsDialog::restoreDefaults()
{
    // General settings
    ui->languageComboBox->setCurrentIndex(AppSettings::defaultLocale());
    ui->autostartCheckBox->setChecked(AppSettings::defaultAutostartEnabled());
    ui->confirmSwitchingCheckBox->setChecked(AppSettings::defaultConfirmSwitching());
    ui->intelIconEdit->setText(AppSettings::defaultTrayIconName(OptimusSettings::Intel));
    ui->nvidiaIconEdit->setText(AppSettings::defaultTrayIconName(OptimusSettings::Nvidia));

    // Optimus settings
    ui->startupModeComboBox->setCurrentIndex(OptimusSettings::defaultStartupMode());
    ui->switchingBackendComboBox->setCurrentIndex(OptimusSettings::defaultSwitchingBackend());
    ui->pciPowerControlCheckBox->setChecked(OptimusSettings::defaultPciPowerControlEnabled());
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
    ui->intelIconEdit->setText(settings.gpuIconName(OptimusSettings::Intel));
    ui->nvidiaIconEdit->setText(settings.gpuIconName(OptimusSettings::Nvidia));

    // Optimus settings
    const OptimusSettings optimusSettings;
    ui->startupModeComboBox->setCurrentIndex(optimusSettings.startupMode());
    ui->switchingBackendComboBox->setCurrentIndex(optimusSettings.switchingBackend());
    ui->pciPowerControlCheckBox->setChecked(optimusSettings.isPciPowerControlEnabled());
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

void SettingsDialog::chooseIntelIcon()
{
    chooseIcon(ui->intelIconEdit);
}

void SettingsDialog::chooseNvidiaIcon()
{
    chooseIcon(ui->nvidiaIconEdit);
}

void SettingsDialog::loadIntelIcon(const QString &fileName)
{
    const QIcon icon = OptimusManager::trayGpuIcon(fileName);
    ui->intelIconButton->setIcon(icon);
}

void SettingsDialog::loadNvidiaIcon(const QString &fileName)
{
    const QIcon icon = OptimusManager::trayGpuIcon(fileName);
    ui->nvidiaIconButton->setIcon(icon);
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

void SettingsDialog::processSwitchingBackendChanged(int index)
{
    switch (index) {
    case OptimusSettings::Nouveau:
        ui->intelModesetCheckBox->setEnabled(true);
        ui->pciPowerControlCheckBox->setEnabled(true);
        break;
    case OptimusSettings::Bbswitch:
        ui->intelModesetCheckBox->setEnabled(false);
        ui->pciPowerControlCheckBox->setEnabled(false);
        break;
    case OptimusSettings::NoneBackend:
        ui->intelModesetCheckBox->setEnabled(false);
        ui->pciPowerControlCheckBox->setEnabled(true);
        break;
    }
}

void SettingsDialog::processIntelDriverChanged(int index)
{
    if (index == OptimusSettings::IntelDriver) {
        ui->intelAccelMethodComboBox->setEnabled(true);
        ui->intelTearFreeComboBox->setEnabled(true);
    } else {
        ui->intelAccelMethodComboBox->setEnabled(false);
        ui->intelTearFreeComboBox->setEnabled(false);
    }
}
