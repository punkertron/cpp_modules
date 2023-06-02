#include "PmergeMe.hpp"

static int K = 5;

static void insertionSort(std::vector<int> &vec, int p, int size)
{
    int tempVal, j;

    for (int i = p; i < size; ++i)
    {
        tempVal = vec[i + 1];
        j = i + 1;
        while (j > p && vec[j - 1] > tempVal)
        {
            vec[j] = vec[j - 1];
            --j;
        }
        vec[j] = tempVal;
    }
}

static void merge(std::vector<int> &vec, const int left
    , const int mid, const int right)
{
    const int subArrayOne = mid - left + 1;
    const int subArrayTwo = right - mid;

    std::vector<int> leftArray(subArrayOne), rightArray(subArrayTwo);

    for (int i = 0; i < subArrayOne; ++i)
    {
        leftArray[i] = vec[left + i];
    }
    for (int i = 0; i < subArrayTwo; ++i)
    {
        rightArray[i] = vec[mid + 1 + i];
    }

	int i, j, k;
	i = j = 0;
	k = left;

	for (int i = p; i < right - mid + 1; ++i)
	{

	}
	
	while (i < subArrayOne && j < subArrayTwo)
	{
		if (leftArray[i] <= rightArray[i])
		{
			vec[k] = leftArray[i];
		}
		else
		{
			vec[k] = rightArray[i];
		}
		++i;
		++k;
	}

	while (i < left)
	{
		vec[k] = leftArray[k];
		++i;
		++k;
	}

	while (i < right)
	{
		vec[k] = rightArray[i];
		++i;
		++k;
	}
}

void MergeInsertSort(std::vector<int> &vec, int p, int r)
{
	if (r - p > K)
	{
		int m = (p + r) / 2;
		MergeInsertSort(vec, p, m);
		MergeInsertSort(vec, m + 1, r);
		merge(vec, p, m, r);
	}
	else
	{
		insertionSort(vec, p, r);
	}
}
