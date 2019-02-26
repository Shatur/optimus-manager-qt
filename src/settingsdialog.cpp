#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "appsettings.h"
#include "optimussettings.h"
#include "singleapplication.h"

#include <QFileDialog>
#include <QStandardItemModel>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    ui->logoLabel->setPixmap(QIcon::fromTheme("nvidia").pixmap(512, 512));
    ui->versionGuiLabel->setText(SingleApplication::applicationVersion());

    // Parse optimus manager version
    QFile optimusManagerBin("/usr/bin/optimus-manager");
    optimusManagerBin.open(QIODevice::ReadOnly);
    QByteArray data = optimusManagerBin.readAll();
    data = data.mid(data.indexOf("optimus-manager==") + 17, 5);
    ui->versionLabel->setText(data);

    // Set languages data
    ui->languageComboBox->setItemData(0, QLocale::AnyLanguage);
    ui->languageComboBox->setItemData(1, QLocale::English);
    ui->languageComboBox->setItemData(2, QLocale::Russian);

    // General settings
    const AppSettings settings;
    ui->languageComboBox->setCurrentIndex(ui->languageComboBox->findData(settings.language()));
    ui->autostartCheckBox->setChecked(settings.isAutostartEnabled());
    ui->confirmSwitchingCheckBox->setChecked(settings.isConfirmSwitching());
    ui->noUpdatesIconEdit->setText(settings.modeIconName(OptimusManager::Intel));
    ui->updatingIconEdit->setText(settings.modeIconName(OptimusManager::Nvidia));

    // Optimus settings
    const OptimusSettings optimusSettings;
    ui->switchingBackendComboBox->setCurrentIndex(optimusSettings.switchingBackend());
    ui->loginManagerControlCheckBox->setChecked(optimusSettings.isLoginManagerControl());
    ui->pciPowerControlCheckBox->setChecked(optimusSettings.isPciPowerControlEnabled());
    ui->pciResetCheckBox->setChecked(optimusSettings.isPciResetEnabled());

    // Intel settings
    ui->intelDriverComboBox->setCurrentIndex(optimusSettings.intelDriver());
    ui->intelAccelMethodComboBox->setCurrentIndex(optimusSettings.intelAccelMethod());
    ui->intelTearFreeComboBox->setCurrentIndex(optimusSettings.intelTearFree());
    ui->intelDriComboBox->setCurrentIndex(optimusSettings.intelDri() - 2);
    ui->intelModesetCheckBox->setChecked(optimusSettings.isIntelModesetEnabled());

    // Nvidia settings
    ui->nvidiaDriComboBox->setCurrentIndex(optimusSettings.nvidiaDri() - 2);
    ui->nvidiaDpiSpinBox->setValue(optimusSettings.nvidiaDpi());
    ui->nvidiaModesetCheckBox->setChecked(optimusSettings.isNvidiaModesetEnabled());
    ui->nvidiaPatCheckBox->setChecked(optimusSettings.isNvidiaPatEnabled());

    const OptimusSettings::NvidiaOptions nvidiaOptions = optimusSettings.nvidiaOptions();
    ui->nvidiaOverclockingCheckBox->setChecked(nvidiaOptions.testFlag(OptimusSettings::Overclocking));
    ui->nvidiaTrippleBuffercheckBox->setChecked(nvidiaOptions.testFlag(OptimusSettings::TrippleBuffer));

    // Check if bbswitch installed
    if (!QFileInfo::exists("/usr/lib/modules/extramodules-ARCH/bbswitch.ko.xz")) {
        auto model = dynamic_cast<QStandardItemModel *>(ui->switchingBackendComboBox->model());
        model->item(OptimusSettings::Bbswitch)->setEnabled(false);

        if (ui->switchingBackendComboBox->currentIndex() == OptimusSettings::Bbswitch)
            ui->switchingBackendComboBox->setCurrentIndex(OptimusSettings::NoneBackend);
    }
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
    settings.setModeIconName(OptimusManager::Intel, ui->noUpdatesIconEdit->text());
    settings.setModeIconName(OptimusManager::Nvidia, ui->updatingIconEdit->text());

    // Optimus settings
    OptimusSettings optimusSettings;
    optimusSettings.setSwitchingBackend(static_cast<OptimusSettings::SwitchingBackend>(ui->switchingBackendComboBox->currentIndex()));
    optimusSettings.setLoginManagerControl(ui->loginManagerControlCheckBox->isChecked());
    optimusSettings.setPciPowerControlEnabled(ui->pciPowerControlCheckBox->isChecked());
    optimusSettings.setPciResetEnabled(ui->pciResetCheckBox->isChecked());

    // Intel settings
    optimusSettings.setIntelDriver(static_cast<OptimusSettings::Driver>(ui->intelDriverComboBox->currentIndex()));
    optimusSettings.setIntelAccelMethod(static_cast<OptimusSettings::AccelMethod>(ui->intelAccelMethodComboBox->currentIndex()));
    optimusSettings.setIntelTearFree(static_cast<OptimusSettings::TearFree>(ui->intelTearFreeComboBox->currentIndex()));
    optimusSettings.setIntelDri(static_cast<OptimusSettings::DRI>(ui->intelDriComboBox->currentIndex() + 2));
    optimusSettings.setIntelModesetEnabled(ui->intelModesetCheckBox->isChecked());

    // Nvidia settings
    optimusSettings.setNvidiaDri(static_cast<OptimusSettings::DRI>(ui->nvidiaDriComboBox->currentIndex() + 2));
    optimusSettings.setNvidiaDpi(ui->nvidiaDpiSpinBox->value());
    optimusSettings.setNvidiaModesetEnabled(ui->nvidiaModesetCheckBox->isChecked());
    optimusSettings.setNvidiaPatEnabled(ui->nvidiaPatCheckBox->isChecked());

    OptimusSettings::NvidiaOptions nvidiaOptions;
    nvidiaOptions.setFlag(OptimusSettings::Overclocking, ui->nvidiaOverclockingCheckBox->isChecked());
    nvidiaOptions.setFlag(OptimusSettings::TrippleBuffer, ui->nvidiaTrippleBuffercheckBox->isChecked());
    optimusSettings.setNvidiaOptions(nvidiaOptions);

    optimusSettings.apply();
}

