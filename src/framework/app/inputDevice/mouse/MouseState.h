#ifndef MOUSE_STATE_H
#define MOUSE_STATE_H

#define MOUSE_KEY_COUNT 3

#include "framework/math/vector/Vector2.h"
#include "../InputDeviceState.h"

class MouseState : public InputDeviceState
{
public:
	MouseState();
	~MouseState();

	enum KeyCode
	{
		KEY_LEFT = 0,
		KEY_RIGHT,
		KEY_CENTER
	};

	ManuelVector::Vector2f getMousePosition() const;

	KeyState getKeyState(KeyCode keyCode) const;
	bool getKeyDown(KeyCode keyCode) const;
	bool getKeyUp(KeyCode keyCode) const;
	bool getKeyReleased(KeyCode keyCode) const;

	bool getKeysDown() const;
	bool getKeysUp() const;
	bool getKeysReleased() const;
	bool getMouseMoved() const;

protected:
	void setMousePosition(ManuelVector::Vector2f& position);
	void resetMouseMoved();
	void setKeyDown(KeyCode keyCode, bool down);
	void resetKeyReleased();

private:
	void resetKeyStates();

	ManuelVector::Vector2f m_mousePosition;
	KeyState m_keyDown[MOUSE_KEY_COUNT];

	bool m_mouseMoved;

	friend class MouseHandler;
};

#endif