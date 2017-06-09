#ifndef DOWNLOADRESOURCE_H
#define DOWNLOADRESOURCE_H

#include "P2PConstants.h"
#include "QtCore"

class DownloadResource
{

public:
	static void addResource(P2PConstants::DownloadResourceType type, QString host, quint16 hostPort);
	static QList<QString*> getResourceListPerType(P2PConstants::DownloadResourceType type);
	
private:
	static QMap<P2PConstants::DownloadResourceType, QList<QString*> > resources;
};

#endif