#ifndef SERVER_H
#define SERVER_H
#pragma once

#include <winsock2.h>
#include "ActionParser.h"
#include "ActionHandler.h"

class Server
{
public:
	Server();
	Server(const Server&) = default;
	~Server();

	Server& operator =(const Server&) = default;

	void startServer();
	void startListen();

private:
	static const int DEFAULT_BUFLEN = 512;

	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket;
	SOCKET ClientSocket;

	struct addrinfo hints;
	struct addrinfo *result;

	int iSendResult;
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;

	ActionParser parser;
	ActionHandler actionHandler;

	struct addrinfo init();

	void handleMessage(const char *pMessage, size_t len);
};

#endif