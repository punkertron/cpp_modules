#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("Tom", 1);
		Bureaucrat c("Mike", 137);
		Bureaucrat d("Hanna", 76);

		ShrubberyCreationForm sh("SH_Name");
		RobotomyRequestForm rb("Robo");
		PresidentialPardonForm pr("PARDON");

		sh.beSigned(b);
		rb.beSigned(b);
		pr.beSigned(b);
		c.executeForm(sh);
		b.executeForm(rb);
		d.executeForm(pr);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	


	return (0);
}
