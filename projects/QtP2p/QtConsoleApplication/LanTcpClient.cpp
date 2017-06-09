#include "LanTcpClient.h"
#include "DownloadResource.h"
#include "P2PConstants.h"

LanTcpClient::LanTcpClient(QObject* parent)
	: QObject(parent),
	m_contentSize(0)
{
	m_tcpSocket = new QTcpSocket(this);
	connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(readyReceiveBlock()));
	connect(m_tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(handleSocketError(QAbstractSocket::SocketError)));
	connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

LanTcpClient::~LanTcpClient()
{
	m_tcpSocket->close();
}

void LanTcpClient::startDownload(QString downloadBlockMd5)
{
	qDebug() << "Start download " << downloadBlockMd5;
	m_contentSize = 0;
	m_tcpSocket->abort();
	QList<QString*> lanServerList = DownloadResource::getResourceListPerType(P2PConstants::DownloadResourceType::LAN);
	if (!lanServerList.isEmpty())
	{
		foreach(QString *lanServer, lanServerList)
		{
			QStringList lanServerInfo = lanServer->split(":");
			QString serverHost = lanServerInfo.at(0);
			m_tcpSocket->connectToHost(QHostAddress(serverHost), LAN_TCP_SERVER_PORT);
			if (m_tcpSocket->waitForConnected(5 * 1000)) // wait for 5s
			{
				qDebug() << QString("Connected to server %1:%2").arg(serverHost, QString::number(LAN_TCP_SERVER_PORT));
				sendData(downloadBlockMd5);
				break;
			}
		}
	}
	else
	{
		qDebug() << "Available IP list is empty!!!";
	}
}

QStringList LanTcpClient::getLanServerInfo()
{
	QStringList result;
	return result;
}

void LanTcpClient::sendData(QString content)
{
	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_5);
	out << (quint16)0;
	out << content;
	out.device()->seek(0);
	out << (quint16)(data.size() - sizeof(quint16));

	m_tcpSocket->write(data);
	m_tcpSocket->flush();
}

void LanTcpClient::readyReceiveBlock()
{
	QDataStream in(m_tcpSocket);
	in.setVersion(QDataStream::Qt_5_5);
	if (m_contentSize == 0) {
		if (m_tcpSocket->bytesAvailable() < (int) sizeof(quint16))
			return;
		in >> m_contentSize;
	}
	if (m_tcpSocket->bytesAvailable() < m_contentSize)
		return;

	QString fileName;
	// get sending file name
	// in >> fileName;
	QByteArray line = m_tcpSocket->readAll();

	QString filePath = "."; // your file path for receiving  
	fileName = "README.md"; // fileName.section("/", -1);
	QFile target(filePath + "/" + fileName);

	if (!target.open(QIODevice::Append | QIODevice::WriteOnly)) {
		qDebug() << "Can't open file for written";
		return;
	}
	target.write(line);
	target.close();
	m_tcpSocket->disconnectFromHost();
	m_tcpSocket->waitForDisconnected();
}

void LanTcpClient::handleSocketError(QAbstractSocket::SocketError socketError)
{

}

void LanTcpClient::disconnected()
{
	qDebug() << "Disconnect from server!";
	m_tcpSocket->deleteLater();
}