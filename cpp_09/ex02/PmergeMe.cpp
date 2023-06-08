#include "PmergeMe.hpp"

static void InsertionSort(std::vector<int> &vec)
{
	int value, hole;

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

void MergeInsertSort(std::vector<int> &vec)
{
	for (int i = 0, size = vec.size(); i < size; ++i, ++i)
	{
		if (i + 1 < size && vec[i] < vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
	}

	std::vector<int> largest, smallest;
	for(int i = 0, size = vec.size(); i < size; ++i, ++i)
	{
		largest.push_back(vec[i]);
		if (i + 1 < size)
			smallest.push_back(vec[i + 1]);
	}

	int nL = largest.size(), nS = smallest.size();
	int i = 0, j = 0, k = 0;

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
