#include <Windows.h>
#include "MouseHookWindows.h"

#include <sstream>

extern "C"
{
	DECLDIR BOOL InstallHook()
	{
		if(g_hMouseHook != NULL)
		{
			return true;
		}
		
		g_hMouseHook = SetWindowsHookEx(WH_MOUSE, MouseProc, g_hInst, 0);
		if(g_hMouseHook == NULL)
		{
			return false;
		}

		Beep(400, 500);

		return true;
	}

	DECLDIR BOOL UninstallHook()
	{
		if(g_hMouseHook != NULL)
		{
			Beep(200, 300);

			UnhookWindowsHookEx(g_hMouseHook);
			g_hMouseHook = NULL;
		}

		return true;
	}

	DECLDIR BOOL SetMouseBlock(bool block)
	{
		Beep(700, 750);

		g_blockMouse = block;

		return g_blockMouse;
	}

	LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
	{
		if(g_blockMouse)
		{
			if(wParam == WM_RBUTTONDOWN)
			{
				return -1;
			}
			else if(wParam == WM_RBUTTONUP)
			{
				Beep(700, 100);
				return -1;
			}
		}

		return CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
	}
}

BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD reason, LPVOID reserved)
{
	g_hInst = hInstance;
	
	return true;
}