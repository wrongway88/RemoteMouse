#include "Client.h"

#include <sstream>

Client::Client()
{
}

Client::~Client()
{
}

void Client::setup(Protocol protocol)
{
	setup(protocol, m_defaultPort);
}

void Client::setup(Protocol protocol, const std::string& port)
{
	m_port = port.c_str();
	m_protocol = protocol;

	startup();
	createSocket(protocol);

	if(m_protocol == PROTOCOL_UDP)
	{
		int broadcast = 1;
		int result = setsockopt(m_socket, SOL_SOCKET, SO_BROADCAST, (char*)&broadcast, sizeof(broadcast));
	}
}

void Client::broadcast(const std::string& message)
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

void Client::broadcastMessage(const std::string& message)
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