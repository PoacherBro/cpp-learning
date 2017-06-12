#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    ~Client();
    QTcpSocket *client;
    void start(QString address, quint16 port, QString file);
    QString filename;

private:
	quint16 receivedSize;
signals:

public slots:
    void ReadData();
    void Completed();
};

#endif // CLIENT_H
