/**
 * Author: Manuel Dobusch
 */

#ifndef VECTOR_BASE_H
#define VECTOR_BASE_H

#include <exception>
#include <sstream>
#include <string>

namespace ManuelVector
{
	#define VECTOR_CHECK_INDEX(idx) \
		do \
		{ \
			unsigned int i((idx)); \
			checkIndexInRange(i, __FUNCTION__); \
		} \
		while(0) \


	template<class T, unsigned int N>
	class Vector
	{
	public:
		Vector();
		Vector(const T values[N]);
		Vector(const Vector<T, N>& vector);
		~Vector();

		T getValue(const unsigned int index) const;
		void setValue(const unsigned int index, const T& value);

		unsigned int getDimensions() const;

		float getLengthSquared() const;
		float getLength() const;

		Vector<T, N> normalize();
		Vector<T, N> normalized() const;

		Vector<T, N> add(const Vector<T, N>& other);
		Vector<T, N> substract(const Vector<T, N>& other);
		Vector<T, N> scalarMultiplication(const float scalar);
		float dotProduct(const Vector<T, N>& other);

		//checks whether all values are the same
		bool isEqual(const Vector<T, N>& other) const;
		//checks whether it really is the same object (at one and the same memory address)
		bool isSame(const Vector<T, N>& other) const;

		T& operator[](const unsigned int index);

		void operator=(Vector<T, N>& other);

		Vector<T, N> operator+(const Vector<T, N>& other) const;
		Vector<T, N> operator-(const Vector<T, N>& other) const;
		Vector<T, N> operator*(const float scalar) const;
		float operator*(const Vector<T, N>& other) const;
		Vector<T, N> operator/(const float scalar) const;

		Vector<T, N> operator+=(const Vector<T, N>& other);
		Vector<T, N> operator-=(const Vector<T, N>& other);
		Vector<T, N> operator*=(const float scalar);
		Vector<T, N> operator/=(const float scalar);

		//checks whether all values are the same
		bool operator==(const Vector<T, N>& other) const;
		//checks whether at least one value is different
		bool operator!=(const Vector<T, N>& other) const;

	private:
		inline void checkIndexInRange(unsigned int index, const std::string& function) const
		{
			if(index >= m_dimensions)
			{
				std::stringstream message;
				message << function << ": index " << index << " is out of range, maximum is " << m_dimensions-1;
				throw(std::exception(message.str().c_str()));
			}
		}
		inline void setValues(const T values[N])
		{
			for(unsigned int i = 0; i < m_dimensions; i++)
			{
				m_values[i] = values[i];
			}
		}

		T m_values[N];
		const unsigned int m_dimensions;
	};


	template<class T, unsigned int N>
	Vector<T, N>::Vector():
		m_dimensions(N)
	{}

	template<class T, unsigned int N>
	Vector<T, N>::Vector(const T values[N]):
		m_dimensions(N)
	{
		setValues(values);
	}

	template<class T, unsigned int N>
	Vector<T, N>::Vector(const Vector<T, N>& vector):
		m_dimensions(vector.m_dimensions)
	{
		setValues(vector.m_values);
	}

	template<class T, unsigned int N>
	Vector<T, N>::~Vector()	
	{
	}

	template<class T, unsigned int N>
	T Vector<T, N>::getValue(const unsigned int index) const
	{
		VECTOR_CHECK_INDEX(index);

		return m_values[index];
	}

	template<class T, unsigned int N>
	void Vector<T, N>::setValue(const unsigned int index, const T& value)
	{
		VECTOR_CHECK_INDEX(index);

		m_values[index] = value;
	}

	template<class T, unsigned int N>
	unsigned int Vector<T, N>::getDimensions() const
	{
		return m_dimensions;
	}

	template<class T, unsigned int N>
	float Vector<T, N>::getLengthSquared() const
		{
			float result = 0.0f;

			for(unsigned int i = 0; i < m_dimensions; i++)
			{
				result += float(m_values[i] * m_values[i]);
			}

			return result;
		}

	template<class T, unsigned int N>
	float Vector<T, N>::getLength() const
	{
		return std::sqrtf(getLengthSquared());
	}

	template<class T, unsigned int N>
	Vector<T, N> Vector<T, N>::normalize()
	{
		float length = getLength();

		T tmpValues[N];
		for(unsigned int i = 0; i < m_dimensions; i++)
		{
			tmpValues[i] = (T)((float)m_values[i] / length);
		}

		//the values of *this won't be changed until all are in a valid state
		setValues(tmpValues);

		return *this;
	}

	template<class T, unsigned int N>
	Vector<T, N> Vector<T, N>::normalized() const
	{
		float length = getLength();

		T tmpValues[N];
		for(unsigned int i = 0; i < m_dimensions; i++)
		{
			tmpValues = (T)((float)m_values[i] / length);
		}

		return Vector<T, N>(tmpValues);
	}

