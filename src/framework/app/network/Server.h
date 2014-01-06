#ifndef SERVER_H
#define SERVER_H

#include <WinSock2.h>
#include <string>

#include "Socket.h"

#define RECEIVE_BUFFER_LENGTH 512

class Server : public Socket
{
public:
	Server();
	~Server();

	void setup(Protocol protocol);
	void setup(Protocol protocol, const std::string& port);

	void acceptConnection();
	std::string receiveMessage();
	std::string receiveMessage(sockaddr_in& senderAddr);

	/**
	 * @note: only for UDP server
	 */
	void broadcast(const std::string& message);

private:
	void bindSocket();

	void listenSocket();
	SOCKET acceptIncomingConnection();

	std::string receive();
	void broadcastMessage(const std::string& message);

	struct addrinfo* m_ptr;

	char m_receiveBuffer[RECEIVE_BUFFER_LENGTH];
};

#endif