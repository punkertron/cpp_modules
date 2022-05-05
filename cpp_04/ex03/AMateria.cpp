#include "AMateria.hpp"

AMateria::AMateria(): m_type("None") {};

AMateria::~AMateria(){};

AMateria::AMateria(std::string const & type): m_type(type) {};

std::string const & AMateria::getType() const
{
	return (this->m_type);
}

AMateria::AMateria(const AMateria &a)
{
	operator=(a);
}

AMateria& AMateria::operator=(const AMateria &a)
{
	this->m_type = a.m_type;
	return (*this);
}
