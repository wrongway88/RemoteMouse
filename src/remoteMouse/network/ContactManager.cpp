#include "ContactManager.h"

#include <iostream>

ContactManager::ContactManager():
	m_contacts()
{
}

ContactManager::~ContactManager()
{
}

void ContactManager::addContact(const std::string& name, const sockaddr_in& addresse)
{
	InstanceContact contact;
	contact.name = name;
	contact.addresse = addresse;

	if(contactExists(contact) == false)
	{
		m_contacts.push_back(contact);
	}
}

void ContactManager::removeContact(const std::string& name, const sockaddr_in& addresse)
{
	InstanceContact contact;
	contact.name = name;
	contact.addresse = addresse;

	for(unsigned int i = 0; i < m_contacts.size(); i++)
	{
		if(contact == m_contacts[i])
		{
			m_contacts.erase(m_contacts.begin()+i);
			break;
		}
	}
}

bool ContactManager::contactExists(InstanceContact& contact)
{
	for(unsigned int i = 0; i < m_contacts.size(); i++)
	{
		if(contact == m_contacts[i])
		{
			return true;
		}
	}

	return false;
}