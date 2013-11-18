#ifndef BASE_APPLICATION_H
#define BASE_APPLICATION_H

#include "keyboard/KeyboardState.h"
#include "mouse/MouseState.h"

class Application;

class BaseApplication
{
public:
	BaseApplication();
	~BaseApplication();

	void setApplication(Application* application);

	virtual void setup(){}

	virtual void update(){}

	virtual void keyDown(const KeyboardState& keyboardState){}
	virtual void keyUp(const KeyboardState& keyboardState){}
	virtual void keyReleased(const KeyboardState& keyboardState){}

	virtual void mouseMoved(const MouseState& mouseState){}

	virtual void shutdown(){}

protected:
	void quit();

private:
	Application* m_application;
};

#endif