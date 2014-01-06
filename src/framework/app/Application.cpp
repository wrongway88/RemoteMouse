#include "Application.h"

#include "inputDevice/keyboard/KeyboardHandler.h"
#include "inputDevice/mouse/MouseHandler.h"
#include "system/ScreenWindows.h"
#include "system/ComputerWindows.h"
#include "system/MessageLoopWindows.h"

#include <iostream>

Application::Application(BaseApplication* baseApplication):
	m_application(baseApplication),
	m_keepRunning(true),
	m_keyboardState(),
	m_screen(NULL),
	m_computer(NULL),
	m_messageLoop(NULL)
{
	m_application->setApplication(this);
}

Application::~Application()
{
	if(m_screen != NULL)
	{
		delete m_screen; 
	}

	if(m_computer != NULL)
	{
		delete m_computer;
	}

	if(m_messageLoop != NULL)
	{
		delete m_messageLoop;
	}

	if(m_application != NULL)
	{
		delete m_application;
	}
}

void Application::setup()
{
	if(m_application != NULL)
	{
		m_screen = new ScreenWindows();
		m_computer = new ComputerWindows();
		m_messageLoop = new MessageLoopWindows();

		m_application->setup();
	}
}

void Application::update()
{
	if(m_application != NULL)
	{
		handleKeyboard();
		handleMouse();

		m_application->update();
	}

	if(m_messageLoop != NULL)
	{
		m_messageLoop->getMessage();
	}
}

void Application::shutdown()
{
	if(m_application != NULL)
	{
		m_application->shutdown();
	}
}

bool Application::getKeepRunning()
{
	if(m_application != NULL)
	{
		return m_keepRunning;
	}
	else
	{
		return false;
	}
}

void Application::quit()
{
	m_keepRunning = false;
}

KeyboardState Application::getKeyboardState() const
{
	return m_keyboardState;
}

MouseState Application::getMouseState() const
{
	return m_mouseState;
}

Vector2i Application::getScreenResolution() const
{
	if(m_screen != NULL)
	{
		return m_screen->getScreenSize();
	}
	else
	{
		return Vector2i(0, 0);
	}
}

Vector2i Application::getScreenRightBottom() const
{
	if(m_screen != NULL)
	{
		return m_screen->getRightBottom();
	}
	else
	{
		return Vector2i(0, 0);
	}
}

std::string Application::getComputerName() const
{
	if(m_computer != NULL)
	{
		return m_computer->getName();
	}
	else
	{
		return "unknown";
	}
}

void Application::handleKeyboard()
{
	KeyboardHandler::updateKeyboardState(m_keyboardState);

	if(m_keyboardState.getKeysDown())
	{
		m_application->keyDown();
	}
	if(m_keyboardState.getKeysUp())
	{
		m_application->keyUp();
	}
	if(m_keyboardState.getKeysReleased())
	{
		m_application->keyReleased();
	}
}

void Application::handleMouse()
{
	MouseHandler::updateMouseState(m_mouseState);

	if(m_mouseState.getMouseMoved())
	{
		m_application->mouseMoved();
	}
	if(m_mouseState.getKeysDown())
	{
		m_application->mouseButtonDown();
	}
	if(m_mouseState.getKeysUp())
	{
		m_application->mouseButtonUp();
	}
	if(m_mouseState.getKeysReleased())
	{
		m_application->mouseButtonReleased();
	}
}