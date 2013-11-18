#ifndef APPLICATION_H
#define APPLICATION_H

#include "keyboard/KeyboardState.h"
#include "mouse/MouseState.h"
#include "BaseApplication.h"

class Application
{
public:
	Application(BaseApplication* baseApplication);
	~Application();

	void setup();
	void update();
	void shutdown();

	bool getKeepRunning();

protected:
	void quit();

private:
	void handleKeyboard();
	void handleMouse();

	BaseApplication* m_application;

	bool m_keepRunning;
	KeyboardState m_keyboardState;
	MouseState m_mouseState;

	friend class BaseApplication;
};

#endif