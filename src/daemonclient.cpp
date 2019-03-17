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
