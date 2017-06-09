#include "LanTcpServer.h"
#include "P2PConstants.h"
#include "LanTcpServerHandler.h"

LanTcpServer::LanTcpServer(QObject* parent)
	: QTcpServer(parent)
{
// 	m_threadPool = new QThreadPool(this);
// 	m_threadPool->setMaxThreadCount(5);
}

void LanTcpServer::startServer(quint16 port)
{
	if (listen(QHostAddress::AnyIPv4, port))
	{
		qDebug() << "Listening to port " << port << "...";
	}
}

void LanTcpServer::incomingConnection(qintptr handle)
{
	qDebug() << handle << " connecting...";

	LanTcpServerHanlder* thread = new LanTcpServerHanlder(handle);
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

	thread->start();
}

// void LanTcpServer::acceptNewConnection()
// {
// 	QTcpSocket* client = m_tcpServer->nextPendingConnection();
// //	m_clients.append(client);
// 	connect(client, SIGNAL(readyRead()), this, SLOT(readyReadFromClient()));
// }
// 
// void LanTcpServer::readyReadFromClient()
// {
// 	QByteArray buffer;
// 	QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
// 	buffer = clientSocket->readAll();
// 	QHostAddress clientHostAddr = clientSocket->peerAddress();
// 	quint16 clientHostPort = clientSocket->peerPort();
// 	qDebug() << QString("Read data from client %1:%2 with data: %3").arg(clientHostAddr.toString(), QString::number(clientHostPort), buffer.data());
// 
// 	QByteArray block = getRequestedData();
// 	connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
// 	clientSocket->write(block);
// 	clientSocket->disconnectFromHost();
// }
// 
// QByteArray LanTcpServer::getRequestedData()
// {
// 	QByteArray block;
// 	QDataStream out(&block, QIODevice::WriteOnly);
// 	out.setVersion(QDataStream::Qt_5_5);
// 	out << (quint16)0;
// 	out << "Server has received your request!";
// 	out.device()->seek(0);
// 	out << (quint16)(block.size() - sizeof(quint16));
// 	return block;
// }