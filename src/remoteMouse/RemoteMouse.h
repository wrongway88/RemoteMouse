#ifndef REMOTE_MOUSE_H
#define REMOTE_MOUSE_H

#include "framework/app/BaseApplication.h"

class RemoteMouse: public BaseApplication
{
public:
	RemoteMouse();
	~RemoteMouse();

	void setup();

	void update();

	void keyDown(const KeyboardState& keyboardState);
	void keyUp(const KeyboardState& keyboardState);
	void keyReleased(const KeyboardState& keyboardState);

	void mouseMoved(const MouseState& mouseState);

	void shutdown();
};

#endif