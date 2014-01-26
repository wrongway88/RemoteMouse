#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <WinSock2.h>
#include <vector>
#include <string>

class ContactManager
{
public:
	ContactManager();
	~ContactManager();

	void addContact(const std::string& name, const sockaddr_in& addresse, const std::string& computerName = "");
	void removeContact(const std::string& name, const sockaddr_in& addresse);

	struct InstanceContact
	{
		std::string name;
		sockaddr_in addresse;

		InstanceContact():
			name(""),
			addresse()
		{}

		bool operator== (const InstanceContact& rContact)
		{
			return (this->name == rContact.name && memcmp(&this->addresse, &rContact.addresse, sizeof(SOCKADDR_IN)) == 0);
		}

		bool operator!= (const InstanceContact& rContact)
		{
			return !(*this == rContact);
		}
	};

	InstanceContact getContact(const unsigned int idx) const;
	int getContactsCount() const;

private:
	bool contactExists(InstanceContact& contact) const;

	//mainly for debugging...
	void printContactList() const;

	std::vector<InstanceContact> m_contacts;
};

#endif