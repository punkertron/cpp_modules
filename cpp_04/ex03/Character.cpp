#include "Character.hpp"
#include <iostream>

Character::Character() : name("None")
{
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
}

Character::Character(const Character &a)
{
	operator=(a);
}

Character& Character::operator=(const Character &a)
{
	this->name = a.name;
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

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i])
			delete this->slot[i];
	}
}

std::string const& Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] == NULL)
		{
			this->slot[i] = m;
			return ;
		}
	}
	std::cout << "No Slots!" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		if (this->slot[idx])
			this->slot[idx] = NULL;
		return ;
	}
	std::cout << "Incorrect idx" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && this->slot[idx])
	{
		this->slot[idx]->use(target);
	}
}
