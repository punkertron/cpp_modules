#include "Cure.hpp"

Cure::Cure(): m_name("cure") {};
Cure::~Cure(){};

Cure::Cure(const Cure &a)
{
	operator=(a);
}

Cure& Cure::operator=(const Cure &a)
{
	this->m_name = a.m_name;
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria	*res = new Cure(*this);
	
	return (res);
}
