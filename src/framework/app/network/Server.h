#ifndef SOCKET_H
#define SOCKET_H

#include <WinSock2.h>
#include <string>

#define RECEIVE_BUFFER_LENGTH 512

class Server
{
public:
	Server();
	~Server();

	enum Protocol
	{
		PROTOCOL_TCP = 0,
		PROTOCOL_UDP
	};

	void setup(Protocol protocol);
	void setup(Protocol protocol, std::string port);

	void acceptConnection();

private:
	void startup();
	void createSocket(Protocol protocol);
	void bindSocket();

	void listenSocket();
	SOCKET acceptIncomingConnection();

	std::string receive();

	void closeSocket();

	static const PCSTR m_defaultPort;

	PCSTR m_port;
	SOCKET m_socket;
	WSADATA wsaData;
	struct addrinfo* m_result;
	struct addrinfo* m_ptr;
	struct addrinfo m_hints;

	char m_receiveBuffer[RECEIVE_BUFFER_LENGTH];
};

#endif