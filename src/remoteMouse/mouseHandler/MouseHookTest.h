#ifndef MOUSE_HOOK_TEST_H
#define MOUSE_HOOK_TEST_H

//#define WM_MOUSEHOOK WM_USER+100
#include <Windows.h>

typedef bool (*SetHookFunction)();

class MouseHookTest
{
public:
	MouseHookTest();
	~MouseHookTest();

	void setup();

private:
	HINSTANCE m_handle;

	SetHookFunction m_installHookFunction;
	SetHookFunction m_uninstallHookFunction;
};

#endif