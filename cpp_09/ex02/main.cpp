#include <iostream>
#include <vector>
#include <list>

#include <algorithm>

#include <cstdlib> //exit
#include <sys/time.h> //gettimeofday

static void exit_error()
{
    std::cout << "Error" << std::endl;
    exit(EXIT_FAILURE);
}

static void print_vector(std::vector<int> &v)
{
    for (int i = 0, s = v.size() - 1; i < s; ++i)
    {
        std::cout << v[i] << ' ';
    }
    std::cout << v[v.size() - 1];
}

/*
static void print_list(std::list<int> &l)
{
    for(std::list<int>::const_iterator it = l.begin(), end = (--l.end()); it != end; ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << *(--l.end());
}
*/

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    if (argc < 2)
        exit_error();
    
    {
        timeval start, end;
        gettimeofday(&start, NULL);
        std::vector<int> vec1, vec2;
        char *endptr;
        int val;
        
        for (int i = 1; i < argc; ++i)
        {
            val = strtol(argv[i], &endptr, 10);
            if (*endptr != '\0')
                exit_error();
            vec1.push_back(val);
        }

        vec2 = vec1;
        std::sort(vec2.begin(), vec2.end());
        gettimeofday(&end, NULL);

        std::cout << "Before:\t";
        print_vector(vec1);
        std::cout << std::endl;
        long double duration = static_cast<long double>((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)) / 1000.0;

        std::cout << "After:\t";
        print_vector(vec2);
        std::cout << std::endl;

        std::cout << "Time to process a range of " << vec2.size() << " elements with std::vector : " << duration << std::endl;
    }

    {
        timeval start, end;
        gettimeofday(&start, NULL);
        std::list<int> l1, l2;
        char *endptr;
        int val;
        
        for (int i = 1; i < argc; ++i)
        {
            val = strtol(argv[i], &endptr, 10);
            if (*endptr != '\0')
                exit_error();
           l1.push_back(val);
        }

        l2 = l1;
        l2.sort();
        gettimeofday(&end, NULL);
        unsigned long long duration = (end.tv_sec - start.tv_sec + end.tv_usec - start.tv_usec) / 1000.0;
        //print_list(l2);
        //std::cout << std::endl;

        std::cout << "Time to process a range of " << l2.size() << " elements with std::list   : " << duration / 1000.0 << std::endl;


    }

    return 0;
}
