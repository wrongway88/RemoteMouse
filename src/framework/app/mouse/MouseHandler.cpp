#include "MouseHandler.h"

#include <Windows.h>

void MouseHandler::updateMouseState(MouseState& mouseState)
{
	mouseState.resetMouseMoved();

	mouseState.setMousePosition(getMousePosition());

	SHORT buttonState = 0;
	
	buttonState = GetAsyncKeyState(VK_LBUTTON);
}

ManuelVector::Vector2f MouseHandler::getMousePosition()
{
	ManuelVector::Vector2f result;

	POINT pos;
	if(GetCursorPos(&pos))
	{
		result.setX(float(pos.x));
		result.setY(float(pos.y));
	}

	return result;
}