#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern someRandomIntern;
		Bureaucrat	a("Tom", 1);
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		a.signForm(*rrf);
		a.executeForm(*rrf);

		delete rrf;
/*
		Form *wrong_form;
		wrong_form = someRandomIntern.makeForm("abc", "target");
		(void) wrong_form;
		*/
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
