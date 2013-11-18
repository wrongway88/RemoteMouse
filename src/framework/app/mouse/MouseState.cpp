#include "MouseState.h"

MouseState::MouseState():
	m_mousePosition(),
	m_mouseMoved(false)
{}

MouseState::~MouseState()
{}

ManuelVector::Vector2f MouseState::getMousePosition() const
{
	return m_mousePosition;
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