#ifndef DAEMONCLIENT_H
#define DAEMONCLIENT_H

#include <QString>
#include <QObject>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

class DaemonClient : public QObject
{
public:
    DaemonClient() = default;

    void connect();
    ssize_t send(const char *message);

    bool error();
    QString errorString();

private:
    void storeErrno();

    QString m_errorString;
    bool m_error = false;
    int m_sockfd = -1;
};

#endif // DAEMONCLIENT_H
