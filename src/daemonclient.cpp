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
#include "singleapplication.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QMessageBox>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

const QMap<DaemonClient::GPU, QString> DaemonClient::gpuMap = {{Intel, QStringLiteral("intel")},
                                                               {Nvidia, QStringLiteral("nvidia")},
                                                               {Hybrid, QStringLiteral("hybrid")}};

DaemonClient::DaemonClient(QObject *parent) :
    QObject(parent)
{
}

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

    constexpr sockaddr_un saddr = {AF_UNIX, "/tmp/optimus-manager"};
    const int connectionStatus = ::connect(m_sockfd, reinterpret_cast<const sockaddr *>(&saddr), sizeof(saddr));
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

void DaemonClient::setGpu(GPU gpu)
{
    sendCommand(QStringLiteral("switch"), {{QStringLiteral("mode"), gpuMap[gpu]}});
}

void DaemonClient::setStartupMode(GPU gpu)
{
    sendCommand(QStringLiteral("startup"), {{QStringLiteral("mode"), gpuMap[gpu]}});
}

void DaemonClient::setConfig(const QString &path)
{
    sendCommand(QStringLiteral("user_config"), {{QStringLiteral("path"), path}});
}

void DaemonClient::setTempConfig(const QString &path)
{
    sendCommand(QStringLiteral("temp_config"), {{QStringLiteral("path"), path}});
}

bool DaemonClient::error()
{
    return m_error;
}

QString DaemonClient::errorString()
{
    return m_errorString;
}

DaemonClient::GPU DaemonClient::startupMode()
{
    QFile file("/var/lib/optimus-manager/startup_mode");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox message(QMessageBox::Warning, SingleApplication::applicationName(), tr("Unable to open startup mode file"));
        message.exec();
        return defaultStartupMode();
    }

    QByteArray modeString = file.readAll();
    if (modeString.back() == '\n')
        modeString.chop(1);

    return gpuMap.key(modeString, defaultStartupMode());
}

DaemonClient::GPU DaemonClient::defaultStartupMode()
{
    return Intel;
}

void DaemonClient::sendCommand(const QString &type, const std::initializer_list<QPair<QString, QJsonValue>> &args)
{
    const QJsonDocument command{{{QStringLiteral("type"), type}, {QStringLiteral("args"), {args}}}};
    const QByteArray json = command.toJson();

    const bool succes = ::send(m_sockfd, json.data(), static_cast<size_t>(json.size()), 0) != -1;

    setError(!succes);
}

void DaemonClient::setError(bool error)
{
    m_error = error;
    if (m_error)
        m_errorString = strerror(errno);
    else
        m_errorString.clear();
}
