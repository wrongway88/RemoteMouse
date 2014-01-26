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

	void testConnecting();
	void testConnections();

	void shutdown();

private:
	void updateServers();
	void updateClients();

	void connectToContact(const ContactManager::InstanceContact& contact);

	void handleMessage(const ProtocollMessage& message);
	void handleMessage(const ProtocollMessage& message, const sockaddr_in& senderAddr);
	void handleRegisterMessage(const ProtocollMessage& message, const sockaddr_in& senderAddr);
	void handleUnregisterMessage(const ProtocollMessage& message, const sockaddr_in& senderAddr);
	void registerInstance();
	void unregisterInstance();

	ContactManager* m_contactManager;

	Server m_udpServer;
	Server m_tcpServer;
	//Client m_client;
	std::vector<Client*> m_clients; //these are stored as pointers to keep original socket (and not just copy it when pushing the Client to the list)

	std::string m_computerName;
};

#endif