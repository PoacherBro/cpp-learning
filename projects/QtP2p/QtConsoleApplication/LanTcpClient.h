#ifndef LANTCPCLIENT_H
#define LANTCPCLIENT_H

#include "QtCore"
#include "QtNetwork"

class LanTcpClient : public QObject
{
	Q_OBJECT

public:
	LanTcpClient(QObject* parent = 0);
	~LanTcpClient();

	void startDownload(QString downloadBlockMd5);
private:
	QTcpSocket* m_tcpSocket;
	quint16 m_contentSize;

private:
	QStringList getLanServerInfo();
	void sendData(QString content);

private slots:
	void readyReceiveBlock();
	void handleSocketError(QAbstractSocket::SocketError socketError);
	void disconnected();
};

#endif