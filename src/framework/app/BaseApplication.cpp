#include "BaseApplication.h"

#include "Application.h"

BaseApplication::BaseApplication():
	m_application(nullptr)
{}

BaseApplication::~BaseApplication()
{}

void BaseApplication::setApplication(Application* application)
{
	m_application = application;
}

void BaseApplication::quit()
{
	m_application->quit();
}

KeyboardState BaseApplication::getKeyboardState() const
{
	return m_application->getKeyboardState();
}

MouseState BaseApplication::getMouseState() const
{
	return m_application->getMouseState();
}

Vector2i BaseApplication::getScreenResolution() const
{
	return m_application->getScreenResolution();
}
 
Vector2i BaseApplication::getScreenBottomRight() const
{
	return m_application->getScreenRightBottom();
}

std::string BaseApplication::getComputerName() const
{
	return m_application->getComputerName();
}