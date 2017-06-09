#include "LanTcpServerHandler.h"

#include <QDataStream>
#include <QFile>
#include <QDir>

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
	sendResponse(readData);
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
	out.setVersion(QDataStream::Qt_5_5);

	QString filePath = QDir::currentPath() + QDir::separator() + parm;
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "Cannot read file " << filePath;
		return;
	}
	while (1)
	{
		block = file.read(64 * 1024);
		if (block.size() == 0)
			break;

		out << (quint16)0;
		out << block;
		out.device()->seek(0);
		out << (quint16)(block.size() - sizeof(quint16));
		m_socket->write(block);
		qDebug() << "Send file with size: " << block.size();
	}
	file.close();
//	m_socket->disconnectFromHost();
	m_socket->waitForDisconnected();
}