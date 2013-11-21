#ifndef INPUT_DEVICE_H
#define INPUT_DEVICE_H

class InputDeviceState
{
public:
	InputDeviceState():
		m_keysDownCount(0),
		m_keyReleased(false)
	{}
	virtual ~InputDeviceState(){}

	enum KeyState
	{
		KEY_STATE_UP = 0,
		KEY_STATE_DOWN,
		KEY_STATE_RELEASED
	};

protected:
	unsigned int m_keysDownCount;
	bool m_keyReleased;
};

#endif