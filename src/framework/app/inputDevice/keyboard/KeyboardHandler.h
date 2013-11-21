#ifndef KEYBOARD_HANDLER_H
#define KEYBOARD_HANDLER_H

#include "KeyboardState.h"

class KeyboardHandler
{
public:
	static void updateKeyboardState(KeyboardState& keyboardState);

private:
	static inline bool getKeyStateDown(short& keyState) { return bool(keyState >> 15); }
};

#endif