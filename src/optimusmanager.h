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

#ifndef OPTIMUSMANAGER_H
#define OPTIMUSMANAGER_H

#include <QObject>

class QMenu;
#ifdef KDE
class KStatusNotifierItem;
#else
class QSystemTrayIcon;
#endif

class OptimusManager : public QObject
{
    Q_OBJECT

public:
    enum Mode {
        Intel,
        Nvidia,
    };
    Q_ENUM(Mode)

    OptimusManager(QObject *parent = nullptr);
    ~OptimusManager() override;


private slots:
    void switchToIntel();
    void switchToNvidia();
    void openSettings();
    void showAppRunningMessage();

private:
    void switchMode(Mode mode);
    void retranslateUi();

    static Mode currentMode();

    QMenu *m_contextMenu;
#ifdef KDE
    KStatusNotifierItem *m_trayIcon;
#else
    QSystemTrayIcon *m_trayIcon;
#endif
};

#endif // OPTIMUSMANAGER_H
