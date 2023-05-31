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
    

}