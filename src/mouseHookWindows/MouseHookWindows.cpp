#include <iostream>
#include <Windows.h>
#include "MouseHookWindows.h"

extern "C"
{
	DECLDIR BOOL InstallHook()
	{
		std::cout << "MouseHookWindows::InstallHook" << std::endl;

		if(g_hMouseHook != NULL)
		{
			return true;
		}

		g_hMouseHook = SetWindowsHookEx(WH_MOUSE, MouseProc, g_hInst, 0);
		if(g_hMouseHook == NULL)
		{
			return false;
		}

		return true;
	}

	DECLDIR BOOL UninstallHook()
	{
		std::cout << "MouseHookWindows::UninstallHook" << std::endl;

		if(g_hMouseHook != NULL)
		{
			UnhookWindowsHookEx(g_hMouseHook);
			g_hMouseHook = NULL;
		}
		return true;
	}

	LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
	{
		std::cout << "MouseHookWindows::MouseProc" << std::endl;

		return CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
	}
}

BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD reason, LPVOID reserved)
{
	std::cout << "MouseHookWindows::DllMain" << std::endl;

	g_hInst = hInstance;

	return true;
}