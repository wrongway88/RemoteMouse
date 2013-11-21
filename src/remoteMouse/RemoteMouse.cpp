#include "RemoteMouse.h"
#include <iostream>

RemoteMouse::RemoteMouse()
{}

RemoteMouse::~RemoteMouse()
{}

void RemoteMouse::setup()
{
	std::cout << "setup" << std::endl;

	try
	{
		m_server.setup(Server::PROTOCOL_TCP);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void RemoteMouse::update()
{
	//std::cout << "update" << std::endl;

	m_server.acceptConnection();
}

void RemoteMouse::keyDown(const KeyboardState& keyboardState)
{
	//std::cout << "keydown" << std::endl;
}

void RemoteMouse::keyUp(const KeyboardState& keyboardState)
{
	//std::cout << "keyup" << std::endl;
}

void RemoteMouse::keyReleased(const KeyboardState& keyboardState)
{
	std::cout << "keyreleased" << std::endl;

	if(keyboardState.getKeyReleased(KeyboardState::KEY_ESCAPE))
	{
		quit();
	}
}

void RemoteMouse::mouseMoved(const MouseState& mouseState)
{
	//ManuelVector::Vector2f mousePosition = mouseState.getMousePosition();
	//std::cout << "mouse moved [" << mousePosition.getX() << ", " << mousePosition.getY() << "]" << std::endl;
}

void RemoteMouse::mouseButtonDown(const MouseState& mouseState)
{
	//std::cout << "mouse button down" << std::endl;
}

void RemoteMouse::mouseButtonUp(const MouseState& mouseState)
{
	//std::cout << "mouse button up" << std::endl;
}

void RemoteMouse::mouseButtonReleased(const MouseState& mouseState)
{
	std::cout << "mouse button released" << std::endl;
}

void RemoteMouse::shutdown()
{
	std::cout << "shutdown" << std::endl;
}