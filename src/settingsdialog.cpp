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
#include "optimussettings.h"
#include "singleapplication.h"

#include <QFileDialog>
#include <QStandardItemModel>
#include <QPushButton>
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

    // Parse Optimus Manager version
    QFile optimusManagerBin("/usr/bin/optimus-manager");
    optimusManagerBin.open(QIODevice::ReadOnly);
    QByteArray data = optimusManagerBin.readAll();
    data = data.mid(data.indexOf("optimus-manager==") + 17, 5);
    ui->versionLabel->setText(data);

    // Set languages data
    ui->languageComboBox->setItemData(0, QLocale::AnyLanguage);
    ui->languageComboBox->setItemData(1, QLocale::English);
    ui->languageComboBox->setItemData(2, QLocale::Russian);

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

void SettingsDialog::on_SettingsDialog_accepted()
{
    // Check if language changed
    AppSettings settings;
    const auto language = ui->languageComboBox->currentData().value<QLocale::Language>();
    if (language != settings.language()) {
        settings.setLocale(language);
        m_languageChanged = true;
    }

    // General settings
    settings.setAutostartEnabled(ui->autostartCheckBox->isChecked());
    settings.setConfirmSwitching(ui->confirmSwitchingCheckBox->isChecked());
    settings.setGpuIconName(OptimusManager::Intel, ui->intelIconEdit->text());
    settings.setGpuIconName(OptimusManager::Nvidia, ui->nvidiaIconEdit->text());

    // Optimus settings
    OptimusSettings optimusSettings;
    optimusSettings.setStartupMode(static_cast<OptimusSettings::StartupMode>(ui->startupModeComboBox->currentIndex()));
    optimusSettings.setSwitchingBackend(static_cast<OptimusSettings::SwitchingBackend>(ui->switchingBackendComboBox->currentIndex()));
    optimusSettings.setLoginManagerControl(ui->loginManagerControlCheckBox->isChecked());
    optimusSettings.setPciPowerControlEnabled(ui->pciPowerControlCheckBox->isChecked());
    optimusSettings.setPciResetEnabled(ui->pciResetCheckBox->isChecked());
    optimusSettings.setTerminateSesionsEnabled(ui->terminateSessionsCheckBox->isChecked());
    optimusSettings.setKillX11Enabled(ui->killX11CheckBox->isChecked());
    optimusSettings.setKillLogindEnabled(ui->killLogindCheckBox->isChecked());

    // Intel settings
    optimusSettings.setIntelDriver(static_cast<OptimusSettings::Driver>(ui->intelDriverComboBox->currentIndex()));
    optimusSettings.setIntelAccelMethod(static_cast<OptimusSettings::AccelMethod>(ui->intelAccelMethodComboBox->currentIndex()));
    optimusSettings.setIntelTearFree(static_cast<OptimusSettings::TearFree>(ui->intelTearFreeComboBox->currentIndex()));
    optimusSettings.setIntelDri(static_cast<OptimusSettings::DRI>(ui->intelDriComboBox->currentText().toInt()));
    optimusSettings.setIntelModesetEnabled(ui->intelModesetCheckBox->isChecked());

    // Nvidia settings
    optimusSettings.setNvidiaDri(static_cast<OptimusSettings::DRI>(ui->nvidiaDriComboBox->currentText().toInt()));
    optimusSettings.setNvidiaDpi(ui->nvidiaDpiSpinBox->value());
    optimusSettings.setNvidiaModesetEnabled(ui->nvidiaModesetCheckBox->isChecked());
    optimusSettings.setNvidiaPatEnabled(ui->nvidiaPatCheckBox->isChecked());

    OptimusSettings::NvidiaOptions nvidiaOptions;
    nvidiaOptions.setFlag(OptimusSettings::Overclocking, ui->nvidiaOverclockingCheckBox->isChecked());
    nvidiaOptions.setFlag(OptimusSettings::TrippleBuffer, ui->nvidiaTrippleBuffercheckBox->isChecked());
    optimusSettings.setNvidiaOptions(nvidiaOptions);

    optimusSettings.apply();
}

void SettingsDialog::restoreDefaults()
{
    // General settings
    const AppSettings settings;
    ui->languageComboBox->setCurrentIndex(0);
    ui->autostartCheckBox->setChecked(false);
    ui->confirmSwitchingCheckBox->setChecked(true);
    ui->intelIconEdit->setText(AppSettings::defaultTrayIconName(OptimusManager::Intel));
    ui->nvidiaIconEdit->setText(AppSettings::defaultTrayIconName(OptimusManager::Nvidia));

    // Optimus settings
    ui->startupModeComboBox->setCurrentIndex(0);
    ui->switchingBackendComboBox->setCurrentIndex(0);
    ui->loginManagerControlCheckBox->setChecked(true);
    ui->pciPowerControlCheckBox->setChecked(true);
    ui->pciResetCheckBox->setChecked(true);
    ui->terminateSessionsCheckBox->setChecked(true);
    ui->killX11CheckBox->setChecked(true);
    ui->killLogindCheckBox->setChecked(true);

    // Intel settings
    ui->intelDriverComboBox->setCurrentIndex(0);
    ui->intelAccelMethodComboBox->setCurrentIndex(0);
    ui->intelTearFreeComboBox->setCurrentIndex(0);
    ui->intelDriComboBox->setCurrentIndex(0);
    ui->intelModesetCheckBox->setChecked(false);

    // Nvidia settings
    ui->nvidiaDriComboBox->setCurrentIndex(0);
    ui->nvidiaDpiSpinBox->setValue(0);
    ui->nvidiaModesetCheckBox->setChecked(true);
    ui->nvidiaPatCheckBox->setChecked(true);
    ui->nvidiaOverclockingCheckBox->setChecked(true);
    ui->nvidiaTrippleBuffercheckBox->setChecked(false);
}

