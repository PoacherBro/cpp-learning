#ifndef LANTCPSERVERHANLDER_H
#define LANTCPSERVERHANLDER_H

#include <QThread>
#include <QTcpSocket>

class LanTcpServerHanlder : public QThread
{
	Q_OBJECT
public:
	explicit LanTcpServerHanlder(qintptr socketDescriptor, QObject* parent = 0);

	void run();

signals:
	void error(QTcpSocket::SocketError socketError);

private slots:
	void readyRead();
	void disconnected();

private:
	QTcpSocket* m_socket;
	qintptr socketDescriptor;
	quint16 m_receivedSize;
	QByteArray* m_receivedData;

private:
	void sendResponse(QString parm);
};

#endif