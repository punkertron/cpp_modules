#include "Ice.hpp"

Ice::Ice(): m_name("ice") {};
Ice::~Ice(){};

Ice::Ice(const Ice &a)
{
	operator=(a);
}

Ice& Ice::operator=(const Ice &a)
{
	this->m_name = a.m_name;
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria	*res = new Ice(*this);
	
	return (res);
}
