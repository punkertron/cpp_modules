#include "PmergeMe.hpp"
#include <iostream>

//vector
static void InsertionSort(std::vector<unsigned int> &vec)
{
	unsigned int value, hole;

	for (int i = 1, size = vec.size(); i < size; ++i)
	{
		value = vec[i];
		hole = i;

		while (hole > 0 && vec[hole - 1] > value)
		{
			vec[hole] = vec[hole - 1];
			--hole;
		}
		vec[hole] = value;
	}
}

void MergeInsertSort(std::vector<unsigned int> &vec)
{
	for (int i = 0, size = vec.size(); i < size; ++i, ++i)
	{
		if (i + 1 < size && vec[i] < vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
	}

	std::vector<unsigned int> largest, smallest;
	for(int i = 0, size = vec.size(); i < size; ++i, ++i)
	{
		largest.push_back(vec[i]);
		if (i + 1 < size)
			smallest.push_back(vec[i + 1]);
	}

	unsigned int nL = largest.size(), nS = smallest.size();
	unsigned int i = 0, j = 0, k = 0;

	InsertionSort(largest);
	InsertionSort(smallest);

	while (i < nL && j < nS)
	{
		if (largest[i] <= smallest[j])
		{
			vec[k] = largest[i];
			++i;
		}
		else
		{
			vec[k] = smallest[j];
			++j;
		}
		++k;
	}

	while (i < nL)
	{
		vec[k] = largest[i];
		++i;
		++k;
	}
	while (j < nS)
	{
		vec[k] = smallest[j];
		++j;
		++k;
	}
}

//list
static void InsertionSort(std::list<unsigned int> &l)
{
	unsigned int value;
	std::list<unsigned int>::iterator temp;

	for (std::list<unsigned int>::iterator it = ++l.begin(); it != l.end(); ++it)
	{
		value = *it;
		temp = it;

		while (temp != l.begin() && *std::prev(temp) > value)
		{
			*temp = *std::prev(temp);
			--temp;
		}
		*temp = value;
		
	}
}

void MergeInsertSort(std::list<unsigned int> &l)
{
	for (std::list<unsigned int>::iterator it = l.begin(), end = l.end(); it != end; ++it)
	{
		if (std::next(it) != end && *it < *std::next(it))
			std::swap(*it, *std::next(it));
		++it;
		if (it == l.end())
			break;
	}

	std::list<unsigned int> largest, smallest;
	for (std::list<unsigned int>::iterator it = l.begin(), end = l.end(); it != end; ++it)
	{
		largest.push_back(*it);
		if (std::next(it) != end)
			smallest.push_back(*std::next(it));
		++it;
		if (it == l.end())
			break;
	}

	InsertionSort(largest);
	InsertionSort(smallest);

	std::list<unsigned int>::iterator nL = largest.end(), nS = smallest.end(),
		i = largest.begin(), j = smallest.begin(), k = l.begin();
	
	/*
	unsigned int nL = largest.size(), nS = smallest.size();
	unsigned int i = 0, j = 0, k = 0;
	*/

	while (i != nL && j != nS)
	{
		if (*i <= *j)
		{
			*k = *i;
			++i;
		}
		else
		{
			*k = *j;
			++j;
		}
		++k;
	}

	while (i != nL)
	{
		*k = *i;
		++i;
		++k;
	}
	while (j != nS)
	{
		*k = *j;
		++j;
		++k;
	}
}
