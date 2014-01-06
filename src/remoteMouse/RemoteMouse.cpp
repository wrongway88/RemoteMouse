#include "RemoteMouse.h"
#include <iostream>
#include <Windows.h>

RemoteMouse::RemoteMouse()
{
	debugCounter = 0;
}

RemoteMouse::~RemoteMouse()
{
	std::cout << "RemoteMouse::~RemoteMouse()" << std::endl;
}

void RemoteMouse::setup()
{
	m_mouseHandler.setup(getScreenResolution(), getScreenBottomRight());
	m_networkManager.setup(getComputerName());
}

void RemoteMouse::update()
{
	m_networkManager.update();
}

void RemoteMouse::keyDown()
{
}

void RemoteMouse::keyUp()
{
}

void RemoteMouse::keyReleased()
{
	KeyboardState keyboardState = getKeyboardState();

	if(keyboardState.getKeyReleased(KeyboardState::KEY_S))
	{
	}
	
	if(keyboardState.getKeyReleased(KeyboardState::KEY_ESCAPE))
	{
		quit();
	}

	if(keyboardState.getKeyReleased(KeyboardState::KEY_SPACE))
	{
		//m_mouseHandler.clickLeft();
	}   

	if(keyboardState.getKeyReleased(KeyboardState::KEY_A))
	{
		std::cout << getScreenResolution() << std::endl;
		std::cout << getScreenBottomRight() << std::endl;
		std::cout << getMouseState().getMousePosition() << std::endl;
	}

	if(keyboardState.getKeyReleased(KeyboardState::KEY_B))
	{
		m_mouseHandler.blockMouse(!m_mouseHandler.getMouseBlocked());
	}

	if(keyboardState.getKeyReleased(KeyboardState::KEY_H))
	{
		m_mouseHandler.toggleCursor();
	}
}

void RemoteMouse::mouseMoved()
{
	m_mouseHandler.update(getMouseState().getMousePosition());
}

void RemoteMouse::mouseButtonDown()
{
}

void RemoteMouse::mouseButtonUp()
{
}

void RemoteMouse::mouseButtonReleased()
{
	std::cout << "mouse button released" << std::endl;
}

void RemoteMouse::shutdown()
{
	m_networkManager.shutdown();

	std::cout << "shutdown" << std::endl;
}