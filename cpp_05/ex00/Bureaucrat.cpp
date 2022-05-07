#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): m_grade(150) {}

Bureaucrat::Bureaucrat(int a)
{
	try
	{
		if (a > 150)
			throw GradeTooLowException();
		else if (a < 1)
			throw GradeTooHighException();
		else
			m_grade = a;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	m_grade = 150;
	
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("To Low Grade! The minimum is 150!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("To High Grade! The maximum is 150!");
}


Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const
{
	return (this->m_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->m_grade);
}





std::ostream& operator<<(std::ostream &out, const Bureaucrat &a)
{
	out << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;

	return (out);
}
