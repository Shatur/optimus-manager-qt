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

#include "daemonclient.h"

#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

constexpr sockaddr_un m_saddr = {AF_UNIX, "/tmp/optimus-manager"};
constexpr socklen_t m_addrlen = sizeof(m_saddr);

DaemonClient::~DaemonClient()
{
    disconnect();
}

void DaemonClient::connect()
{
    disconnect();

    m_sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (m_sockfd == -1) {
        setError(true);
        return;
    }

    const int connectionStatus = ::connect(m_sockfd, reinterpret_cast<const sockaddr *>(&m_saddr), m_addrlen);
    setError(connectionStatus == -1);
}

void DaemonClient::disconnect()
{
    if (m_sockfd == -1)
        return;

    if (close(m_sockfd) == -1) {
        setError(true);
    } else {
        setError(false);
        m_sockfd = -1;
    }
}

ssize_t DaemonClient::send(const QString &message)
{
    const ssize_t bytesSent = ::send(m_sockfd, qPrintable(message), static_cast<size_t>(message.size()), 0);
    setError(bytesSent == -1);

    return bytesSent;
}

bool DaemonClient::error()
{
    return m_error;
}

QString DaemonClient::errorString()
{
    return m_errorString;
}

void DaemonClient::setError(bool error)
{
    m_error = error;
    if (m_error)
        m_errorString = strerror(errno);
    else
        m_errorString.clear();
}
