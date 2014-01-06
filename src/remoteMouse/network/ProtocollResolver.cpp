#include "ProtocollResolver.h"

ProtocollResolver::ProtocollResolver()
{
}

ProtocollResolver::~ProtocollResolver()
{
}

ProtocollMessage ProtocollResolver::resolveMessage(std::string message)
{
	if(message.length() > 0)
	{
		std::string type = message;
		int pos = message.find(" ");

		if(pos > -1)
		{
			type = message.substr(0, pos);
		}

		if(type == MSG_REGISTER)
		{
			std::string parameterString = message.substr(9);
			return ProtocollMessage(MessageType::REGISTER, MSG_REGISTER, resolveParameters(parameterString));
		}
		else if(type == MSG_REGISTER_RESPOND)
		{
			std::string parameterString = message.substr(17);
			return ProtocollMessage(MessageType::REGISTER_RESPOND, MSG_REGISTER_RESPOND, resolveParameters(parameterString));
		}
		if(type == MSG_UNREGISTER)
		{
			std::string parameterString = message.substr(11);
			return ProtocollMessage(MessageType::UNREGISTER, MSG_UNREGISTER, resolveParameters(parameterString));
		}
	}
	
	return ProtocollMessage(MessageType::INVALID, "", std::vector<std::string>());
}

std::vector<std::string> ProtocollResolver::resolveParameters(std::string parameterString)
{
	std::vector<std::string> result;

	while(parameterString.length() > 0)
	{
		int pos = parameterString.find(" ");

		if(pos > -1)
		{
			std::string tmpString = parameterString.substr(pos+1);

			int posTmp = tmpString.find(" ");
			if(posTmp > -1)
			{
				tmpString = tmpString.substr(posTmp);

				parameterString = parameterString.substr(pos+1+posTmp);
			}
			else
			{
				parameterString = parameterString.substr(pos+1);
			}

			result.push_back(tmpString);
		}
		else
		{
			result.push_back(parameterString);
			parameterString = "";
		}
	}

	return result;
}