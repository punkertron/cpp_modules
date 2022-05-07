#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
private:
	int	m_grade;
	const std::string	m_name;

	class GradeTooHighException
	{
	private:
		virtual const char* what() const throw();
	};
	class GradeTooLowException
	{
	private:
		virtual const char* what() const throw();
	};

public:
	Bureaucrat();
	Bureaucrat(int a);
	~Bureaucrat();

	std::string getName() const;
	int	getGrade() const;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &a);

#endif