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

	keyState = GetAsyncKeyState(VK_SPACE);
	keyboardState.setKeyDown(KeyboardState::KEY_SPACE, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(VK_UP);
	keyboardState.setKeyDown(KeyboardState::KEY_ARROW_UP, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(VK_DOWN);
	keyboardState.setKeyDown(KeyboardState::KEY_ARROW_DOWN, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(0x41);
	keyboardState.setKeyDown(KeyboardState::KEY_A, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(0x42);
	keyboardState.setKeyDown(KeyboardState::KEY_B, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(0x43);
	keyboardState.setKeyDown(KeyboardState::KEY_C, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(0x48);
	keyboardState.setKeyDown(KeyboardState::KEY_H, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(0x53);
	keyboardState.setKeyDown(KeyboardState::KEY_S, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(0x56);
	keyboardState.setKeyDown(KeyboardState::KEY_V, getKeyStateDown(keyState));

	keyState = GetAsyncKeyState(0x57);
	keyboardState.setKeyDown(KeyboardState::KEY_W, getKeyStateDown(keyState));
}