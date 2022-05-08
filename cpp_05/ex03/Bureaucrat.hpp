#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	int	m_grade;
	const std::string	m_name;

	class GradeTooHighException : public std::exception
	{
	private:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	private:
		virtual const char* what() const throw();
	};

	Bureaucrat& operator=(const Bureaucrat &a);

public:
	Bureaucrat();
	Bureaucrat(const std::string name, int a);
	Bureaucrat(const Bureaucrat &a);
	~Bureaucrat();

	std::string getName() const;
	int	getGrade() const;
	void	increment(int a);
	void	decrement(int a);


	void	signForm(Form &a) const;

	void executeForm(Form const & form);
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &a);

#endif