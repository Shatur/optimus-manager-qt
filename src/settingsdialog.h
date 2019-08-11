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

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT
    Q_DISABLE_COPY(SettingsDialog)

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog() override;

    bool languageChanged() const;

public slots:
    void accept() override;

private slots:
    void chooseIntelIcon();
    void chooseNvidiaIcon();
    void loadIntelIcon(const QString &fileName);
    void loadNvidiaIcon(const QString &fileName);
    void processSwitchingBackendChanged(int index);
    void processIntelDriverChanged(int index);
    void restoreDefaults();

private:
    void loadSettings();
    void chooseIcon(QLineEdit *iconNameEdit);

    static QString optimusManagerVersion();

    Ui::SettingsDialog *ui;
    bool m_languageChanged = false;
};

#endif // SETTINGSDIALOG_H
