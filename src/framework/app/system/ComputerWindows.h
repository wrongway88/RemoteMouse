#ifndef COMPUTER_WINDOWS_H
#define COMPUTER_WINDOWS_H

#include "IComputer.h"

class ComputerWindows : public IComputer
{
public:
	ComputerWindows();
	~ComputerWindows();

	virtual std::string getName() const;

private:
	static const unsigned int m_maxNameLength;

};

#endif