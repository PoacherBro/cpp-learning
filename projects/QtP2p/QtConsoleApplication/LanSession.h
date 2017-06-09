#ifndef P2PSESSION_H
#define P2PSESSION_H

#include "QtCore"
#include "QtNetwork"

class LanSession : public QObject
{
	Q_OBJECT

public:
	LanSession(QObject *parent = 0);

	~LanSession();

private:
	static const quint16 port = 65001;

	QUdpSocket* m_udpSocket;
	QHostAddress m_localIp4;

private:
	void getLocalIp4();

	void broadcast();
	void processReceivedBroadcast(QByteArray senderDatagram, QHostAddress senderAddress, quint16 senderPort);
	void processReceivedBlock();

	void init();


private slots:
	void receiveFeedback();
};
#endif