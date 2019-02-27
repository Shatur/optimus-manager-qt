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
    void on_SettingsDialog_accepted();

    void on_noUpdatesIconButton_clicked();
    void on_updatingIconEditButton_clicked();
    void on_noUpdatesIconEdit_textChanged(const QString &fileName);
    void on_updatingIconEdit_textChanged(const QString &fileName);

    void on_switchingBackendComboBox_currentIndexChanged(int index);

    void restoreDefaults();

private:
    void chooseIcon(QLineEdit *iconPathEdit);
    void showIconPreview(QLabel *previewLabel, const QString &fileName);

    Ui::SettingsDialog *ui;
    bool m_languageChanged = false;
};

#endif // SETTINGSDIALOG_H
