#include "LanTcpServerHandler.h"

#include <QDataStream>

LanTcpServerHanlder::LanTcpServerHanlder(qintptr socketDescriptor, QObject* parent /* = 0 */) :
	QThread(parent)
{
	this->socketDescriptor = socketDescriptor;
}

void LanTcpServerHanlder::run()
{
	qDebug() << "TCP server handler thread started";
	m_receivedSize = 0;
	m_socket = new QTcpSocket();

	if (!m_socket->setSocketDescriptor(socketDescriptor))
	{
		emit error(m_socket->error());
		return;
	}

	connect(m_socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
	connect(m_socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

	qDebug() << socketDescriptor << " Client connected";

	exec();
}

void LanTcpServerHanlder::readyRead()
{
	QDataStream in(m_socket);
	in.setVersion(QDataStream::Qt_5_5);
	
	if (m_receivedSize == 0) {
		if (m_socket->bytesAvailable() < sizeof(quint16))
			return;

		in >> m_receivedSize;
	}

	if (m_socket->bytesAvailable() < m_receivedSize)
		return;

	QString readData;
	in >> readData;

	qDebug() << socketDescriptor << " data in: " << readData;
	sendResponse("Received!");
}

void LanTcpServerHanlder::disconnected()
{
	qDebug() << socketDescriptor << " disconnected";

	m_socket->deleteLater();
	exit(0);
}

void LanTcpServerHanlder::sendResponse(QString parm)
{
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_0);
	out << (quint16)0;
	out << parm;
	out.device()->seek(0);
	out << (quint16)(block.size() - sizeof(quint16));

	m_socket->write(block);
	m_socket->flush();
//	m_socket->disconnectFromHost();
	m_socket->waitForDisconnected();
}