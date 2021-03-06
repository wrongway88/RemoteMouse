#ifndef KEYBOARD_STATE_H
#define KEYBOARD_STATE_H

#define KEYBOARD_KEY_COUNT 12

#include "../InputDeviceState.h"

class KeyboardState : public InputDeviceState
{
public:
	KeyboardState();
	virtual ~KeyboardState();

	enum KeyCode
	{
		KEY_ESCAPE = 0,
		KEY_SPACE,
		KEY_ARROW_UP,
		KEY_ARROW_DOWN,
		KEY_A,
		KEY_B,
		KEY_C,
		KEY_H,
		KEY_S,
		KEY_V,
		KEY_W
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