void SettingsDialog::loadSettings()
{
    // General settings
    const AppSettings settings;
    ui->languageComboBox->setCurrentIndex(ui->languageComboBox->findData(settings.language()));
    ui->autostartCheckBox->setChecked(settings.isAutostartEnabled());
    ui->confirmSwitchingCheckBox->setChecked(settings.isConfirmSwitching());
    ui->intelIconEdit->setText(settings.gpuIconName(OptimusManager::Intel));
    ui->nvidiaIconEdit->setText(settings.gpuIconName(OptimusManager::Nvidia));

    // Optimus settings
    const OptimusSettings optimusSettings;
    ui->startupModeComboBox->setCurrentIndex(optimusSettings.startupMode());
    ui->switchingBackendComboBox->setCurrentIndex(optimusSettings.switchingBackend());
    ui->loginManagerControlCheckBox->setChecked(optimusSettings.isLoginManagerControl());
    ui->pciPowerControlCheckBox->setChecked(optimusSettings.isPciPowerControlEnabled());
    ui->pciResetCheckBox->setChecked(optimusSettings.isPciResetEnabled());

    // Intel settings
    ui->intelDriverComboBox->setCurrentIndex(optimusSettings.intelDriver());
    ui->intelAccelMethodComboBox->setCurrentIndex(optimusSettings.intelAccelMethod());
    ui->intelTearFreeComboBox->setCurrentIndex(optimusSettings.intelTearFree());
    ui->intelDriComboBox->setCurrentText(QString::number(optimusSettings.intelDri()));
    ui->intelModesetCheckBox->setChecked(optimusSettings.isIntelModesetEnabled());
    ui->terminateSessionsCheckBox->setChecked(optimusSettings.isTerminateSesionsEnabled());
    ui->killX11CheckBox->setChecked(optimusSettings.isKillX11Enabled());
    ui->killLogindCheckBox->setChecked(optimusSettings.isKillLogindEnabled());

    // Nvidia settings
    ui->nvidiaDriComboBox->setCurrentText(QString::number(optimusSettings.nvidiaDri()));
    ui->nvidiaDpiSpinBox->setValue(optimusSettings.nvidiaDpi());
    ui->nvidiaModesetCheckBox->setChecked(optimusSettings.isNvidiaModesetEnabled());
    ui->nvidiaPatCheckBox->setChecked(optimusSettings.isNvidiaPatEnabled());

    const OptimusSettings::NvidiaOptions nvidiaOptions = optimusSettings.nvidiaOptions();
    ui->nvidiaOverclockingCheckBox->setChecked(nvidiaOptions.testFlag(OptimusSettings::Overclocking));
    ui->nvidiaTrippleBuffercheckBox->setChecked(nvidiaOptions.testFlag(OptimusSettings::TrippleBuffer));
}

void SettingsDialog::on_intelIconButton_clicked()
{
    ui->intelIconEdit->setText(chooseIcon());
}

void SettingsDialog::on_nvidiaIconButton_clicked()
{
    ui->nvidiaIconEdit->setText(chooseIcon());
}

void SettingsDialog::on_intelIconEdit_textChanged(const QString &fileName)
{
    const QIcon icon = OptimusManager::trayGpuIcon(fileName);
    ui->intelIconButton->setIcon(icon);
}

void SettingsDialog::on_nvidiaIconEdit_textChanged(const QString &fileName)
{
    const QIcon icon = OptimusManager::trayGpuIcon(fileName);
    ui->nvidiaIconButton->setIcon(icon);
}

QString SettingsDialog::chooseIcon()
{
#ifdef PLASMA
    KIconDialog dialog(this);
    dialog.setup(KIconLoader::Panel, KIconLoader::StatusIcon);

    return  dialog.openDialog();
#else

    QFileDialog dialog(this, tr("Select icon"));
    dialog.setNameFilter(tr("Images (*.png *.jpg *.bmp);;All files(*)"));
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFile);

    if (!dialog.exec())
        return QString();

    return dialog.selectedFiles().at(0);
#endif
}

void SettingsDialog::on_switchingBackendComboBox_currentIndexChanged(int index)
{
    if (index == OptimusSettings::Bbswitch) {
        ui->pciPowerControlCheckBox->setEnabled(false);
        ui->pciResetCheckBox->setEnabled(false);
        ui->intelModesetCheckBox->setEnabled(false);
    } else {
        ui->pciPowerControlCheckBox->setEnabled(true);
        ui->pciResetCheckBox->setEnabled(true);
        ui->intelModesetCheckBox->setEnabled(true);
    }
}
