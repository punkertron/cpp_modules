#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5), m_target("None") {};

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5), m_target(target) {};

PresidentialPardonForm::~PresidentialPardonForm() {};


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a):
	Form(a.getNameForm(), a.getMinGradeSign(), a.getMinGradeExec()),
	m_target(a.m_target)
{
	this->setSignedStatus(a.getStatusSigned());
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getStatusSigned() != true)
		throw (std::string) "Form is NOT signed!";
	if (this->getMinGradeExec() < executor.getGrade())
		throw Form::GradeTooLowException("Bureaucrat's grade is too low!");
	std::cout << this->m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
