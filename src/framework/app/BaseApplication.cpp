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