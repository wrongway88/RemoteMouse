#ifndef MESSAGE_LOOP_WINDOWS_H
#define MESSAGE_LOOP_WINDOWS_H

#include "IMessageLoop.h"
#include <Windows.h>

class MessageLoopWindows : public IMessageLoop
{
public:
	MessageLoopWindows();
	~MessageLoopWindows();

	virtual std::string getMessage();

private:
	MSG m_msg;
};

#endif