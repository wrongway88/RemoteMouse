#include "NetworkManager.h"

#include <iostream>

#include "ProtocollResolver.h"

NetworkManager::NetworkManager():
	m_contactManager(NULL)
{
}

NetworkManager::~NetworkManager()
{
}

void NetworkManager::setup(const std::string& computerName)
{
	m_computerName = computerName;

	try
	{
		m_server.setup(Socket::Protocol::PROTOCOL_UDP);
		m_client.setup(Socket::Protocol::PROTOCOL_UDP);

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
	try
	{
		sockaddr_in senderAddr;

		std::string msg = m_server.receiveMessage(senderAddr);

		if(msg.length() > 0)
		{
			std::cout << msg << std::endl;
			handleMessage(ProtocollResolver::resolveMessage(msg), senderAddr);
		}
	}
	catch(std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}
}

void NetworkManager::shutdown()
{
	unregisterInstance();
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
	//save contact
	if(m_contactManager != NULL)
	{
		std::string name;

		std::vector<std::string> parameters = message.getParameters();
		if(parameters.size() == 1)
		{
			name = parameters[0];

			m_contactManager->addContact(name, senderAddr);
		}
	}

	//respond
	if(message.getType() == MessageType::REGISTER)
	{
		std::vector<std::string> parameter;
		parameter.push_back(m_computerName);
		ProtocollMessage msg = Protocoll::getMessage(MessageType::REGISTER_RESPOND, parameter);

		m_server.broadcast(msg.getMessage());
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
	m_server.broadcast(message.getMessage());
}

void NetworkManager::unregisterInstance()
{
	std::vector<std::string> parameters;
	parameters.push_back(m_computerName);
	ProtocollMessage message = Protocoll::getMessage(MessageType::UNREGISTER, parameters);
	m_server.broadcast(message.getMessage());
}