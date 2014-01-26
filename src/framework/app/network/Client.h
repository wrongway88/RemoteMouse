#ifndef CLIENT_H
#define CLIENT_H

#include <WinSock2.h>
#include <string>

#include "Socket.h"

class Client : public Socket
{
public:
	Client();
	~Client();

	void setup(Protocol protocol);
	void setup(Protocol protocol, const std::string& port);
	void setup(Protocol protocol, const std::string& port, const sockaddr_in& serverAddress);

	//works only for UDP clients
	void broadcast(const std::string& message);
	//works only for TCP clients
	//cant call it just send, name conflict with winsock method
	void sendMsg(const std::string& message);

	std::string receiveMessage();

private:
	void broadcastMessage(const std::string& message);
	void sendMessage(const std::string& message);

	char m_receiveBuffer[RECEIVE_BUFFER_LENGTH];
};

#endif