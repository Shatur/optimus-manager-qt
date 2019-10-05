#ifndef SESSION_H
#define SESSION_H

#include <QDBusObjectPath>

// To demarshall QDBusArgument
struct Session
{
    QString sessionId;
    int userId = 0;
    QString userName;
    QString seatId;
    QDBusObjectPath sessionObjectPath;
};

#endif // SESSION_H
