#include "Ice.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice") {};
Ice::~Ice(){};

Ice::Ice(const Ice &a): AMateria()
{
	operator=(a);
}

Ice& Ice::operator=(const Ice &a)
{
	this->m_type = a.m_type;
	return (*this);
}

AMateria* Ice::clone() const
{
	Ice	*res = new Ice(*this);
	
	return (res);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << this->getType() << " *" << std::endl;
	(void) target;
}
