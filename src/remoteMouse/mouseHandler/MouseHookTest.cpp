#include "MouseHookTest.h"

#include <iostream>

//extern "C" __declspec(dllexport) void __stdcall SetHook(HWND);
//extern "C" __declspec(dllexport) void __stdcall RemoveHook(void);
//extern "C" __declspec(dllexport) MOUSEHOOKSTRUCT __stdcall GetMouseData(void);

MouseHookTest::MouseHookTest():
	m_installHookFunction(NULL),
	m_uninstallHookFunction(NULL),
	m_setMouseBlock(NULL)
{
	std::cout << "MouseHookTest::MouseHookTest" << std::endl;
}

MouseHookTest::~MouseHookTest()
{
	std::cout << "MouseHookTest::~MouseHookTest" << std::endl;

	uninstallMouseHook();

	FreeLibrary(m_handle);
	/**/
}

void MouseHookTest::setup()
{
	installHookThread();
}

void MouseHookTest::setMouseBlocked(bool mouseBlocked)
{
	if(m_setMouseBlock != NULL)
	{
		m_setMouseBlock(mouseBlocked);
	}
}

void MouseHookTest::loadMouseHookDll()
{
	m_handle = LoadLibrary(TEXT("MouseHookWindows"));

	if(m_handle)
	{
		m_installHookFunction = (DllFunction_void)GetProcAddress(m_handle, "InstallHook");
		m_uninstallHookFunction = (DllFunction_void)GetProcAddress(m_handle, "UninstallHook");
		m_setMouseBlock = (DllFunction_bool)GetProcAddress(m_handle, "SetMouseBlock");
	}
}

void MouseHookTest::installMouseHook()
{
	if(m_installHookFunction != NULL)
	{
		std::cout << m_installHookFunction() << std::endl;
	}
}

void MouseHookTest::uninstallMouseHook()
{
	if(m_uninstallHookFunction != NULL)
	{
		std::cout << m_uninstallHookFunction() << std::endl;
	}
}

void MouseHookTest::installHookThread()
{
	loadMouseHookDll();

	installMouseHook();
}