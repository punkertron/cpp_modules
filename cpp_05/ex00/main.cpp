#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("Bob", 12);
		Bureaucrat b("Anna", 149);
		Bureaucrat c("Tom", 2);

		std::cout << a;
		std::cout << b;
		std::cout << c;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	try
	{
		Bureaucrat d("Molly", 10);
		d.increment(15);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
