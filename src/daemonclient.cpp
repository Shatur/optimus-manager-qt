#include "daemonclient.h"

constexpr sockaddr_un m_saddr = { AF_UNIX, "/tmp/optimus-manager" };
constexpr socklen_t m_addrlen = sizeof(m_saddr);

void DaemonClient::connect()
{
    m_sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (m_sockfd == -1)
        storeErrno();

    if (::connect(m_sockfd, reinterpret_cast<const sockaddr *>(&m_saddr), m_addrlen) == -1)
        storeErrno();
}

ssize_t DaemonClient::send(const char *message)
{
    const ssize_t bytesSent = ::send(m_sockfd, message, strlen(message), 0);
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
