#include <iostream>
#include "TestDll.h"

extern "C"
{
	DECLDIR void testPrint()
	{
		std::cout << "DLL foo!" << std::endl;
	}
}