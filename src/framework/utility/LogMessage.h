#ifndef LOG_MESSAGE_H
#define LOG_MESSAGE_H

#include <string>
#include <sstream>
#include <ctime>

/**
 * @brief This class holds information of a log call. It can be an error or a general message. It also holds information of the message's origin and creation time.
 */
class LogMessage
{
public:
	enum Type
	{
		TYPE_INFO = 0,
		TYPE_WARNING,
		TYPE_ERROR
	};

	struct Params
	{
		Params(const std::string& message, const std::string& fileName, const std::string& functionName, const unsigned int line, const Type type, const bool writeToConsole, const bool writeToFile):
			message(message),
			fileName(fileName),
			functionName(functionName),
			line(line),
			type(type),
			writeToConsole(writeToConsole),
			writeToFile(writeToFile)
		{}

		const std::string& message;
		const  std::string& fileName;
		const  std::string& functionName;
		const  unsigned int line;
		const  Type type;
		const bool writeToConsole;
		const bool writeToFile;
	};

	LogMessage(const Params& params);
	~LogMessage();

	const std::string getMessage();

	const bool writeToConsole();
	const bool writeToFile();

private:
	const std::string m_message;
	const std::string m_fileName;
	const std::string m_functionName;
	const unsigned int m_line;
	std::tm* m_time;

	const Type m_type;

	const bool m_writeToConsole;
	const bool m_writeToFile;

	static const std::string infoTag;
	static const std::string warningTag;
	static const std::string errorTag;
};

#endif