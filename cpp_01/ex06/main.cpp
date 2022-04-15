#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl Harl;

	if (argc == 2)
	{
		Harl.filter(argv[1]);
	}
	else
	{
		std::cerr << "Bad arguments!" << std::endl;
	}
	return (0);
}
