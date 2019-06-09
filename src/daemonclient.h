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

#ifndef DAEMONCLIENT_H
#define DAEMONCLIENT_H

#include <QString>

class DaemonClient
{
    Q_DISABLE_COPY(DaemonClient)

public:
    DaemonClient() = default;

    void connect();
    ssize_t send(const QString &message);

    bool error();
    QString errorString();

private:
    void storeErrno();

    QString m_errorString;
    bool m_error = false;
    int m_sockfd = -1;
};

#endif // DAEMONCLIENT_H
