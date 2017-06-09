#ifndef LANTCPSERVER_H
#define LANTCPSERVER_H

#include <QThreadPool>
#include <QTcpServer>

class LanTcpServer : public QTcpServer
{
	Q_OBJECT
public:
	explicit LanTcpServer(QObject* parent = 0);

	void startServer(quint16 port);

protected:
	void incomingConnection(qintptr handle);

private:
	QThreadPool* m_threadPool;
};

#endif