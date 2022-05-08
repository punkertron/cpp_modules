#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string	m_target;

	PresidentialPardonForm& operator=(const PresidentialPardonForm &a);

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &a);
	
	void	execute(Bureaucrat const & executor) const;
};