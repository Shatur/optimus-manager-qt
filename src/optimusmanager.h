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

#ifndef OPTIMUSMANAGER_H
#define OPTIMUSMANAGER_H

#include "optimussettings.h"

class Session;
class AppSettings;
class QMenu;
#ifdef PLASMA
class KStatusNotifierItem;
#else
class QSystemTrayIcon;
#endif

class OptimusManager : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(OptimusManager)

public:
    explicit OptimusManager(QObject *parent = nullptr);
    ~OptimusManager() override;

    static QIcon trayGpuIcon(const QString &iconName);

private slots:
    void switchToIntel();
    void switchToNvidia();
    void switchToHybrid();
    void openSettings();

private:
    void showNotification(const QString &title, const QString &message);
    void loadSettings(AppSettings &settings);
    void retranslateUi();
    void switchGpu(OptimusSettings::GPU switchingGpu);

    static OptimusSettings::GPU detectGpu();
    static bool isModuleAvailable(const QString &moduleName);
    static bool isServiceActive(const QString &serviceName);
    static bool isGdmPatched();
    static QString currentDisplayManager();
    static QVector<Session> activeSessions();
    static int sessionsCountWithoutGdm(const QVector<Session> &sessions);
    static void logout();
    static bool killProcess(const QByteArray &name);

    QMenu *m_contextMenu;
#ifdef PLASMA
    KStatusNotifierItem *m_trayIcon;
#else
    QSystemTrayIcon *m_trayIcon;
#endif
    OptimusSettings::GPU m_currentGpu;
};

#endif // OPTIMUSMANAGER_H
