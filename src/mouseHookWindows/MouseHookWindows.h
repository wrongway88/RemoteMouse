#ifndef MOUSE_HOOK_WINDOWS_H
#define MOUSE_HOOK_WINDOWS_H

#if defined DLL_EXPORT
	#define DECLDIR __declspec(dllexport)
#else
	#define DECLDIR __declspec(dllimport)
#endif

#pragma data_seg(".mouseHookSharedMemory")
	HHOOK g_hMouseHook = NULL;
	HINSTANCE g_hInst = NULL;
	BOOL g_blockMouse = FALSE;
#pragma data_seg()
#pragma comment(linker, "/section:.mouseHookSharedMemory,RWS")

extern "C"
{
	DECLDIR BOOL InstallHook();
	DECLDIR BOOL UninstallHook();

	DECLDIR BOOL SetMouseBlock(bool block);

	LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
}

#endif