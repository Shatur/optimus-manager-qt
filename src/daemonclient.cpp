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

#include <QProcess>
#include <QDebug>

#include <sys/socket.h>
#include <sys/un.h>

constexpr sockaddr_un m_saddr = {AF_UNIX, "/tmp/optimus-manager"};
constexpr socklen_t m_addrlen = sizeof(m_saddr);

bool DaemonClient::isDaemonActive()
{
    QProcess process;
    process.setProgram("systemctl");
    process.setArguments({"is-active", "optimus-manager"});
    process.start();
    process.waitForFinished();

    return process.readAllStandardOutput() == "active\n";
}

void DaemonClient::connect()
{
    m_sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (m_sockfd == -1)
        storeErrno();

    if (::connect(m_sockfd, reinterpret_cast<const sockaddr *>(&m_saddr), m_addrlen) == -1)
        storeErrno();
}

ssize_t DaemonClient::send(const QString &message)
{
    const ssize_t bytesSent = ::send(m_sockfd, qPrintable(message), static_cast<size_t>(message.size()), 0);
    if (bytesSent == -1)
        storeErrno();

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

void DaemonClient::storeErrno()
{
    m_errorString = strerror(errno);
    m_error = true;
}
