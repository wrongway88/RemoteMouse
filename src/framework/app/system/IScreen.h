#ifndef SCREEN_H
#define SCREEN_H

#include "framework/math/vector/Vector.h"

class IScreen
{
public:
	IScreen(){};
	virtual ~IScreen(){};

	virtual Vector2i getScreenSize() const = 0;
	virtual Vector2i getRightBottom() const = 0;

private:
};

#endif