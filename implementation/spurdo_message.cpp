#ifndef _WIN32
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#else
#include <winsock.h>
#endif

#include "spurdo_message.h"

SpurdoMessage::SpurdoMessage()
{
	#ifdef _WIN32
		WSAData wsaData;
		WSAStartup(0x0202, &wsaData);
	#endif
}

SpurdoMessage::~SpurdoMessage()
{
	close(thisSocket);
	#ifdef _WIN32
		WSACleanup();
	#endif
}

createSocket()
{
	int thisSocket;
	struct sockaddr_in destination;
	
	destination.sin_family = AF_INET;
	thisSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(thisSocket < 0)
	{
		return 0;
	}
}
