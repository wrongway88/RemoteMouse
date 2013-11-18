#include "Vector2.h"

namespace ManuelVector
{
	Vector2f::Vector2f():
		Vector2<float>(0.0f, 0.0f)
	{
	}

	Vector2f::Vector2f(const float x, const float y):
		Vector2<float>(x, y)
	{
	}

	Vector2f::Vector2f(const Vector<float, 2>& vector):
		Vector2<float>(vector)
	{
	}

	Vector2f::~Vector2f()
	{
	}




	Vector2i::Vector2i():
		Vector2<int>(0, 0)
	{
	}

	Vector2i::Vector2i(const int x, const int y):
		Vector2<int>(x, y)
	{
	}

	Vector2i::Vector2i(const Vector<int, 2>& vector):
		Vector2<int>(vector)
	{
	}

	Vector2i::~Vector2i()
	{
	}
}