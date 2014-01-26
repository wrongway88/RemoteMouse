#include "NetworkManager.h"

#include <iostream>

#include "ProtocollResolver.h"

NetworkManager::NetworkManager():
	m_contactManager(NULL)
{
}

NetworkManager::~NetworkManager()
{
	for(unsigned int i = 0; i < m_clients.size(); i++)
	{
		delete m_clients[i];
	}
}

void NetworkManager::setup(const std::string& computerName)
{
	m_computerName = computerName;

	try
	{
		m_udpServer.setup(Socket::Protocol::PROTOCOL_UDP);
		m_tcpServer.setup(Socket::Protocol::PROTOCOL_TCP);
		//m_client.setup(Socket::Protocol::PROTOCOL_UDP);

		registerInstance();

		m_contactManager = new ContactManager();
	}
	catch(std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}
}

void NetworkManager::update()
{
	updateServers();
	updateClients();
}

void NetworkManager::testConnecting()
{
	if(m_contactManager->getContactsCount() > 0)
	{
		connectToContact(m_contactManager->getContact(0));
	}
}

void NetworkManager::testConnections()
{
	try
	{
		for(unsigned int i = 0; i < m_clients.size(); i++)
		{
			m_clients[i]->sendMsg("foo");
		}
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void NetworkManager::shutdown()
{
	unregisterInstance();
}

void NetworkManager::updateServers()
{
	try
	{
		sockaddr_in senderAddr;

		std::string msg = m_udpServer.receiveMessage(senderAddr);

		if(msg.length() > 0)
		{
			std::cout << msg << std::endl;
			handleMessage(ProtocollResolver::resolveMessage(msg), senderAddr);
		}

		m_tcpServer.acceptConnection();
		std::vector<std::string> msgs = m_tcpServer.receiveMessage();

		if(msgs.size() > 0)
		{
			for(unsigned int i = 0; i < msgs.size(); i++)
			{
				if(msgs[i].length() > 0)
				{
					std::cout << msgs[i] << std::endl;
					handleMessage(ProtocollResolver::resolveMessage(msgs[i]));
				}
			}
		}
	}
	catch(std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}
}

void NetworkManager::updateClients()
{
	try
	{
		for(unsigned int i = 0; i < m_clients.size(); i++)
		{
			std::string msg = m_clients[i]->receiveMessage();

			if(msg.length() > 0)
			{
				std::cout << msg << std::endl;
			}
		}
	}
	catch(std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}
}

void NetworkManager::connectToContact(const ContactManager::InstanceContact& contact)
{
	try
	{
		Client* newClient = new Client();
		newClient->setup(Socket::Protocol::PROTOCOL_TCP, "", contact.addresse);
		m_clients.push_back(newClient);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void NetworkManager::handleMessage(const ProtocollMessage& message)
{

}

void NetworkManager::handleMessage(const ProtocollMessage& message, const sockaddr_in& senderAddr)
{
	if(message.getType() == MessageType::REGISTER || message.getType() == MessageType::REGISTER_RESPOND)
	{
		handleRegisterMessage(message, senderAddr);
	}
	else if(message.getType() == MessageType::UNREGISTER)
	{
		handleUnregisterMessage(message, senderAddr);
	}
}

void NetworkManager::handleRegisterMessage(const ProtocollMessage& message, const sockaddr_in& senderAddr)
{
	//get name
	std::string name;

	std::vector<std::string> parameters = message.getParameters();
	if(parameters.size() == 1)
	{
		name = parameters[0];
	}

	//catch program instance's own register message or nameless message
	if(name == m_computerName || name.length() <= 0)
	{
		return;
	}

	//save contact
	if(m_contactManager != NULL)
	{
		m_contactManager->addContact(name, senderAddr, m_computerName);
	}

	//respond
	if(message.getType() == MessageType::REGISTER)
	{
		std::vector<std::string> parameter;
		parameter.push_back(m_computerName);
		ProtocollMessage msg = Protocoll::getMessage(MessageType::REGISTER_RESPOND, parameter);

		m_udpServer.broadcast(msg.getMessage());
	}
}

void NetworkManager::handleUnregisterMessage(const ProtocollMessage& message, const sockaddr_in& senderAddr)
{
	if(m_contactManager != NULL)
	{
		std::string name;

		std::vector<std::string> parameters = message.getParameters();
		if(parameters.size() == 1)
		{
			name = parameters[0];

			m_contactManager->removeContact(name, senderAddr);
		}
	}
}

void NetworkManager::registerInstance()
{
	std::vector<std::string> parameters;
	parameters.push_back(m_computerName);
	ProtocollMessage message = Protocoll::getMessage(MessageType::REGISTER, parameters);
	m_udpServer.broadcast(message.getMessage());
}

void NetworkManager::unregisterInstance()
{
	std::vector<std::string> parameters;
	parameters.push_back(m_computerName);
	ProtocollMessage message = Protocoll::getMessage(MessageType::UNREGISTER, parameters);
	m_udpServer.broadcast(message.getMessage());
}