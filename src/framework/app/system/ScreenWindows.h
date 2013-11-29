#ifndef SCREEN_WINDOWS_H
#define SCREEN_WINDOWS_H

#include "IScreen.h"

class ScreenWindows : public IScreen
{
public:
	ScreenWindows();
	~ScreenWindows();

	virtual Vector2i getScreenSize() const;
	virtual Vector2i getRightBottom() const;

private:

};

#endif