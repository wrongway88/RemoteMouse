#ifndef MOUSE_STATE_H
#define MOUSE_STATE_H

#include "framework/math/vector/Vector2.h"

class MouseState
{
public:
	MouseState();
	~MouseState();

	ManuelVector::Vector2f getMousePosition() const;

	bool getMouseMoved() const;

protected:
	void setMousePosition(ManuelVector::Vector2f& position);
	void resetMouseMoved();

private:
	ManuelVector::Vector2f m_mousePosition;

	bool m_mouseMoved;

	friend class MouseHandler;
};

#endif