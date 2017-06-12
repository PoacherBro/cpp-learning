
#include <QtCore/QCoreApplication>
#include "LanTcpServer.h"
#include "P2PConstants.h"
#include "LanSession.h"
#include "LanTcpClient.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
// 	LanTcpServer lanServer;
// 	lanServer.startServer(LAN_TCP_SERVER_PORT);
 	LanSession lanSession;
// 	LanTcpClient client;
// 	client.startDownload("README.md");
	return a.exec();
}
