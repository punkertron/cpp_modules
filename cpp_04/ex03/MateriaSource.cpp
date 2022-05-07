#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
};

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i])
			delete this->slot[i];
	}
};

MateriaSource&	MateriaSource::operator=(const MateriaSource &a)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i])
			delete this->slot[i];
		if (a.slot[i])
			this->slot[i] = a.slot[i]->clone();
		else
			this->slot[i] = NULL;
	}
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource &a)
{
	operator=(a);
}

void MateriaSource::learnMateria(AMateria* t)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] == NULL)
		{
			this->slot[i] = t;
			return ;
		}
	}
	std::cout << "No Slots!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] && this->slot[i]->getType() == type)
		{
			return (this->slot[i]->clone());
		}
	}
	return (0);
}
