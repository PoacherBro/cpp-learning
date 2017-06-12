#include <QCoreApplication>
#include <QDir>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Client client;
    QString fileName = QDir::currentPath() + QDir::separator() + "windows-version.txt";
    client.start("192.168.0.107", 65100, fileName);
    return a.exec();
}
