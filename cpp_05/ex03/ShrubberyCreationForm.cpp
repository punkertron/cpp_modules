#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <sstream>

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137), m_target("None") {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), m_target(target) {};

ShrubberyCreationForm::~ShrubberyCreationForm() {};


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a):
	Form(a.getNameForm(), a.getMinGradeSign(), a.getMinGradeExec()),
	m_target(a.m_target)
{
	this->setSignedStatus(a.getStatusSigned());
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::fstream	f;

	if (this->getStatusSigned() != true)
		throw (std::string) "Form is NOT signed!";
	if (this->getMinGradeExec() < executor.getGrade())
		throw Form::GradeTooLowException("Bureaucrat's grade is too low!");
	f.open((m_target + "_shrubbery").c_str(), std::ios_base::out);
	if (f.is_open() == false)
		throw (std::string) "Cannot open a file";
	
	f << "\n"
"    oxoxoo    ooxoo\n"
"  ooxoxo oo  oxoxooo\n"
" oooo xxoxoo ooo ooox\n"
" oxo o oxoxo  xoxxoxo\n"
"  oxo xooxoooo o ooo\n"
"    ooo\\oo\\  /o/o\n"
"        \\  \\/ /\n"
"         |   /\n"
"         |  |\n"
"         | D|\n"
"         |  |\n"
"         |  |\n"
"  ______/____\\____\n";

	
	f.close();
}
