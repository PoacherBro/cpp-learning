#ifndef P2PSESSION_H
#define P2PSESSION_H

#include "QtCore"
#include "QtNetwork"

#include "LanTcpClient.h"

class LanSession : public QObject
{
	Q_OBJECT

public:
	LanSession(QObject *parent = 0);

	~LanSession();

private:
	static const quint16 port = 65001;

	QUdpSocket* m_udpSocket;
	QHash<QTcpSocket*, quint32*> m_expectedSize;
	QHostAddress m_localIp4;

private:
	void getLocalIp4();

	void broadcast();
	void processReceivedBroadcast(QByteArray senderDatagram, QHostAddress senderAddress, quint16 senderPort);
	void processReceivedBlock();

	void init();

	void sendData(QTcpSocket* socket, QString content);
	void startTcpDownload(QString param);

private slots:
	void receiveFeedback();
	void readyReadTcpFeedback();
	void tcpDisconnected();
};
#endif