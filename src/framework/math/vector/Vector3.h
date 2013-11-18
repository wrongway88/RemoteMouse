/**
 * Author: Manuel Dobusch
 */

#ifndef VECTOR_3_H
#define VECTOR_3_H

#include "VectorBase.h"

namespace ManuelVector
{
	template<class T>
	class Vector3 : public Vector<T, 3>
	{
	public:
		Vector3();
		Vector3(const T& x, const T& y, const T& z);
		Vector3(const Vector<T, 3>& vector);
		~Vector3();

		T getX() const;
		void setX(const T& value);

		T getY() const;
		void setY(const T& value);

		T getZ() const;
		void setZ(const T& value);

	protected:
		static const unsigned int m_xIndex = 0;
		static const unsigned int m_yIndex = 1;
		static const unsigned int m_zIndex = 2;
	};

	template<class T>
	Vector3<T>::Vector3():
		Vector<T, 3>()
	{
	}

	template<class T>
	Vector3<T>::Vector3(const T& x, const T& y, const T& z):
		Vector<T, 3>()
	{
		setValue(m_xIndex, x);
		setValue(m_yIndex, y);
		setValue(m_zIndex, z);
	}

	template<class T>
	Vector3<T>::Vector3(const Vector<T, 3>& vector):
		Vector<T, 3>(vector)
	{
	}

	template<class T>
	Vector3<T>::~Vector3()
	{
	}

	template<class T>
	T Vector3<T>::getX() const
	{
		return getValue(m_xIndex);
	}

	template<class T>
	void Vector3<T>::setX(const T& value)
	{
		setValue(m_xIndex, value);
	}

	template<class T>
	T Vector3<T>::getY() const
	{
		return getValue(m_yIndex);
	}
	
	template<class T>
	void Vector3<T>::setY(const T& value)
	{
		setValue(m_yIndex, value);
	}

	template<class T>
	T Vector3<T>::getZ() const
	{
		return getValue(m_zIndex);
	}
	
	template<class T>
	void Vector3<T>::setZ(const T& value)
	{
		setValue(m_zIndex, value);
	}



	class Vector3f : public Vector3<float>
	{
	public:
		Vector3f();
		Vector3f(const float x, const float y, const float z);
		Vector3f(const Vector<float, 3>& vector);
		~Vector3f();
	};

	class Vector3i : public Vector3<int>
	{
	public:
		Vector3i();
		Vector3i(const int x, const int y, const int z);
		Vector3i(const Vector<int, 3>& vector);
		~Vector3i();
	};
}

#endif