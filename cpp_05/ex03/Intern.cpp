#include "Intern.hpp"
#include <cstdlib>

Intern::Intern(){};
Intern::~Intern(){};
Intern::Intern(const Intern &a) {(void) a;}
Intern& Intern::operator=(const Intern &a){(void) a; return (*this);}

Form*	Intern::makeForm(std::string name_form, std::string name_target)
{
	Form *res = NULL;
	int	a = 0;
	std::string forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

	while (a < 3 && forms[a] != name_form)
		a++;
	
	switch (a)
	{
	case 0:
		try {res = new RobotomyRequestForm(name_target);}
		catch(std::bad_alloc &ex)
		{
			std::cerr << ex.what() << std::endl;
			exit(EXIT_FAILURE);
		}
		std::cout << "Intern creates " << forms[a] << std::endl;
		break;
	case 1:
		try {res = new ShrubberyCreationForm(name_target);}
		catch(std::bad_alloc &ex)
		{
			std::cerr << ex.what() << std::endl;
			exit(EXIT_FAILURE);
		}
		std::cout << "Intern creates " << forms[a]  << std::endl;
		break;
	case 2:
		try{res = new PresidentialPardonForm(name_target);}
		catch(std::bad_alloc &ex)
		{
			std::cerr << ex.what() << std::endl;
			exit(EXIT_FAILURE);
		}
		std::cout << "Intern creates " << forms[a] << std::endl;
		break;

	default:
		throw Intern::UnrecognizedForm();
		break;
	}
	return (res);
}

const char* Intern::UnrecognizedForm::what() const throw()
{
	return ("UNRECOGNIZED FORM!!");
}
