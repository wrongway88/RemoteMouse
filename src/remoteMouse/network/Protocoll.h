#ifndef PROTOCOLL_H
#define PROTOCOLL_H

#include <vector>

const static std::string MSG_REGISTER = "register";
const static std::string MSG_REGISTER_RESPOND = "register_respond";
const static std::string MSG_UNREGISTER = "unregister";

static enum MessageType
{
	INVALID = 0,
	REGISTER,
	REGISTER_RESPOND,
	UNREGISTER
};

class ProtocollMessage
{
public:
	ProtocollMessage(MessageType type, std::string message, std::vector<std::string> parameters):
		m_type(type),
		m_messageString(message),
		m_parameters(parameters)
	{}

	MessageType getType() const
	{
		return m_type;
	}

	std::string getString() const
	{
		return m_messageString;
	}

	std::vector<std::string> getParameters() const
	{
		return m_parameters;
	}

	std::string getMessage() const
	{
		std::string msg;

		msg += m_messageString;

		for(unsigned int i = 0; i < m_parameters.size(); i++)
		{
			msg += " ";
			msg += m_parameters[i];
		}

		return msg;
	}

private:
	MessageType m_type;
	std::string m_messageString;
	std::vector<std::string> m_parameters;
};

class Protocoll
{
public:
	Protocoll();
	~Protocoll();

	static ProtocollMessage getMessage(MessageType type, std::vector<std::string> parameter);

private:

};

#endif