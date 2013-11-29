#ifndef MOUSE_HANDLER_H
#define MOUSE_HANDLER_H

#include "MouseState.h"
#include "framework/math/vector/Vector2.h"

class MouseHandler
{
public:
	static void updateMouseState(MouseState& mouseState);

private:
	static ManuelVector::Vector2i getMousePosition();
	static inline bool getKeyStateDown(short& keyState) { return bool(keyState >> 15); }
};

#endif