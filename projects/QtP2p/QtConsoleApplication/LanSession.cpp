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
	//}
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
		LanTcpClient client;
		client.startDownload("README.md");
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