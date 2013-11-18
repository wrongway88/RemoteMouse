#include "Vector3.h"

namespace ManuelVector
{
	Vector3f::Vector3f():
		Vector3<float>(0.0f, 0.0f, 0.0f)
	{
	}

	Vector3f::Vector3f(const float x, const float y, const float z):
		Vector3<float>(x, y, z)
	{
	}

	Vector3f::Vector3f(const Vector<float, 3>& vector):
		Vector3<float>(vector)
	{
	}

	Vector3f::~Vector3f()
	{
	}




	Vector3i::Vector3i():
		Vector3<int>(0, 0, 0)
	{
	}

	Vector3i::Vector3i(const int x, const int y, const int z):
		Vector3<int>(x, y, z)
	{
	}

	Vector3i::Vector3i(const Vector<int, 3>& vector):
		Vector3<int>(vector)
	{
	}

	Vector3i::~Vector3i()
	{
	}
}