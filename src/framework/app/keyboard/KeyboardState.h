#ifndef KEYBOARD_STATE_H
#define KEYBOARD_STATE_H

#define KEY_COUNT 1

class KeyboardState
{
public:
	KeyboardState();
	~KeyboardState();

	enum KeyCode
	{
		KEY_ESCAPE = 0
	};

	enum KeyState
	{
		KEY_STATE_UP = 0,
		KEY_STATE_DOWN,
		KEY_STATE_RELEASED
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

	KeyState m_keyDown[KEY_COUNT];
	unsigned int m_keysDownCount;
	bool m_keyReleased;

	friend class KeyboardHandler;
};

#endif