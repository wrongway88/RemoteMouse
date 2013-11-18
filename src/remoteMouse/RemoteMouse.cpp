#include "RemoteMouse.h"
#include <iostream>

RemoteMouse::RemoteMouse()
{}

RemoteMouse::~RemoteMouse()
{}

void RemoteMouse::setup()
{
	std::cout << "setup" << std::endl;
}

void RemoteMouse::update()
{
	//std::cout << "update" << std::endl;
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
	ManuelVector::Vector2f mousePosition = mouseState.getMousePosition();
	std::cout << "mouse moved [" << mousePosition.getX() << ", " << mousePosition.getY() << "]" << std::endl;
}

void RemoteMouse::shutdown()
{
	std::cout << "shutdown" << std::endl;
}