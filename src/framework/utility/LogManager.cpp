#include "LogManager.h"

std::shared_ptr<LogManager> LogManager::m_instance;

const int LogManager::maxInfoLogBufferSize = 10;
const bool LogManager::infoToConsole = false;
const bool LogManager::infoToFile = false;
const bool LogManager::warningToConsole = false;
const bool LogManager::warningToFile = true;
const bool LogManager::errorToConsole = false;
const bool LogManager::errorToFile = true;

std::shared_ptr<LogManager> LogManager::getInstance()
{
	if(0 == m_instance.use_count())
	{
		std::shared_ptr<LogManager> shPtr(new LogManager);
		m_instance = shPtr;
	}

	return m_instance;
}

void LogManager::logInfo(const std::string& message, const std::string& file, const std::string& function, const unsigned int line)
{
	std::shared_ptr<LogMessage> logInfo = std::make_shared<LogMessage>(LogMessage::Params(message, file, function, line, LogMessage::TYPE_INFO, infoToConsole, infoToFile));

	processLogMessage(logInfo);
}

void LogManager::logWarning(const std::string& message, const std::string& file, const std::string& function, const unsigned int line)
{
	std::shared_ptr<LogMessage> logWarning = std::make_shared<LogMessage>(LogMessage::Params(message, file, function, line, LogMessage::TYPE_WARNING, warningToConsole, warningToFile));

	processLogMessage(logWarning);
}

void LogManager::logError(const std::string& message, const std::string& file, const std::string& function, const unsigned int line)
{
	LogMessage logError(LogMessage::Params(message, file, function, line, LogMessage::TYPE_ERROR, warningToConsole, warningToFile));
	std::string sMessage = logError.getMessage();

	if(errorToConsole)
	{
		std::cout << sMessage << std::endl;
	}

	if(errorToFile)
	{
		std::shared_ptr< std::vector<std::string> > messages = std::make_shared< std::vector<std::string> >();

		if(infoToFile)
		{
			//get info messages and append to messages vector
			std::shared_ptr< std::vector<std::string> > infoMessages = flushInfoLogBuffer();
			messages->insert(messages->end(), infoMessages->begin(), infoMessages->end());
		}

		messages->push_back(sMessage);
	
		writeMessagesToFile(messages);
	}
}

LogManager::LogManager():
	m_messageBuffer(),
	m_fileName("logs/log_")
{
	time_t t;
	std::time(&t);
	std::tm* time = std::localtime(&t);

	std::stringstream fileName;
	fileName << m_fileName;
	fileName << time->tm_mday << "-" << (time->tm_mon + 1) << "-" << (time->tm_year + 1900)
			<< "_" << time->tm_hour << "-" << time->tm_min << "-" << time->tm_sec;
	fileName << ".txt";

	m_fileName = fileName.str();
}

LogManager::~LogManager()
{
	writeMessagesToFile(flushInfoLogBuffer());
	m_instance.reset();
}

void LogManager::processLogMessage(std::shared_ptr<LogMessage> message)
{
	if(message->writeToConsole())
	{
		std::cout << message->getMessage() << std::endl;
	}

	if(message->writeToFile())
	{
		m_messageBuffer.push(message);

		if(m_messageBuffer.size() > maxInfoLogBufferSize)
		{
			writeMessagesToFile(flushInfoLogBuffer());
		}
	}
}

std::shared_ptr< std::vector<std::string> > LogManager::flushInfoLogBuffer()
{
	std::shared_ptr< std::vector<std::string> > messages = std::make_shared< std::vector<std::string> >();

	while(m_messageBuffer.size() > 0)
	{
		std::shared_ptr<LogMessage> message = m_messageBuffer.front();
		std::string sMessage = message->getMessage();

		messages->push_back(sMessage);
		
		//delete message;
		m_messageBuffer.pop();
	}

	return messages;
}

void LogManager::writeMessagesToFile(const std::shared_ptr< std::vector<std::string> >& messages)
{
	std::ofstream file;
	file.open(m_fileName, std::ios::app);
	file.seekp(0, std::ios::end);

	for(unsigned int i = 0; i < messages->size(); i++)
	{
		file << messages->at(i) << "\n";
	}
	file.close();
}