	template<class T, unsigned int N>
	Vector<T, N> Vector<T, N>::add(const Vector<T, N>& other)
	{
		T tmpValues[N];
		for(unsigned int i = 0; i < m_dimensions; i++)
		{
			tmpValues[i] = m_values[i] + other.m_values[i];
		}

		//the values of *this won't be changed until all are in a valid state
		setValues(tmpValues);
		return *this;
	}

	template<class T, unsigned int N>
	Vector<T, N> Vector<T, N>::substract(const Vector<T, N>& other)
	{
		T tmpValues[N];
		for(unsigned int i = 0; i < m_dimensions; i++)
		{
			tmpValues[i] = m_values[i] - other.m_values[i];
		}

		//the values of *this won't be changed until all are in a valid state
		setValues(tmpValues);
		return *this;
	}

	template<class T, unsigned int N>
	Vector<T, N> Vector<T, N>::scalarMultiplication(const float scalar)
		{
			T tmpValues[N];
			for(unsigned int i = 0; i < m_dimensions; i++)
			{
				tmpValues[i] = m_values[i] * scalar;
			}

			//the values of *this won't be changed until all are in a valid state
			setValues(tmpValues);
			return *this;
		}

	template<class T, unsigned int N>
	float Vector<T, N>::dotProduct(const Vector<T, N>& other)
	{
		float result = 0.0f;
		for(unsigned int i = 0; i < m_dimensions; i++)
		{
			result += (m_values[i]*other.m_values[i]);
		}
		return result;
	}

	template<class T, unsigned int N>
	bool Vector<T, N>::isEqual(const Vector<T, N>& other) const
	{
		if(m_dimensions != other.m_dimensions)
		{
			return false;
		}

		for(unsigned int i = 0; i < m_dimensions; i++)
		{
			if(m_values[i] != other.m_values[i])
			{
				return false;
			}
		}

		return true;
	}

	template<class T, unsigned int N>
	bool Vector<T, N>::isSame(const Vector<T, N>& other) const
	{
		return &other == this;
	}

	template<class T, unsigned int N>
	T& Vector<T, N>::operator[](const unsigned int index)
	{
		VECTOR_CHECK_INDEX(index);

		return m_values[index];
	}

	template<class T, unsigned int N>
	void Vector<T, N>::operator=(Vector<T, N>& other)
	{
		if(isSame(other))
		{
			return;
		}

		if(isEqual(other))
		{
			return;
		}

		setValues(other.m_values);
	}

	template<class T, unsigned int N>
	Vector<T, N> Vector<T, N>::operator+(const Vector<T, N>& other) const
	{
		Vector<T, N> result(*this);
		return result.add(other);
	}

	template<class T, unsigned int N>
	Vector<T, N> Vector<T, N>::operator-(const Vector<T, N>& other) const
	{
		Vector<T, N> result(*this);
		return result.substract(other);
	}

	template<class T, unsigned int N>
	Vector<T, N> Vector<T, N>::operator*(const float scalar) const
	{
		Vector<T, N> result(*this);
		return result.scalarMultiplication(scalar);
	}

	template<class T, unsigned int N>
	float Vector<T, N>::operator*(const Vector<T, N>& other) const
	{
		return dotProduct(other);
	}

	template<class T, unsigned int N>
	Vector<T, N> Vector<T, N>::operator/(const float scalar) const
	{
		Vector<T, N> result(*this);
		return result.scalarMultiplication(1.0f/scalar);
	}

	template<class T, unsigned int N>
	Vector<T, N> Vector<T, N>::operator+=(const Vector<T, N>& other)
	{
		return add(other);
	}

	template<class T, unsigned int N>
	Vector<T, N> Vector<T, N>::operator-=(const Vector<T, N>& other)
	{
		return substract(other);
	}

	template<class T, unsigned int N>
	Vector<T, N> Vector<T, N>::operator/=(const float scalar)
	{
		return scalarMultiplication(1.0f/scalar);
	}

	template<class T, unsigned int N>
	bool Vector<T, N>::operator==(const Vector<T, N>& other) const
	{
		return isEqual(other);
	}

	template<class T, unsigned int N>
	bool Vector<T, N>::operator!=(const Vector<T, N>& other) const
	{
		return !isEqual(other);
	}


	template<class T, unsigned int N>
	std::ostream& operator<<(std::ostream& ostream, const Vector<T, N>& vector)
	{
		for(unsigned int i = 0; i < vector.getDimensions()-1; i++)
		{
			ostream << vector.getValue(i) << ", ";
		}
		ostream << vector.getValue(vector.getDimensions()-1);

		return ostream;
	}
}

#endif