#include "client.h"

#include <QDataStream>

Client::Client(QObject *parent) :
    QObject(parent)
{
    client = new QTcpSocket(this);
    client->abort();
	receivedSize = 0;
    connect(client, SIGNAL(readyRead()), this, SLOT(ReadData()));
    connect(client, SIGNAL(disconnected()), this, SLOT(Completed()));

}

Client::~Client()
{
    client->close();
}

void Client::start(QString address, quint16 port, QString file)
{
    QHostAddress addr(address);
    filename = file;
    client->connectToHost(addr, port);
	if (client->waitForConnected())
	{
		qDebug() << "connected to server!";
	}
    qDebug() << client->socketDescriptor();
}


void Client::Completed()
{
	receivedSize = 0;
    qDebug() << "File transfer complete";
}

void Client::ReadData()
{
    QFile file(filename);
    if(!(file.open(QIODevice::Append)))
    {
        qDebug("File cannot be opened.");
        exit(0);
    }
	QDataStream out(client);
	if (receivedSize == 0)
	{
		if (client->bytesAvailable() < sizeof(quint16))
		{
			return;
		}
		out >> receivedSize;
	}
	if (client->bytesAvailable() < receivedSize)
		return;

	QString fileName;
	out >> fileName;
	qDebug() << "Receive file name: " << fileName;
    QByteArray read = client->readAll();
    qDebug() << "Read    : " << read.size();
    file.write(read);
    file.close();
}
