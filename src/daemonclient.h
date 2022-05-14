/*
 *  Copyright © 2019-2022 Hennadii Chernyshchyk <genaloner@gmail.com>
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
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a get of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef DAEMONCLIENT_H
#define DAEMONCLIENT_H

#include "settings/optimussettings.h"

class DaemonClient : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(DaemonClient)

public:
    explicit DaemonClient(QObject *parent = nullptr);
    ~DaemonClient() override;

    void connect();
    void disconnect();

    void setGpu(OptimusSettings::Mode gpu);
    void setConfig(const QString &content);
    void setTempConfig(const QString &path);

    bool error() const;
    QString errorString();

private:
    void sendCommand(const QString &type, std::initializer_list<QPair<QString, QJsonValue>> args);
    void setError(bool error);

    QString m_errorString;
    bool m_error = false;
    int m_sockfd = -1;
};

#endif // DAEMONCLIENT_H
