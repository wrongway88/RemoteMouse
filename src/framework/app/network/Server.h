#ifndef SERVER_H
#define SERVER_H

#include <WinSock2.h>
#include <string>
#include <vector>

#include "Socket.h"

class Server : public Socket
{
public:
	Server();
	~Server();

	void setup(Protocol protocol);
	void setup(Protocol protocol, const std::string& port);

	void acceptConnection();
	std::vector<std::string> receiveMessage(); //todo: return string vector (one string per client)
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

	std::vector<SOCKET> m_clientSockets;
	char m_receiveBuffer[RECEIVE_BUFFER_LENGTH];
};

#endif