#include "RemoteMouse.h"
#include <iostream>

RemoteMouse::RemoteMouse()
{}

RemoteMouse::~RemoteMouse()
{}

void RemoteMouse::setup()
{
	std::cout << "setup" << std::endl;

	m_mouseHandler.setup(getScreenResolution(), getScreenBottomRight());

	try
	{
		m_server.setup(Server::PROTOCOL_UDP);
		m_client.setup(Server::PROTOCOL_UDP);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void RemoteMouse::update()
{
	try
	{
		m_server.acceptConnection();
		m_server.receiveMessage();
	}
	catch(std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}
}

void RemoteMouse::keyDown()
{
}

void RemoteMouse::keyUp()
{
}

void RemoteMouse::keyReleased()
{
	if(keyboardState.getKeyReleased(KeyboardState::KEY_S))
	{
		try
		{
			//m_server.broadcast("blablabla");
			m_client.broadcast("foo bar");
		}
		catch(std::exception& exception)
		{
			std::cout << exception.what() << std::endl;
		}
	}
	
	if(keyboardState.getKeyReleased(KeyboardState::KEY_ESCAPE))
	{
		quit();
	}

	if(keyboardState.getKeyReleased(KeyboardState::KEY_SPACE))
	{
		m_mouseHandler.clickLeft();
	}   

	if(keyboardState.getKeyReleased(KeyboardState::KEY_A))
	{
		std::cout << getScreenResolution() << std::endl;
		std::cout << getScreenBottomRight() << std::endl;
		std::cout << getMouseState().getMousePosition() << std::endl;
	}

	if(keyboardState.getKeyReleased(KeyboardState::KEY_H))
	{
		m_mouseHandler.toggleCursor();
	}

	if(keyboardState.getKeyReleased(KeyboardState::KEY_S))
	{
		m_mouseHandler.scrollUp();
	}
	
	if(keyboardState.getKeyReleased(KeyboardState::KEY_W))
	{
		m_mouseHandler.scrollDown();
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
	std::cout << "shutdown" << std::endl;
}