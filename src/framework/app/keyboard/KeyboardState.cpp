#include "KeyboardState.h"

#include <exception>

KeyboardState::KeyboardState():
	m_keysDownCount(0),
	m_keyReleased(false)
{
	resetKeyStates();
}

KeyboardState::~KeyboardState()
{}

KeyboardState::KeyState KeyboardState::getKeyState(KeyCode keyCode) const
{
	if(keyCode >= 0 && keyCode < KEY_COUNT)
	{
		return m_keyDown[keyCode];
	}
	else
	{
		throw(std::exception("Invalid key code"));
	}
}

bool KeyboardState::getKeyDown(KeyCode keyCode) const
{
	return (getKeyState(keyCode) == KEY_STATE_DOWN);
}

bool KeyboardState::getKeyUp(KeyCode keyCode) const
{
	return (getKeyState(keyCode) == KEY_STATE_UP);
}

bool KeyboardState::getKeyReleased(KeyCode keyCode) const
{
	return (getKeyState(keyCode) == KEY_STATE_RELEASED);
}

bool KeyboardState::getKeysDown() const
{
	return m_keysDownCount > 0;
}

bool KeyboardState::getKeysUp() const
{
	return m_keysDownCount < KEY_COUNT;
}

bool KeyboardState::getKeysReleased() const
{
	return m_keyReleased;
}

void KeyboardState::setKeyDown(KeyCode keyCode, bool down)
{
	if(keyCode >= 0 && keyCode < KEY_COUNT)
	{
		KeyState newState = KEY_STATE_DOWN;
		if(!down)
		{
			newState = KEY_STATE_UP;

			if(m_keyDown[keyCode] != newState)
			{
				newState = KEY_STATE_RELEASED;
			}
		}

		if(m_keyDown[keyCode] != newState)
		{
			if(newState == KEY_STATE_DOWN)
			{
				m_keysDownCount++;
			}
			else if(newState == KEY_STATE_RELEASED)
			{
				m_keysDownCount--;
				m_keyReleased = true;
			}
		}

		m_keyDown[keyCode] = newState;
	}
	else
	{
		throw(std::exception("Invalid key code"));
	}
}

void KeyboardState::resetKeyReleased()
{
	m_keyReleased = false;

	for(unsigned int i = 0; i < KEY_COUNT; i++)
	{
		if(m_keyDown[i] == KEY_STATE_RELEASED)
		{
			m_keyDown[i] = KEY_STATE_UP;
		}
	}
}

void KeyboardState::resetKeyStates()
{
	for(unsigned int i = 0; i < KEY_COUNT; i++)
	{
		m_keyDown[i] = KEY_STATE_UP;
	}
}