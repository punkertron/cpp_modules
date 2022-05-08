#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	m_name;
	bool				m_signed;
	const int			min_grade_sign;
	const int			min_grade_execute;

	Form& operator=(const Form &a);

	class GradeTooHighException : public std::exception
	{
	private:
		std::string	m_error_message;

		virtual const char* what() const throw();
	public:
		GradeTooHighException(const std::string m_er);
		virtual ~GradeTooHighException() throw() {};
	};
	class GradeTooLowException : public std::exception
	{
	private:
		std::string	m_error_message;

		virtual const char* what() const throw();
	public:
		GradeTooLowException(const std::string m_er);
		virtual ~GradeTooLowException() throw() {};
	};

	void	CheckFormGrades() const;

public:
	Form();
	Form(const std::string name, const int min_sign, const int min_exec);
	~Form();
	Form(const Form &a);

	std::string	getNameForm() const;
	bool	getStatusSigned() const;
	int		getMinGradeSign() const;
	int		getMinGradeExec() const;


	void	beSigned(const Bureaucrat &a);
	void	setSignedStatus(bool t);

};

std::ostream& operator<<(std::ostream &out, const Form &a);

#endif