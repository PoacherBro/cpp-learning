#include "LanTcpServerHandler.h"

#include <QDataStream>
#include <QFile>
#include <QDir>
#include <QTextCodec>

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
		m_socket->disconnectFromHost();
		return;
	}
	while (1)
	{
		block.clear();
		out.device()->seek(0);

		QString fileName(parm);
		QByteArray fileContent;
		fileContent = file.read(64 * 1024);
		if (fileContent.size() == 0)
			break;

		out << (quint32)0;
		out << fileName;
		out << fileContent;
		int blockSize = block.size();
		qDebug() << "File name size: " << fileName.size();
		qDebug() << "File content size: " << fileContent.size();
		if (blockSize < 0)
			break;

		quint32 contentSize = quint32(blockSize) - sizeof(quint32);
		qDebug() << "Content size: " << contentSize;
		out.device()->seek(0);
		out << contentSize;

		qDebug() << "Send file with size: " << m_socket->write(block);

		m_socket->waitForBytesWritten();
	}
	file.close();
	m_socket->disconnectFromHost();
}