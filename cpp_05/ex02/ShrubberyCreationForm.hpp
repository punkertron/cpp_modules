#pragma once

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std::string	m_target;

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &a);

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &a);

	void	execute(Bureaucrat const & executor) const;
};
