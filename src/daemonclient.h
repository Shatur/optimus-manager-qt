#ifndef DAEMONCLIENT_H
#define DAEMONCLIENT_H

#include <QString>
#include <QObject>

class DaemonClient : public QObject
{
public:
    DaemonClient() = default;

    bool isDaemonActive();
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
