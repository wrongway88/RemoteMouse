#ifndef REMOTE_MOUSE_H
#define REMOTE_MOUSE_H

#include "framework/app/BaseApplication.h"

#include "framework/app/network/Server.h"

class RemoteMouse: public BaseApplication
{
public:
	RemoteMouse();
	~RemoteMouse();

	void setup();

	void update();

	virtual void keyDown(const KeyboardState& keyboardState);
	virtual void keyUp(const KeyboardState& keyboardState);
	virtual void keyReleased(const KeyboardState& keyboardState);

	virtual void mouseMoved(const MouseState& mouseState);
	virtual void mouseButtonDown(const MouseState& mouseState);
	virtual void mouseButtonUp(const MouseState& mouseState);
	virtual void mouseButtonReleased(const MouseState& mouseState);

	void shutdown();

private:
	Server m_server;
};

#endif