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

	keyState = GetAsyncKeyState(VK_UP);
	keyboardState.setKeyDown(KeyboardState::KEY_ARROW_UP, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(VK_DOWN);
	keyboardState.setKeyDown(KeyboardState::KEY_ARROW_DOWN, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(0x41);
	keyboardState.setKeyDown(KeyboardState::KEY_A, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(0x48);
	keyboardState.setKeyDown(KeyboardState::KEY_H, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(0x53);
	keyboardState.setKeyDown(KeyboardState::KEY_S, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(0x57);
	keyboardState.setKeyDown(KeyboardState::KEY_W, getKeyStateDown(keyState));
}