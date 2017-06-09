#ifndef P2PCONSTANTS_H
#define P2PCONSTANTS_H

#include "QString"

class P2PConstants
{
public:
	enum DownloadResourceType
	{
		LAN,
		P2P,
		HTTP
	};
};

const QString MESSAGE_TYPE_BROADCAST = "BROADCAST";
const QString MESSAGE_TYPE_BROADCAST_FEEDBACK = "FEEDBACK_BROADCAST";

const QString MESSAGE_TYPE_CANDIDATE = "CANDIDATE";
const QString MESSAGE_TYPE_CANDIDATE_FEEDBACK = "FEEDBACK_CANDIDATE";

const quint16 LAN_TCP_SERVER_PORT = 65100;

#endif