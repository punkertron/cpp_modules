#pragma once


template <typename T>

void	iter(T * arr, int len, void (*f)(T& r))
{
	for (int i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}
