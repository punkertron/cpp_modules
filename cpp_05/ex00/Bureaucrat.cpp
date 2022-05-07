#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): m_grade(150), m_name("None") {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int a):
	m_grade(a), m_name(name)
{
	if (a > 150)
		throw GradeTooLowException();
	else if (a < 1)
		throw GradeTooHighException();
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("To Low Grade! The minimum is 150!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("To High Grade! The maximum is 1!");
}

std::string Bureaucrat::getName() const
{
	return (this->m_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->m_grade);
}

void	Bureaucrat::increment(int a)
{
	this->m_grade -= a;
	if (this->m_grade > 150)
		throw GradeTooLowException();
	else if (this->m_grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::decrement(int a)
{
	this->m_grade += a;
	if (this->m_grade > 150)
		throw GradeTooLowException();
	else if (this->m_grade < 1)
		throw GradeTooHighException();;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &a)
{
	out << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;

	return (out);
}
