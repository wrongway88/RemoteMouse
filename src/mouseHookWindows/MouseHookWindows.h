#ifndef MOUSE_HOOK_WINDOWS_H
#define MOUSE_HOOK_WINDOWS_H

#if defined DLL_EXPORT
	#define DECLDIR __declspec(dllexport)
#else
	#define DECLDIR __declspec(dllimport)
#endif

//shared resources...
#pragma data_seg("shared")
	HHOOK g_hMouseHook = NULL;
	HINSTANCE g_hInst = NULL;
#pragma data_set()
#pragma comment(linker, "/SECTION:shared,RWS")

extern "C"
{
	DECLDIR BOOL InstallHook();
	DECLDIR BOOL UninstallHook();

	LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
}

#endif