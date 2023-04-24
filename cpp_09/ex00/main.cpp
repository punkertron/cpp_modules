#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    DataBase data((std::string(argv[1])));

    return 0;
}
