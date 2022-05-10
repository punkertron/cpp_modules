#pragma once

#include <stdexcept>

template <typename T>
class Array
{
private:
	T* arr;
	unsigned int	m_size;

public:
	Array(): arr(NULL), m_size(0){}

	Array(unsigned int n): m_size(n)
	{
		arr = new T[n];
	}

	~Array()
	{
		if (arr)
			delete [] arr;
	}

	Array(const Array<T> &a): m_size(a.m_size)
	{
		arr = new T[a.m_size];
		for (unsigned int i = 0; i < a.m_size; i++)
			arr[i] = a.arr[i];
	}

	Array<T>& operator=(const Array<T> &a)
	{
		m_size = a.m_size;
		if (arr)
			delete[] arr;
		arr = new T[a.m_size];
		for (unsigned int i = 0; i < a.m_size; i++)
			arr[i] = a.arr[i];
		return (*this);
	}

	unsigned int size() const
	{
		return (m_size);
	}

	T& operator[](unsigned int i)
	{
		if (i >= m_size)
			throw std::out_of_range("Input index >= size of array");
		return (arr[i]);
	}

	const T& operator[](unsigned int i) const
	{
		if (i >= m_size)
			throw std::out_of_range("Input index >= size of array");
		return (arr[i]);
	}
};