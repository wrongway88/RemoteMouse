#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include "LogMessage.h"

#include <iostream>
#include <string>
#include <queue>
#include <time.h>
#include <sstream>
#include <fstream>
#include <memory>

/**
 *@brief Class for logging messages to the console or to a file. It should be used instead of std::cout
 */
class LogManager
{
public:
	~LogManager();
	static std::shared_ptr<LogManager> getInstance();

	void logInfo(const std::string& message, const std::string& file, const std::string& function, const unsigned int line);
	void logWarning(const std::string& message, const std::string& file, const std::string& function, const unsigned int line);
	void logError(const std::string& message, const std::string& file, const std::string& function, const unsigned int line);

private:
	LogManager();

	void processLogMessage(std::shared_ptr<LogMessage> message);

	std::shared_ptr< std::vector<std::string> > flushInfoLogBuffer();

	void writeMessagesToFile(const std::shared_ptr< std::vector<std::string> >& messages);

	std::queue<std::shared_ptr<LogMessage>> m_messageBuffer;
	std::string m_fileName;

	static std::shared_ptr<LogManager> m_instance;

	static const int maxInfoLogBufferSize;
	static const bool infoToConsole;
	static const bool infoToFile;
	static const bool warningToConsole;
	static const bool warningToFile;
	static const bool errorToConsole;
	static const bool errorToFile;
};

/**	
 * @brief Makros to simplify the usage of the log manager
 */
#define LOG_INFO(str) \
	do \
	{ \
		std::string s((str)); \
		LogManager::getInstance()->logInfo(s, __FILE__, __FUNCTION__, __LINE__); \
	} \
	while(0) \

#define LOG_WARNING(str) \
	do \
	{ \
		std::string s((str)); \
		LogManager::getInstance()->logWarning(s, __FILE__, __FUNCTION__, __LINE__); \
	} \
	while(0) \

#define LOG_ERROR(str) \
	do \
	{ \
		std::string s((str)); \
		LogManager::getInstance()->logError(s, __FILE__, __FUNCTION__, __LINE__); \
	} \
	while(0) \

#endif