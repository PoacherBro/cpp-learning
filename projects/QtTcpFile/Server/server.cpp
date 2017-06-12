#include "server.h"
#include <QtNetwork>

Server::Server(QObject *parent) :
    QTcpServer(parent)
{
    //connect(&server, SIGNAL(newConnection()),this, SLOT(acceptConnection()));
	if (listen(QHostAddress::AnyIPv4, 8888))
	{
		qDebug() << "Start listening 8888...";
	}
    qDebug() << serverAddress() << serverPort() << serverError();
}

Server::~Server()
{
    close();
}

void Server::incomingConnection(int socketDescriptor)
{
    qDebug() << "File transfer started";

    SendThread *thread = new SendThread(socketDescriptor,this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
    qDebug() << "Thread called";
}
