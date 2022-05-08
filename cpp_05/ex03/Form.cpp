#include "Form.hpp"
#include <cstring>

Form::Form(): m_name("None"), m_signed(false)
		, min_grade_sign(1), min_grade_execute(1)
{
	;
}

Form::~Form(){}

Form::Form(const std::string name, const int min_sign, const int min_exec):
	m_name(name), m_signed(false)
	, min_grade_sign(min_sign), min_grade_execute(min_exec)
{
	CheckFormGrades();
}

Form::Form(const Form &a):
	m_name(a.m_name), m_signed(a.m_signed)
	, min_grade_sign(a.min_grade_sign), min_grade_execute(a.min_grade_execute)
{
	CheckFormGrades();
}



std::string	Form::getNameForm() const
{
	return (m_name);
}

bool	Form::getStatusSigned() const
{
	return (m_signed);
}

int		Form::getMinGradeSign() const
{
	return (min_grade_sign);
}

int		Form::getMinGradeExec() const
{
	return (min_grade_execute);
}

Form::GradeTooHighException::GradeTooHighException(const std::string m_er): m_error_message(m_er) {};
Form::GradeTooLowException::GradeTooLowException(const std::string m_er): m_error_message(m_er) {};

const char* Form::GradeTooLowException::what() const throw()
{
	return (this->m_error_message.c_str());
}

const char* Form::GradeTooHighException::what() const throw()
{
	return (this->m_error_message.c_str());
}

void	Form::CheckFormGrades() const
{
	if (this->getMinGradeExec() > 150)
		throw GradeTooLowException("MinGradeExec is Too Low");
	if (this->getMinGradeExec() < 1)
		throw GradeTooHighException("MinGradeExec is Too High");
	if (this->getMinGradeSign() > 150)
		throw GradeTooLowException("MinGradeSign is Too Low");
	if (this->getMinGradeSign() < 1)
		throw GradeTooHighException("MinGradeSign is Too High");
	return ;
}

void	Form::beSigned(const Bureaucrat &a)
{
	if (a.getGrade() <= this->getMinGradeSign())
		this->m_signed = true;
	else
		throw GradeTooLowException("Bureaucrat's grade is Too Low");
}


void	Form::setSignedStatus(bool t)
{
	this->m_signed = t;
}

std::ostream&	operator<<(std::ostream &out, const Form &a)
{
	out << "The Form " << a.getNameForm() << " is "
		<< (a.getStatusSigned() == true ? "sighned" : "NOT sighned") << "." << std::endl
		<< "Min Grade to Sign is " << a.getMinGradeSign() << "." << std::endl
		<< "Min Grade to Execute is " << a.getMinGradeExec() << "."
		<< std::endl;

	return (out);
}
