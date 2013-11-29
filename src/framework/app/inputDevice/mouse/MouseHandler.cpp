#include "MouseHandler.h"

#include <Windows.h>

void MouseHandler::updateMouseState(MouseState& mouseState)
{
	mouseState.resetMouseMoved();
	mouseState.resetKeyReleased();

	mouseState.setMousePosition(getMousePosition());

	SHORT buttonState = 0;
	buttonState = GetAsyncKeyState(VK_LBUTTON);
	mouseState.setKeyDown(MouseState::KEY_LEFT, getKeyStateDown(buttonState));

	buttonState = GetAsyncKeyState(VK_RBUTTON);
	mouseState.setKeyDown(MouseState::KEY_RIGHT, getKeyStateDown(buttonState));

	buttonState = GetAsyncKeyState(VK_MBUTTON);
	mouseState.setKeyDown(MouseState::KEY_CENTER, getKeyStateDown(buttonState));
}

ManuelVector::Vector2i MouseHandler::getMousePosition()
{
	ManuelVector::Vector2i result;

	POINT pos;
	if(GetCursorPos(&pos))
	{
		result.setX(int(pos.x));
		result.setY(int(pos.y));
	}

	return result;
}