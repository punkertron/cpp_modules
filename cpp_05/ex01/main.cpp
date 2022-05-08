#include "Bureaucrat.hpp"
#include "Form.hpp"


int main(void)
{
	try
	{
		Form a("A-123", 41, 12);
		std::cout << a;
		Bureaucrat b("Anna", 15);
		std::cout << b;
		a.beSigned(b);
		std::cout << a;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		//return (1);
	}
	std::cout << std::endl;

	try
	{
		Form a("A-123", 41, 12);
		std::cout << a;
		Bureaucrat b("Anna", 150);
		std::cout << b;
		a.beSigned(b);
		std::cout << a;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		//return (1);
	}


	std::cout << std::endl;

	Bureaucrat a("Bob", 15);
	Bureaucrat b("Mike", 90);
	Form c("B-19", 30, 45);
	Form d("GB-03", 30, 45);

	a.signForm(c);
	b.signForm(c);
	b.signForm(d);


	return (0);
}
