#include <iostream>

#include "framework/MainLoop.h"
#include "remoteMouse/RemoteMouse.h"

int main()
{
	std::cout << "foo" << std::endl;

	MainLoop remoteMouse(new RemoteMouse());

	remoteMouse.run();

	return 0;
}