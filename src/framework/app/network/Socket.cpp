#include "Socket.h"

#include <exception>
#include <WS2tcpip.h>
#include <sstream>

const PCSTR Socket::m_defaultPort = "6666";

Socket::Socket():
	m_socket(),
	m_protocol(PROTOCOL_NOT_SET)
{
}

Socket::~Socket()
{
}

void Socket::startup()
{
	int result = WSAStartup(MAKEWORD(2,2), &wsaData);

	if(result != 0)
	{
		std::stringstream message;
		message << "Startup failed: error " << WSAGetLastError();
		throw(std::exception(message.str().c_str()));
	}
}

void Socket::createSocket(Protocol protocol)
{
	ZeroMemory(&m_hints, sizeof(m_hints));
	m_hints.ai_family = AF_INET;
	m_hints.ai_flags = AI_PASSIVE;

	switch(protocol)
	{
	case PROTOCOL_TCP:
		m_hints.ai_socktype = SOCK_STREAM;
		m_hints.ai_protocol = IPPROTO_TCP;
		break;
	case PROTOCOL_UDP:
		m_hints.ai_socktype = SOCK_DGRAM;
		m_hints.ai_protocol = IPPROTO_UDP;
		break;
	default:
		WSACleanup();
		throw(std::exception("Invalid connection type"));
	}
	

	int result = getaddrinfo(NULL, m_port, &m_hints, &m_result);

	if(result != 0)
	{
		WSACleanup();
		std::stringstream message;
		message << "getaddrinfo failed: error " << WSAGetLastError();
		throw(std::exception(message.str().c_str()));
	}

	m_socket = socket(m_result->ai_family, m_result->ai_socktype, m_result->ai_protocol);

	if(m_socket == INVALID_SOCKET)
	{
		freeaddrinfo(m_result);
		WSACleanup();
		std::stringstream message;
		message << "Error at socket(): error " << WSAGetLastError();
		throw(std::exception(message.str().c_str()));
	}

	u_long mode = 1;
	ioctlsocket(m_socket, FIONBIO, &mode);
}

void Socket::closeSocket()
{
	closesocket(m_socket);
	WSACleanup();
}