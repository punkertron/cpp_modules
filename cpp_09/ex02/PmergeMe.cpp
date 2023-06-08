#include "PmergeMe.hpp"

static void vec_InsertionSort(std::vector<unsigned int> &vec)
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

	vec_InsertionSort(largest);
	vec_InsertionSort(smallest);

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
