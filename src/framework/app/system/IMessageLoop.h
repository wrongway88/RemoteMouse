#ifndef I_MESSAGE_LOOP_H
#define I_MESSAGE_LOOP_H

#include <string>

class IMessageLoop
{
public:
	IMessageLoop(){};
	virtual ~IMessageLoop(){};

	/**
	 * @brief Must be called every update loop
	 * @note Would cause apps with system hooks to crash if not called
	 */
	virtual std::string getMessage() = 0;

private:
};

#endif