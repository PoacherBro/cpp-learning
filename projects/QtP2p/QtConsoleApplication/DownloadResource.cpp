#include "DownloadResource.h"
#include "P2PConstants.h"

QMap<P2PConstants::DownloadResourceType, QList<QString*> > DownloadResource::resources;

void DownloadResource::addResource(P2PConstants::DownloadResourceType type, QString host, quint16 hostPort)
{
	QList<QString*> hostInfoList = resources.value(type);
	QString hostInfo = QString("%1:%2").arg(host, QString::number(hostPort));
	if (hostInfoList.isEmpty() || !hostInfoList.contains(&hostInfo))
	{
		hostInfoList.append(new QString(hostInfo));
	}
	if (!resources.contains(type))
	{
		resources.insert(type, hostInfoList);
	}
}

QList<QString*> DownloadResource::getResourceListPerType(P2PConstants::DownloadResourceType type)
{
	return resources.value(type);
}