/**
 * Author: Manuel Dobusch
 */

#ifndef VECTOR_2_H
#define VECTOR_2_H

#include "VectorBase.h"

namespace ManuelVector
{
	template<class T>
	class Vector2 : public Vector<T, 2>
	{
	public:
		Vector2();
		Vector2(const T& x, const T& y);
		Vector2(const Vector<T, 2>& vector);
		~Vector2();

		T getX() const;
		void setX(const T& value);

		T getY() const;
		void setY(const T& value);

	protected:
		static const unsigned int m_xIndex = 0;
		static const unsigned int m_yIndex = 1;
	};

	template<class T>
	Vector2<T>::Vector2():
		Vector<T, 2>()
	{
	}

	template<class T>
	Vector2<T>::Vector2(const T& x, const T& y):
		Vector<T, 2>()
	{
		setValue(m_xIndex, x);
		setValue(m_yIndex, y);
	}

	template<class T>
	Vector2<T>::Vector2(const Vector<T, 2>& vector):
		Vector<T, 2>(vector)
	{}

	template<class T>
	Vector2<T>::~Vector2()
	{
	}

	template<class T>
	T Vector2<T>::getX() const
	{
		return getValue(m_xIndex);
	}
	
	template<class T>
	void Vector2<T>::setX(const T& value)
	{
		setValue(m_xIndex, value);
	}

	template<class T>
	T Vector2<T>::getY() const
	{
		return getValue(m_yIndex);
	}
	
	template<class T>
	void Vector2<T>::setY(const T& value)
	{
		setValue(m_yIndex, value);
	}



	class Vector2f : public Vector2<float>
	{
	public:
		Vector2f();
		Vector2f(const float x, const float y);
		Vector2f(const Vector<float, 2>& vector);
		~Vector2f();
	};

	class Vector2i : public Vector2<int>
	{
	public:
		Vector2i();
		Vector2i(const int x, const int y);
		Vector2i(const Vector<int, 2>& vector);
		~Vector2i();
	};
}

#endif