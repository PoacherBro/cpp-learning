#ifndef LANTCPCLIENT_H
#define LANTCPCLIENT_H

#include "QtCore"
#include "QtNetwork"

class LanTcpClient : public QThread
{
	Q_OBJECT

public:
	LanTcpClient(QObject* parent = 0);
	~LanTcpClient();

	void startDownload(QString downloadBlockMd5);

protected:
	void run();

private:
	QTcpSocket* m_tcpSocket;
	quint32 m_contentSize;

private:
	QStringList getLanServerInfo();
	void sendData(QString content);

private slots:
	void readyReceiveBlock();
	void handleSocketError(QAbstractSocket::SocketError socketError);
	void disconnected();
};

#endif