#include "Server.h"

#include <exception>
#include <WS2tcpip.h>
//#include <Windows.h>

const PCSTR Server::m_defaultPort = "6666";

Server::Server():
	m_socket(INVALID_SOCKET)
{}

Server::~Server()
{
	closeSocket();
}

void Server::setup(Protocol protocol)
{
	setup(protocol, m_defaultPort);
}

void Server::setup(Protocol protocol, std::string port)
{
	m_port = port.c_str();

	startup();
	createSocket(protocol);
	bindSocket();
	listenSocket();
}

void Server::acceptConnection()
{
	SOCKET clientSocket = acceptIncomingConnection();
}

void Server::startup()
{
	int result = WSAStartup(MAKEWORD(2,2), &wsaData);

	if(result != 0)
	{
		std::string message = "Startup failed: error " + result;
		throw(std::exception(message.c_str()));
	}
}

void Server::createSocket(Protocol protocol)
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
		std::string message = "getaddrinfo failed: error " + result;
		throw(std::exception(message.c_str()));
	}

	m_socket = socket(m_result->ai_family, m_result->ai_socktype, m_result->ai_protocol);

	if(m_socket == INVALID_SOCKET)
	{
		freeaddrinfo(m_result);
		WSACleanup();
		std::string message = "Error at socket(): error " + WSAGetLastError();
		throw(std::exception(message.c_str()));
	}

	u_long mode = 1;
	ioctlsocket(m_socket, FIONBIO, &mode);
}

void Server::bindSocket()
{
	if(m_socket == INVALID_SOCKET)
	{
		std::string message = "Can't bind Socket, socket is invalid";
		throw(std::exception(message.c_str()));
	}

	int result;
	result = bind(m_socket, m_result->ai_addr, (int)m_result->ai_addrlen);

	if(result == SOCKET_ERROR)
	{
		freeaddrinfo(m_result);
		closesocket(m_socket);
		WSACleanup();
		std::string message = "bind failed: Error " + result;
		throw(std::exception(message.c_str()));
	}

	freeaddrinfo(m_result);
}

void Server::listenSocket()
{
	if(listen(m_socket, SOMAXCONN) == SOCKET_ERROR)
	{
		closesocket(m_socket);
		WSACleanup();
		std::string message = "Error while listening to socket!";
		throw(std::exception(message.c_str()));
	}
}

SOCKET Server::acceptIncomingConnection()
{
	return accept(m_socket, NULL, NULL);
}

std::string Server::receive()
{
	std::string result = "";
	int resultCode;
	resultCode = recv(m_socket, m_receiveBuffer, RECEIVE_BUFFER_LENGTH, 0);

	if(resultCode > 0)
	{
		printf("bytes received: %d\n", resultCode);
		result = m_receiveBuffer;
	}

	return result;
}

void Server::closeSocket()
{
	closesocket(m_socket);
	WSACleanup();
}