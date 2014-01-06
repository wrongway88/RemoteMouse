#include "RemoteMouseHandler.h"

#include <iostream>

RemoteMouseHandler::RemoteMouseHandler():
	m_screenSize(),
	m_screenRightBottom(),
	m_cursorVisible(true),
	m_mouseBlocked(false),
	m_initiated(false)
{
}

RemoteMouseHandler::~RemoteMouseHandler()
{
	std::cout << "RemoteMouseHandler::~RemoteMouseHandler" << std::endl;
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

	if(m_initiated == false)
	{
		if(m_lastMousePosition.getLength() <= 0)
		{
			m_lastMousePosition.setX(mousePosition.getX());
			m_lastMousePosition.setY(mousePosition.getY());
		}

		if(m_absoluteMousePosition.getLength() <= 0)
		{
			m_absoluteMousePosition.setX(mousePosition.getX());
			m_absoluteMousePosition.setY(mousePosition.getY());
		}

		m_initiated = true;
	}

	int x = mousePosition.getX() - m_lastMousePosition.getX();
	int y = mousePosition.getY() - m_lastMousePosition.getY();

	m_absoluteMousePosition += Vector2i(x, y);

	//std::cout << mousePosition << " | mousePos: " << m_absoluteMousePosition << ", delta: " << x << ", " << y << std::endl;

	//std::cout << mousePosition << "| " << m_lastMousePosition << "| " << delta << "| " << x << " " << y << std::endl;

	if(mousePosition.getX() == m_screenLeftTop.getX())
	{
		MouseController::setMousePosition(Vector2i(m_screenRightBottom.getX() - 2 ,mousePosition.getY()));

		m_lastMousePosition.setX(m_screenRightBottom.getX() - 2);
		m_lastMousePosition.setY(mousePosition.getY());
	}
	else if(mousePosition.getX() == (m_screenRightBottom.getX()-1))
	{
		MouseController::setMousePosition(Vector2i(m_screenLeftTop.getX() + 1 ,mousePosition.getY()));

		m_lastMousePosition.setX(m_screenLeftTop.getX() + 1);
		m_lastMousePosition.setY(mousePosition.getY());
	}
	else
	{
		m_lastMousePosition.setX(mousePosition.getX());
		m_lastMousePosition.setY(mousePosition.getY());
	}
}

void RemoteMouseHandler::blockMouse(bool blockMouse)
{
	m_mouseBlocked = blockMouse;
	m_mouseHookTest.setMouseBlocked(blockMouse);
}

bool RemoteMouseHandler::getMouseBlocked()
{
	return m_mouseBlocked;
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