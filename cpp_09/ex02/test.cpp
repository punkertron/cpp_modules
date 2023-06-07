#include <vector>
#include <algorithm>
#include <iostream>

void print_vec(std::vector<int> &vec)
{
	for (int i = 0, s = vec.size(); i < s; ++i)
	{
		std::cout << vec[i] << '|';
	}
	std::cout << std::endl;
}

void InsertionSort(std::vector<int> &vec)
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

int main(void)
{
	std::vector<int> vec = {1, 2, 6, 5, 7, 8, 0, 90};
	print_vec(vec);
	MergeInsertSort(vec);
	print_vec(vec);
	return 0;
}
