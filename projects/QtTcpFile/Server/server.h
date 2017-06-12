#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include "sendthread.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = 0);
    void ServerListener();
    ~Server();

protected:
    void incomingConnection(int socketDescriptor);

signals:

public slots:

};

#endif // SERVER_H
