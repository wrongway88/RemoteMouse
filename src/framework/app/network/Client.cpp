#include "Client.h"

#include <sstream>

Client::Client()
{
}

Client::~Client()
{
	shutdown(m_socket, SD_SEND);
	closeSocket();
}

void Client::setup(Protocol protocol)
{
	setup(protocol, m_defaultPort);
}

void Client::setup(Protocol protocol, const std::string& port)
{
	if(port.length() > 0)
		m_port = port.c_str();
	else
		m_port = m_defaultPort;

	m_protocol = protocol;

	startup();
	createSocket(protocol);

	if(m_protocol == PROTOCOL_TCP)
	{
		throw(std::exception("Cannot setup client as TCP without a server address!"));
	}
	else
	{
		int broadcast = 1;
		int result = setsockopt(m_socket, SOL_SOCKET, SO_BROADCAST, (char*)&broadcast, sizeof(broadcast));
	}
}

void Client::setup(Protocol protocol, const std::string& port, const sockaddr_in& serverAddress)
{
	if(port.length() > 0)
		m_port = port.c_str();
	else
		m_port = m_defaultPort;

	m_protocol = protocol;

	startup();
	createSocket(protocol);

	if(m_protocol == PROTOCOL_TCP)
	{
		int result = connect(m_socket, (SOCKADDR*) &serverAddress, sizeof(serverAddress));
		if(result == SOCKET_ERROR)
		{
			int errorCode = WSAGetLastError();
			if(errorCode != 10035 && errorCode != 10037 && errorCode != 10056) //all these errors can (and probably will) occur when using non-blocking sockets, they are non-critical and can therefore be ignored (at least they should not throw exceptions...)
			{
				std::stringstream msg;
				msg << "Failed to connect to server! Error: " << errorCode;
				closeSocket();
				throw(std::exception(msg.str().c_str()));
			}
		}
	}
	else
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
		throw(std::exception("Cannot broadcast, client is not using UDP!"));
	}
}

void Client::sendMsg(const std::string& message)
{
	if(m_protocol == PROTOCOL_TCP)
	{
		sendMessage(message);
	}
	else
	{
		throw(std::exception("Cannot send, client is not using TCP!"));
	}
}

std::string Client::receiveMessage()
{
	std::string result = "";
	int resultCode;

	resultCode = recv(m_socket, m_receiveBuffer, RECEIVE_BUFFER_LENGTH, 0);

	if(resultCode > 0)
	{
		result = m_receiveBuffer;
		result = result.substr(0, resultCode);
	}

	return result;
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

void Client::sendMessage(const std::string& message)
{
	int length = message.length();
	char* buffer = new char[length];
	strcpy(buffer, message.c_str());

	int result = send(m_socket, buffer, length, 0);

	if(result == SOCKET_ERROR)
	{
		//delete [] buffer;

		std::stringstream message;
		message << "Failed to send message: error " << WSAGetLastError();
		throw(std::exception(message.str().c_str()));
	}
}