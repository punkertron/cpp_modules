#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	AMateria*	slot[4];

public:
	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource& operator=(const MateriaSource &a);
	MateriaSource(const MateriaSource &a);

	void learnMateria(AMateria* t);
	AMateria* createMateria(std::string const & type);
};

#endif