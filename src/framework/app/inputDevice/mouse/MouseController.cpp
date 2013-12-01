#include "MouseController.h"

#include <Windows.h>
#include <WinUser.h>

#include <iostream>

void MouseController::setMousePosition(const Vector2i& position)
{
	SetCursorPos(position.getX(), position.getY());
}

void MouseController::setCursorVisible(const bool visible)
{
	//???
}

void MouseController::setLeftButtonDown()
{
	triggerMouseButtonEvent(MOUSEEVENTF_LEFTDOWN);
}

void MouseController::setLeftButtonUp()
  {
	triggerMouseButtonEvent(MOUSEEVENTF_LEFTUP);
}

void MouseController::setRightButtonDown()
{
	triggerMouseButtonEvent(MOUSEEVENTF_RIGHTDOWN);
}

void MouseController::setRightButtonUp()
{
	triggerMouseButtonEvent(MOUSEEVENTF_RIGHTUP);
}

void MouseController::setMiddleButtonDown()
{
	triggerMouseButtonEvent(MOUSEEVENTF_MIDDLEDOWN);
}

void MouseController::setMiddleButtonUp()
{
	triggerMouseButtonEvent(MOUSEEVENTF_MIDDLEUP);
}

void MouseController::rollMouseWheelUp()
{
	//???
}

void MouseController::rollMouseWheelDown()
{
	//???
}

void MouseController::triggerMouseButtonEvent(int event)
{
	INPUT input = {0};
	input.type = INPUT_MOUSE;

	input.mi.dwFlags = event;

	SendInput(1, &input, sizeof(INPUT));
}