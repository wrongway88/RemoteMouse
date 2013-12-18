#ifndef SOCKET_H
#define SOCKET_H

#include <WinSock2.h>

class Socket
{
public:
	Socket();
	virtual ~Socket();

	enum Protocol
	{
		PROTOCOL_NOT_SET = 0,
		PROTOCOL_TCP,
		PROTOCOL_UDP
	};

protected:
	void startup();
	void createSocket(Protocol protocol);

	void closeSocket();

	static const PCSTR m_defaultPort;

	PCSTR m_port;
	SOCKET m_socket;
	Protocol m_protocol;

	WSADATA wsaData;
	struct addrinfo m_hints;
	struct addrinfo* m_result;
};

#endif