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
}
