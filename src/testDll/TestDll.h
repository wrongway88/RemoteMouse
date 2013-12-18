#ifndef TEST_DLL_H
#define TEST_DLL_H

#if defined DLL_EXPORT
	#define DECLDIR __declspec(dllexport)
#else
	#define DECLDIR __declspec(dllimport)
#endif

extern "C"
{
	DECLDIR void testPrint();
}

#endif