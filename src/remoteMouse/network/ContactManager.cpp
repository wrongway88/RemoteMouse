#include "ContactManager.h"

#include <iostream>
#include <sstream>

ContactManager::ContactManager():
	m_contacts()
{
}

ContactManager::~ContactManager()
{
}

void ContactManager::addContact(const std::string& name, const sockaddr_in& addresse, const std::string& computerName)
{
	InstanceContact contact;
	contact.name = name;
	contact.addresse = addresse;

	if(contactExists(contact) == false && contact.name != computerName)
	{
		m_contacts.push_back(contact);
	}

	printContactList();
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

	printContactList();
}

ContactManager::InstanceContact ContactManager::getContact(const unsigned int idx) const
{
	if(idx < m_contacts.size())
	{
		return m_contacts[idx];
	}
	else
	{
		std::stringstream msg;
		msg << "No connection with idx " << idx << " available. Highest possible index is " << m_contacts.size() - 1 << ".";
		throw(std::exception(msg.str().c_str()));
	}
}

int ContactManager::getContactsCount() const
{
	return m_contacts.size();
}

bool ContactManager::contactExists(InstanceContact& contact) const
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

void ContactManager::printContactList() const
{
	std::cout << "Contacts: " << std::endl;

	for(int i = 0; i < m_contacts.size(); i++)
	{
		std::cout << i << ": " << m_contacts[i].name << std::endl;
	}
}