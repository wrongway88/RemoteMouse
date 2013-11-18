#include "Application.h"

#include "keyboard/KeyboardHandler.h"
#include "mouse/MouseHandler.h"

#include <iostream>

Application::Application(BaseApplication* baseApplication):
	m_application(baseApplication),
	m_keepRunning(true),
	m_keyboardState()
{
	m_application->setApplication(this);
}

Application::~Application()
{
	delete m_application;
}

void Application::setup()
{
	m_application->setup();
}

void Application::update()
{
	handleKeyboard();
	handleMouse();

	m_application->update();
}

void Application::shutdown()
{
	m_application->shutdown();
}

bool Application::getKeepRunning()
{
	return m_keepRunning;
}

void Application::quit()
{
	m_keepRunning = false;
}

void Application::handleKeyboard()
{
	KeyboardHandler::updateKeyboardState(m_keyboardState);

	if(m_keyboardState.getKeysDown())
	{
		m_application->keyDown(m_keyboardState);
	}
	if(m_keyboardState.getKeysUp())
	{
		m_application->keyUp(m_keyboardState);
	}
	if(m_keyboardState.getKeysReleased())
	{
		m_application->keyReleased(m_keyboardState);
	}
}

void Application::handleMouse()
{
	MouseHandler::updateMouseState(m_mouseState);

	if(m_mouseState.getMouseMoved())
	{
		m_application->mouseMoved(m_mouseState);
	}
}