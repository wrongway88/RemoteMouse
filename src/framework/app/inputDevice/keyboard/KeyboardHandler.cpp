#include "KeyboardHandler.h"

#include <iostream>

#include <Windows.h>
#include "WinUser.h"

void KeyboardHandler::updateKeyboardState(KeyboardState& keyboardState)
{
	keyboardState.resetKeyReleased();

	SHORT keyState = 0;
	
	keyState = GetAsyncKeyState(VK_ESCAPE);
	keyboardState.setKeyDown(KeyboardState::KEY_ESCAPE, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(0x53);
	keyboardState.setKeyDown(KeyboardState::KEY_S, getKeyStateDown(keyState));
}