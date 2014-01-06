#ifndef APPLICATION_H
#define APPLICATION_H
 
#include "inputDevice/keyboard/KeyboardState.h"
#include "inputDevice/mouse/MouseState.h"
#include "system/IScreen.h"
#include "system/IComputer.h"
#include "system/IMessageLoop.h"
#include "BaseApplication.h"
#include "framework/math/vector/Vector.h"

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

	KeyboardState getKeyboardState() const;
	MouseState getMouseState() const;

	Vector2i getScreenResolution() const;
	Vector2i getScreenRightBottom() const;

	std::string getComputerName() const;

private:
	void handleKeyboard();
	void handleMouse();

	BaseApplication* m_application;

	bool m_keepRunning;
	KeyboardState m_keyboardState;
	MouseState m_mouseState;

	IScreen* m_screen;
	IComputer* m_computer;
	IMessageLoop* m_messageLoop;

	friend class BaseApplication;
};

#endif