#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include "framework/app/network/Server.h"
#include "framework/app/network/Client.h"

#include "ContactManager.h"
#include "Protocoll.h"

class NetworkManager
{
public:
	NetworkManager();
	~NetworkManager();
	
	void setup(const std::string& computerName);

	void update();

	void shutdown();

private:
	void handleMessage(const ProtocollMessage& message, const sockaddr_in& senderAddr);
	void handleRegisterMessage(const ProtocollMessage& message, const sockaddr_in& senderAddr);
	void handleUnregisterMessage(const ProtocollMessage& message, const sockaddr_in& senderAddr);
	void registerInstance();
	void unregisterInstance();

	ContactManager* m_contactManager;

	Server m_server;
	Client m_client;

	std::string m_computerName;
};

#endif