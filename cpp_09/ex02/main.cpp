#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#include <cstdlib> //exit
#include <sys/time.h> //gettimeofday
#include <climits>

#include "PmergeMe.hpp"

static void exit_error()
{
    std::cout << "Error" << std::endl;
    exit(EXIT_FAILURE);
}

static bool is_duplicate(std::vector<unsigned int> &v, const unsigned int val)
{
    for (int i = 0, s = v.size(); i < s; ++i)
    {
        if (v[i] == val)
            return true;
    }
    return false;
}

static bool is_duplicate(std::list<unsigned int> &l, const unsigned int val)
{
    for (std::list<unsigned int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        if (*it == val)
            return true;
    }
    return false;
}



/*
static void print_vector(std::vector<unsigned int> &v)
{
    for (int i = 0, s = v.size() - 1; i < s; ++i)
    {
        std::cout << v[i] << ' ';
    }
    std::cout << v[v.size() - 1];
}

void print_list(std::list<unsigned int> &l)
{
    for(std::list<unsigned int>::const_iterator it = l.begin(), end = (--l.end()); it != end; ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << *(--l.end());
}
*/

int main(int argc, char **argv)
{
    if (argc < 2)
        exit_error();

    timeval start, end;

    //vector
    {
        std::vector<unsigned int> vec;
        char *endptr;
        int val;

        for (int i = 1; i < argc; ++i)
        {
            val = strtol(argv[i], &endptr, 10);
            if (*endptr != '\0' || val < 1 || val > INT_MAX || is_duplicate(vec, val))
                exit_error();
            vec.push_back(val);
        }

        //std::cout << "Before:\t";
        //print_vector(vec);

        gettimeofday(&start, NULL);
        MergeInsertSort(vec);
		gettimeofday(&end, NULL);

        std::cout << std::endl;
        unsigned long long duration = end.tv_sec - start.tv_sec + end.tv_usec - start.tv_usec;

        std::cout << "After:\t";
        //print_vector(vec);
        //std::cout << std::endl;

        if (std::is_sorted(vec.begin(), vec.end()))
            std::cout << "sorted" << std::endl;

        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << duration / 1000.0 << std::endl;
    }

	//list
    {
        std::list<unsigned int> l;
        char *endptr;
        int val;

        for (int i = 1; i < argc; ++i)
        {
            val = strtol(argv[i], &endptr, 10);
            if (*endptr != '\0' || val < 1 || val > INT_MAX || is_duplicate(l, val))
                exit_error();
            l.push_back(val);
        }

        gettimeofday(&start, NULL);

        //print_list(l);
        //std::cout << std::endl;

		MergeInsertSort(l);
        gettimeofday(&end, NULL);
        unsigned long long duration = end.tv_sec - start.tv_sec + end.tv_usec - start.tv_usec;
        
        //print_list(l);
        //std::cout << std::endl;
        if (std::is_sorted(l.begin(), l.end()))
            std::cout << "SORTED" << std::endl;
        
        std::cout << "Time to process a range of " << l.size() << " elements with std::list   : " << duration / 1000.0 << std::endl;

    }

    return 0;
}
