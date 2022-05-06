#include "Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure") {};
Cure::~Cure(){};

Cure::Cure(const Cure &a): AMateria()
{
	operator=(a);
}

Cure& Cure::operator=(const Cure &a)
{
	this->m_type = a.m_type;
	return (*this);
}

AMateria* Cure::clone() const
{
	Cure	*res = new Cure(*this);
	
	return (res);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals "<< this->getType() << "’s wounds *" << std::endl;
	(void) target;
}
