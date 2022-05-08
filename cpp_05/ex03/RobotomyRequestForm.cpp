#include "RobotomyRequestForm.hpp"

#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45), m_target("None") {};

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45), m_target(target) {};

RobotomyRequestForm::~RobotomyRequestForm() {};


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a):
	Form(a.getNameForm(), a.getMinGradeSign(), a.getMinGradeExec()),
	m_target(a.m_target)
{
	this->setSignedStatus(a.getStatusSigned());
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getStatusSigned() != true)
		throw (std::string) "Form is NOT signed!";
	if (this->getMinGradeExec() < executor.getGrade())
		throw Form::GradeTooLowException("Bureaucrat's grade is too low!");
	std::cout << "Some drilling noise..." << std::endl;

	srand(time(NULL));
	if (rand() % 2 == 1)
		std::cout << this->getNameForm() << " has been robotomized successfully 50% of the time" << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}
