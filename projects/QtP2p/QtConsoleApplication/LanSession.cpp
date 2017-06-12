#include "LanSession.h"
#include "P2PConstants.h"
#include "DownloadResource.h"

#include "LanTcpClient.h"

LanSession::LanSession(QObject* parent)
	: QObject(parent)
{
	init();
}

LanSession::~LanSession() 
{
	delete m_udpSocket;
}

void LanSession::init()
{
	getLocalIp4();
	m_udpSocket = new QUdpSocket(this);
	m_udpSocket->bind(QHostAddress::AnyIPv4, port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
	connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(receiveFeedback()));

	broadcast();
}

void LanSession::broadcast()
{
	QByteArray datagram = MESSAGE_TYPE_BROADCAST.toLatin1();
	m_udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, m_udpSocket->localPort());
	qDebug() << "Start broadcast...";
}

void LanSession::processReceivedBroadcast(QByteArray senderDatagram, QHostAddress senderAddress, quint16 senderPort)
{
	quint32 senderIPv4 = senderAddress.toIPv4Address();

// 	if (senderIPv4 == m_localIp4.toIPv4Address())
// 	{
// 		qDebug() << "Received from local broadcast";
// 	}
// 	else 
// 	{
		QString senderIp = senderAddress.toString();
		qDebug() << tr("Receive from %1:%2 with data: %3").arg(senderAddress.toString(), QString::number(senderPort), senderDatagram.data());
		// 1. 保存对方地址
		DownloadResource::addResource(P2PConstants::DownloadResourceType::LAN, senderIp, senderPort);

		// 2. 发送回复
		m_udpSocket->writeDatagram(MESSAGE_TYPE_BROADCAST_FEEDBACK.toLatin1(), senderAddress, senderPort);
//	}
}

void LanSession::receiveFeedback()
{
	QHostAddress senderAddress;
	quint16 senderPort;
	QByteArray senderDatagram;

	senderDatagram.resize(m_udpSocket->pendingDatagramSize());
	m_udpSocket->readDatagram(senderDatagram.data(), senderDatagram.size(), &senderAddress, &senderPort);

	QString receivedData(senderDatagram);

	if (receivedData.startsWith(MESSAGE_TYPE_BROADCAST))
	{
		processReceivedBroadcast(senderDatagram, senderAddress, senderPort);
	}
	else if (receivedData.startsWith(MESSAGE_TYPE_BROADCAST_FEEDBACK)) 
	{
		qDebug() << "Received broadcast feedback from " << senderAddress.toString() << ":" << QString::number(senderPort);
// 		LanTcpClient client;
// 		client.startDownload("README.md");
		startTcpDownload("QtConsoleApplication.exe");
	}
}

void LanSession::getLocalIp4()
{
	foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) 
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
		{
			QString ipStr = address.toString();
			if (!ipStr.endsWith("1") && ipStr.section(".", -1, -1) != "1") 
			{
				m_localIp4 = address;
				qDebug() << "Local IPv4" << address.toString();
				break;
			}
		}
	}
}

void LanSession::startTcpDownload(QString param)
{
	qDebug() << "Start download " << param;
	QList<QString*> lanServerList = DownloadResource::getResourceListPerType(P2PConstants::DownloadResourceType::LAN);
	if (!lanServerList.isEmpty())
	{
		foreach(QString *lanServer, lanServerList)
		{
			QTcpSocket* client = new QTcpSocket(this);
			m_tcpClients.append(client);
			QByteArray* buffer = new QByteArray();
			quint16* size = new quint16(0);

			buffers.insert(client, buffer);
			receivedSize.insert(client, size);

			connect(client, SIGNAL(readyRead()), this, SLOT(readyReadTcpFeedback()));
			connect(client, SIGNAL(disconnected()), this, SLOT(tcpDisconnected()));

			QStringList lanServerInfo = lanServer->split(":");
			QString serverHost = lanServerInfo.at(0);
			client->connectToHost(QHostAddress(serverHost), LAN_TCP_SERVER_PORT);
			if (client->waitForConnected(5 * 1000)) // wait for 5s
			{
				qDebug() << QString("Connected to server %1:%2").arg(serverHost, QString::number(LAN_TCP_SERVER_PORT));
				sendData(client, param);
				break;
			}
		}
	}
	else
	{
		qDebug() << "Available IP list is empty!!!";
	}
}

void LanSession::sendData(QTcpSocket* socket, QString content)
{
	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_5);
	out << (quint16)0;
	out << content;
	out.device()->seek(0);
	out << (quint16)(data.size() - sizeof(quint16));

	socket->write(data);
	socket->flush();
}

void LanSession::readyReadTcpFeedback()
{
	QTcpSocket* client = qobject_cast<QTcpSocket*>(sender());
	quint16 s = 0;
	quint16 sizeOfQuint16 = sizeof(quint16);

	QDataStream in(client);
	in.setVersion(QDataStream::Qt_5_5);

	if (client->bytesAvailable() < sizeOfQuint16)
		return;

	in >> s;
	qDebug() << "Header declared size: " << s;
	qDebug() << "Available size: " << client->bytesAvailable();

	if (client->bytesAvailable() < s)
		return;

	// get sending file name
	QString fileName;
	in >> fileName;

	QByteArray line = client->readAll();
	qDebug() << "Received size: " << line.size();

	QString filePath = QDir::currentPath() + QDir::separator() + "app" + QDir::separator();
	QFile target(filePath + fileName);
	qDebug() << target.fileName();
	if (!target.open(QIODevice::Append)) {
		qDebug() << "Can't open file for written";
		return;
	}
	QTextStream out(&target);
	out << line;
//	target.write(line);
	target.close();
//	client->disconnectFromHost();
//	client->waitForDisconnected();
}

void LanSession::tcpDisconnected()
{
	QTcpSocket* client = qobject_cast<QTcpSocket*>(sender());
	qDebug() << "Disconnect from server!";
	client->deleteLater();
	quint16* size = receivedSize.value(client);
	delete size;
}

quint16 LanSession::arrayToInt(QByteArray source)
{
	quint16 temp;
	QDataStream data(&source, QIODevice::ReadWrite);
	data >> temp;
	return temp;
}