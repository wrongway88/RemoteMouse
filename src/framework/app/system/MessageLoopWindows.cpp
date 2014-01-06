#include "MessageLoopWindows.h"

MessageLoopWindows::MessageLoopWindows()
{
}

MessageLoopWindows::~MessageLoopWindows()
{
}

std::string MessageLoopWindows::getMessage()
{
	PeekMessage(&m_msg, NULL, 0, 0, 0);

	return "";
}