#ifndef PROTOCOLL_RESOLVER_H
#define PROTOCOLL_RESOLVER_H

#include <string>

#include "Protocoll.h"

class ProtocollResolver
{
public:
	ProtocollResolver();
	~ProtocollResolver();

	static ProtocollMessage resolveMessage(std::string message);

private:
	static std::vector<std::string> resolveParameters(std::string parameterString);
};

#endif