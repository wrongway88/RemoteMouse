#include <iostream>

#include "framework/MainLoop.h"
#include "remoteMouse/RemoteMouse.h"

int main()
{
	try
	{
		std::cout << "foo" << std::endl;

		MainLoop remoteMouse(new RemoteMouse());

		remoteMouse.run();
	}
	catch(std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}

	system("Pause");

	return 0;
}