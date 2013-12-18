#include "MouseHookTest.h"

#include <iostream>

//extern "C" __declspec(dllexport) void __stdcall SetHook(HWND);
//extern "C" __declspec(dllexport) void __stdcall RemoveHook(void);
//extern "C" __declspec(dllexport) MOUSEHOOKSTRUCT __stdcall GetMouseData(void);

MouseHookTest::MouseHookTest():
	m_installHookFunction(NULL),
	m_uninstallHookFunction(NULL)
{

}

MouseHookTest::~MouseHookTest()
{
	if(m_uninstallHookFunction != NULL)
	{
		std::cout << m_uninstallHookFunction() << std::endl;
	}
}

void MouseHookTest::setup()
{
	m_handle = LoadLibrary(TEXT("MouseHookWindows"));

	if(m_handle)
	{
		m_installHookFunction = (SetHookFunction)GetProcAddress(m_handle, "InstallHook");
		m_uninstallHookFunction = (SetHookFunction)GetProcAddress(m_handle, "UninstallHook");
	}

	if(m_installHookFunction != NULL)
	{
		std::cout << m_installHookFunction() << std::endl;
	}
}