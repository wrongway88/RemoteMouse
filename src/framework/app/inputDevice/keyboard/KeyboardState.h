#ifndef KEYBOARD_STATE_H
#define KEYBOARD_STATE_H

#define KEYBOARD_KEY_COUNT 1

#include "../InputDeviceState.h"

class KeyboardState : public InputDeviceState
{
public:
	KeyboardState();
	virtual ~KeyboardState();

	enum KeyCode
	{
		KEY_ESCAPE = 0
	};

	KeyState getKeyState(KeyCode keyCode) const;
	bool getKeyDown(KeyCode keyCode) const;
	bool getKeyUp(KeyCode keyCode) const;
	bool getKeyReleased(KeyCode keyCode) const;

	bool getKeysDown() const;
	bool getKeysUp() const;
	bool getKeysReleased() const;

protected:
	void setKeyDown(KeyCode keyCode, bool down);
	void resetKeyReleased();

private:
	void resetKeyStates();

	KeyState m_keyDown[KEYBOARD_KEY_COUNT];

	friend class KeyboardHandler;
};

#endif