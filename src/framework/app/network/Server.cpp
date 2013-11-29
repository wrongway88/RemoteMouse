#include "Server.h"

#include <exception>
#include <WS2tcpip.h>
#include <sstream>

Server::Server()
{}

Server::~Server()
{
	closeSocket();
}

void Server::setup(Protocol protocol)
{
	setup(protocol, m_defaultPort);
}

void Server::setup(Protocol protocol, const std::string& port)
{
	m_port = port.c_str();
	m_protocol = protocol;

	startup();
	createSocket(protocol);
	bindSocket();

	if(protocol == PROTOCOL_TCP)
	{
		listenSocket();
	}
	else
	{
		int broadcast = 1;
		int result = setsockopt(m_socket, SOL_SOCKET, SO_BROADCAST, (char*)&broadcast, sizeof(broadcast));
	}
}

void Server::acceptConnection()
{
	SOCKET clientSocket = acceptIncomingConnection();
}

std::string Server::receiveMessage()
{
	return receive();
}

void Server::broadcast(const std::string& message)
{
	if(m_protocol == PROTOCOL_UDP)
	{
		broadcastMessage(message);
	}
	else
	{
		throw(std::exception("Cannot broadcast, server is not using UDP!"));
	}
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
		std::stringstream message;
		message << "bind failed: Error " << result;
		throw(std::exception(message.str().c_str()));
	}

	freeaddrinfo(m_result);
}

void Server::listenSocket()
{
	if(listen(m_socket, SOMAXCONN) == SOCKET_ERROR)
	{
		closesocket(m_socket);
		WSACleanup();
		std::stringstream message;
		message << "Error while listening to socket! Error " << WSAGetLastError();
		throw(std::exception(message.str().c_str()));
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
	// recv() will create an error each time no data is received, so it would be stupid to throw an exception...
	/*else if(resultCode == SOCKET_ERROR)
	{
		std::stringstream message;
		message << "Failed to receive data: Error " << WSAGetLastError();
		throw(std::exception(message.str().c_str()));
	}*/

	return result;
}

void Server::broadcastMessage(const std::string& message)
{
	sockaddr_in rcvAddr;
	rcvAddr.sin_family = AF_INET;
	rcvAddr.sin_port = htons(6666);
	rcvAddr.sin_addr.s_addr = inet_addr("255.255.255.255");

	int length = message.length();
	char* buffer = new char[length];
	strcpy(buffer, message.c_str());

	int result = sendto(m_socket, buffer, length, 0, (SOCKADDR*) &rcvAddr, sizeof(rcvAddr));
	
	if(result == SOCKET_ERROR)
	{
		delete [] buffer;

		std::stringstream message;
		message << "Failed to broadcast data: error " << WSAGetLastError();
		throw(std::exception(message.str().c_str()));
	}
}