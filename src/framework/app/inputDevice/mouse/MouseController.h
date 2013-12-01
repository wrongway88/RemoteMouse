#ifndef MOUSE_CONTROLLER_H
#define MOUSE_CONTROLLER_H

#include "framework/math/vector/Vector.h"

#include <Windows.h>

class MouseController
{
public:
	static void setMousePosition(const Vector2i& position);
	static void setCursorVisible(const bool visible);

	static void setLeftButtonDown();
	static void setLeftButtonUp();

	static void setRightButtonDown();
	static void setRightButtonUp();

	static void setMiddleButtonDown();
	static void setMiddleButtonUp();

	static void rollMouseWheelUp();
	static void rollMouseWheelDown();

private:
	static void triggerMouseButtonEvent(int event);
};

#endif