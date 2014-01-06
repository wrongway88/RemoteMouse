#ifndef MOUSE_HOOK_TEST_H
#define MOUSE_HOOK_TEST_H

//#define WM_MOUSEHOOK WM_USER+100
#include <Windows.h>

typedef bool (*DllFunction_void)();
typedef bool (*DllFunction_bool)(bool);

class MouseHookTest
{
public:
	MouseHookTest();
	~MouseHookTest();

	void setup();

	void setMouseBlocked(bool mouseBlocked);

private:
	void loadMouseHookDll();
	void installMouseHook();
	void uninstallMouseHook();

	void installHookThread();

	HINSTANCE m_handle;

	DllFunction_void m_installHookFunction;
	DllFunction_void m_uninstallHookFunction;
	DllFunction_bool m_setMouseBlock;
};

#endif