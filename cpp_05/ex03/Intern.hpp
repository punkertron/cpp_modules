#pragma once

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern &a);
	Intern& operator=(const Intern& a);
	Form*	makeForm(std::string name_form, std::string name_target);

	class UnrecognizedForm : public std::exception
	{
	private:
		virtual const char* what() const throw();
	};
};
