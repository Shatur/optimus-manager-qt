#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

class QLineEdit;
class QLabel;

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog() override;

    bool languageChanged() const;

private slots:
    // UI
    void on_SettingsDialog_accepted();
    void on_resetSettingsButton_clicked();

    void on_noUpdatesIconButton_clicked();
    void on_updatingIconEditButton_clicked();
    void on_noUpdatesIconEdit_textChanged(const QString &fileName);
    void on_updatingIconEdit_textChanged(const QString &fileName);

    void on_switchingBackendComboBox_currentIndexChanged(int index);

private:
    void chooseIcon(QLineEdit *iconPathEdit);
    void showIconPreview(QLabel *previewLabel, const QString &fileName);

    Ui::SettingsDialog *ui;
    bool m_languageChanged = false;
};

#endif // SETTINGSDIALOG_H
