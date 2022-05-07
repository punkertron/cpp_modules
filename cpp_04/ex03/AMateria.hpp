#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"

#include <string>

class ICharacter;

class AMateria
{
protected:
	std::string	m_type;

public:
	AMateria();
	virtual ~AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &a);
	AMateria& operator=(const AMateria &a);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif