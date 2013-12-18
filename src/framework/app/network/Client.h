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

	void broadcast(const std::string& message);

private:
	void broadcastMessage(const std::string& message);
};

#endif