void SettingsDialog::on_resetSettingsButton_clicked()
{
    // General settings
    const AppSettings settings;
    ui->languageComboBox->setCurrentIndex(0);
    ui->autostartCheckBox->setChecked(false);
    ui->confirmSwitchingCheckBox->setChecked(true);
    ui->noUpdatesIconEdit->setText(AppSettings::defaultTrayIconName(OptimusManager::Intel));
    ui->updatingIconEdit->setText(AppSettings::defaultTrayIconName(OptimusManager::Nvidia));

    // Optimus settings
    ui->switchingBackendComboBox->setCurrentIndex(0);
    ui->loginManagerControlCheckBox->setChecked(true);
    ui->pciPowerControlCheckBox->setChecked(true);
    ui->pciResetCheckBox->setChecked(true);

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

void SettingsDialog::on_noUpdatesIconButton_clicked()
{
    chooseIcon(ui->noUpdatesIconEdit);
}

void SettingsDialog::on_updatingIconEditButton_clicked()
{
    chooseIcon(ui->updatingIconEdit);
}

void SettingsDialog::on_noUpdatesIconEdit_textChanged(const QString &fileName)
{
    showIconPreview(ui->noUpdatesIconPreviewLabel, fileName);
}

void SettingsDialog::on_updatingIconEdit_textChanged(const QString &fileName)
{
    showIconPreview(ui->updatingIconPreviewLabel, fileName);
}

void SettingsDialog::chooseIcon(QLineEdit *iconPathEdit)
{
    QFileDialog dialog(this, tr("Select icon"));
    dialog.setNameFilter(tr("Images (*.png *.jpg *.bmp);;All files(*)"));
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFile);

    if (!dialog.exec())
        return;

    iconPathEdit->setText(dialog.selectedFiles().at(0));
}

void SettingsDialog::showIconPreview(QLabel *previewLabel, const QString &fileName)
{
    if (QIcon::hasThemeIcon(fileName))
        previewLabel->setPixmap(QIcon::fromTheme(fileName).pixmap(24, 24));
    else
        previewLabel->setPixmap(QIcon(fileName).pixmap(24, 24));
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
