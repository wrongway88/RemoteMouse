#ifndef REMOTE_MOUSE_HANDLER_H
#define REMOTE_MOUSE_HANDLER_H

#include "framework/math/vector/Vector.h"
#include "framework/app/inputDevice/mouse/MouseController.h"
#include "MouseHookTest.h"

class RemoteMouseHandler
{
public:
	RemoteMouseHandler();
	~RemoteMouseHandler();

	void setup(Vector2i& screenSize, Vector2i& screenRightBottom);

	void update(const Vector2i& mousePosition);

	void clickLeft() const;

	void scrollUp() const;
	void scrollDown() const;

	void toggleCursor();

private:
	Vector2i m_screenSize;
	Vector2i m_screenRightBottom;
	Vector2i m_screenLeftTop;

	bool m_cursorVisible;

	MouseHookTest m_mouseHookTest;
};

#endif