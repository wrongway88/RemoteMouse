#ifndef I_COMPUTER_H
#define I_COMPUTER_H

#include <string>

class IComputer
{
public:
	IComputer(){};
	virtual ~IComputer(){};

	virtual std::string getName() const = 0;

private:
};

#endif