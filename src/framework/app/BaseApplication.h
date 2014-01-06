#ifndef BASE_APPLICATION_H
#define BASE_APPLICATION_H

#include "inputDevice/keyboard/KeyboardState.h"
#include "inputDevice/mouse/MouseState.h"
#include "framework/math/vector/Vector.h"

class Application;

class BaseApplication
{
public:
	BaseApplication();
	virtual ~BaseApplication();

	void setApplication(Application* application);

	virtual void setup(){}

	virtual void update(){}

	virtual void keyDown(){}
	virtual void keyUp(){}
	virtual void keyReleased(){}

	virtual void mouseMoved(){}
	virtual void mouseButtonDown(){}
	virtual void mouseButtonUp(){}
	virtual void mouseButtonReleased(){}

	virtual void shutdown(){}

protected:
	void quit();

	KeyboardState getKeyboardState() const;
	MouseState getMouseState() const;

	Vector2i getScreenResolution() const;
	Vector2i getScreenBottomRight() const;

	std::string getComputerName() const;

private:
	Application* m_application;
};

#endif