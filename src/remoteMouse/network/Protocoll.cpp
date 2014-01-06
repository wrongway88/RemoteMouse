#include "Protocoll.h"

Protocoll::Protocoll()
{
}

Protocoll::~Protocoll()
{
}

ProtocollMessage Protocoll::getMessage(MessageType type, std::vector<std::string> parameter)
{
	switch(type)
	{
	case MessageType::REGISTER:
		return ProtocollMessage(type, MSG_REGISTER, parameter);
		break;
	case MessageType::REGISTER_RESPOND:
		return ProtocollMessage(type, MSG_REGISTER_RESPOND, parameter);
		break;
	case MessageType::UNREGISTER:
		return ProtocollMessage(type, MSG_UNREGISTER, parameter);
		break;
	}

	return ProtocollMessage(MessageType::INVALID, "", std::vector<std::string>());
}