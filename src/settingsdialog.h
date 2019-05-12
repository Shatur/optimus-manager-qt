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
    void on_intelIconButton_clicked();
    void on_nvidiaIconButton_clicked();
    void on_intelIconEdit_textChanged(const QString &fileName);
    void on_nvidiaIconEdit_textChanged(const QString &fileName);
    void on_switchingBackendComboBox_currentIndexChanged(int index);
    void on_intelDriverComboBox_currentIndexChanged(int index);

    void restoreDefaults();

private:
    void loadSettings();
    QString chooseIcon();

    static QString optimusManagerVersion();

    Ui::SettingsDialog *ui;
    bool m_languageChanged = false;
};

#endif // SETTINGSDIALOG_H
