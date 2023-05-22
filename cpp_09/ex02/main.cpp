#include <iostream>
#include <vector>
#include <string>

#include <algorithm>

#include <cstdlib> //exit

static void exit_error()
{
    std::cout << "Error" << std::endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        exit_error();
    
    std::vector<int> vec;
    char *endptr;
    int val;
    
    for (int i = 1; i < argc; ++i)
    {
        val = strtol(argv[i], &endptr, 10);
        if (*endptr != '\0')
            exit_error();
        vec.push_back(val);
    }

    //std::sort(vec.begin(), vec.end());
    std::cout << *(vec.begin()) << std::endl;

    return 0;
}