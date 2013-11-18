#include "LogMessage.h"

const std::string LogMessage::infoTag = "INFO";
const std::string LogMessage::warningTag = "WARNING";
const std::string LogMessage::errorTag = "ERROR";

LogMessage::LogMessage(const Params& params):
	m_message(params.message),
	m_fileName(params.fileName),
	m_functionName(params.functionName),
	m_line(params.line),
	m_type(params.type),
	m_time(NULL),
	m_writeToConsole(params.writeToConsole),
	m_writeToFile(params.writeToFile)
{
	time_t time;
	std::time(&time);
	m_time = std::localtime(&time);
}

LogMessage::~LogMessage()
{
}

const std::string LogMessage::getMessage()
{
	std::stringstream message;

	message << m_time->tm_hour << ":" << m_time->tm_min << ":" << m_time->tm_sec << " ";

	if(m_type == this->TYPE_INFO)
	{
		message << infoTag + " ";
	}
	else if(m_type == this->TYPE_WARNING)
	{
		message << warningTag + " ";
	}
	else
	{
		message << errorTag + " ";
	}

	message << (m_functionName + " - " + m_message);

	return message.str();
}

const bool LogMessage::writeToConsole()
{
	return m_writeToConsole;
}

const bool LogMessage::writeToFile()
{
	return m_writeToFile;
}