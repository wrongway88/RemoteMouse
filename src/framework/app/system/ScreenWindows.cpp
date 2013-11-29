#include "ScreenWindows.h"

#include <wtypes.h>

ScreenWindows::ScreenWindows()
{}

ScreenWindows::~ScreenWindows()
{}

Vector2i ScreenWindows::getScreenSize() const
{
	Vector2i result(0, 0);

	if(GetSystemMetrics(SM_CMONITORS) <= 1)
	{
		result.setX(GetSystemMetrics(SM_CXSCREEN));
		result.setY(GetSystemMetrics(SM_CYSCREEN));
	}
	else
	{
		result.setX(GetSystemMetrics(SM_CXVIRTUALSCREEN));
		result.setY(GetSystemMetrics(SM_CYVIRTUALSCREEN));
	}

	return result;
}

Vector2i ScreenWindows::getRightBottom() const
{
	Vector2i result(0, 0);

	if(GetSystemMetrics(SM_CMONITORS) <= 1)
	{
		result.setX(GetSystemMetrics(SM_CXSCREEN));
		result.setY(GetSystemMetrics(SM_CYSCREEN));
	}
	else
	{
		result.setX(GetSystemMetrics(SM_XVIRTUALSCREEN) + GetSystemMetrics(SM_CXVIRTUALSCREEN));
		result.setY(GetSystemMetrics(SM_YVIRTUALSCREEN) + GetSystemMetrics(SM_CYVIRTUALSCREEN));
	}

	return result;
}