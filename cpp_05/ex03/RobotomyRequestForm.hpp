#pragma once

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	std::string	m_target;

	RobotomyRequestForm& operator=(const RobotomyRequestForm &a);

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &a);
	
	void	execute(Bureaucrat const & executor) const;
};