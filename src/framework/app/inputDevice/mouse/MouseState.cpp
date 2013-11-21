#include "MouseState.h"

MouseState::MouseState():
	m_mousePosition(),
	m_mouseMoved(false)
{
	resetKeyStates();
}

MouseState::~MouseState()
{}

ManuelVector::Vector2f MouseState::getMousePosition() const
{
	return m_mousePosition;
}

MouseState::KeyState MouseState::getKeyState(KeyCode keyCode) const
{
	if(keyCode >= 0 && keyCode < MOUSE_KEY_COUNT)
	{
		return m_keyDown[keyCode];
	}
	else
	{
		throw(std::exception("Invalid key code"));
	}
}

bool MouseState::getKeyDown(KeyCode keyCode) const
{
	return (getKeyState(keyCode) == KEY_STATE_DOWN);
}

bool MouseState::getKeyUp(KeyCode keyCode) const
{
	return (getKeyState(keyCode) == KEY_STATE_UP);
}

bool MouseState::getKeyReleased(KeyCode keyCode) const
{
	return (getKeyState(keyCode) == KEY_STATE_RELEASED);
}

bool MouseState::getKeysDown() const
{
	return m_keysDownCount > 0;
}

bool MouseState::getKeysUp() const
{
	return m_keysDownCount < MOUSE_KEY_COUNT;
}

bool MouseState::getKeysReleased() const
{
	return m_keyReleased;
}

bool MouseState::getMouseMoved() const
{
	return m_mouseMoved;
}

void MouseState::setMousePosition(ManuelVector::Vector2f& position)
{
	if(position != m_mousePosition)
	{
		m_mouseMoved = true;
	}

	m_mousePosition = position;
}

void MouseState::resetMouseMoved()
{
	m_mouseMoved = false;
}

void MouseState::setKeyDown(KeyCode keyCode, bool down)
{
	if(keyCode >= 0 && keyCode < MOUSE_KEY_COUNT)
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

void MouseState::resetKeyReleased()
{
	m_keyReleased = false;

	for(unsigned i = 0; i < MOUSE_KEY_COUNT; i++)
	{
		if(m_keyDown[i] == KEY_STATE_RELEASED)
		{
			m_keyDown[i] = KEY_STATE_UP;
		}
	}
}

void MouseState::resetKeyStates()
{
	for(unsigned i = 0; i < MOUSE_KEY_COUNT; i++)
	{
		m_keyDown[i] = KEY_STATE_UP;
	}
}