#include "RemoteMouseHandler.h"

#include <iostream>

RemoteMouseHandler::RemoteMouseHandler():
	m_screenSize(),
	m_screenRightBottom(),
	m_cursorVisible(true)
{
}

RemoteMouseHandler::~RemoteMouseHandler()
{
}

void RemoteMouseHandler::setup(Vector2i& screenSize, Vector2i& screenRightBottom)
{
	m_screenSize = screenSize;
	m_screenRightBottom = screenRightBottom;
	m_screenLeftTop = Vector2i(m_screenRightBottom - screenSize);

	m_mouseHookTest.setup();
}

void RemoteMouseHandler::update(const Vector2i& mousePosition)
{
	//std::cout << "mousePos: " << mousePosition << " | rightBottom: " << m_screenRightBottom << " | leftTop: " << m_screenLeftTop << std::endl;

	if(mousePosition.getX() == m_screenLeftTop.getX())
	{
		MouseController::setMousePosition(Vector2i(m_screenRightBottom.getX() - 2 ,mousePosition.getY()));
	}
	else if(mousePosition.getX() == (m_screenRightBottom.getX()-1))
	{
		MouseController::setMousePosition(Vector2i(m_screenLeftTop.getX() + 1 ,mousePosition.getY()));
	}
}

void RemoteMouseHandler::clickLeft() const
{
	MouseController::setLeftButtonDown();
	MouseController::setLeftButtonUp();
}

void RemoteMouseHandler::scrollUp() const
{
	MouseController::rollMouseWheelUp();
}

void RemoteMouseHandler::scrollDown() const
{
	MouseController::rollMouseWheelDown();
}

void RemoteMouseHandler::toggleCursor()
{
	m_cursorVisible = !m_cursorVisible;
	MouseController::setCursorVisible(m_cursorVisible);
}