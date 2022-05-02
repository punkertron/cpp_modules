#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string const & name):
	ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "Default ScavTrap Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &a): ClapTrap()
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(a);
}

ScavTrap& ScavTrap::operator=(const ScavTrap &a)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setName(a.getName());
	this->setEnergy(a.getEnergy());
	this->setHit(a.getHit());
	this->setAttack(a.getAttack());
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergy() == 0 || this->getHit() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " has no hit or energy!" << std::endl;
		return ;
	}
	this->setEnergy(this->getEnergy() - 1);
	std::cout << "ScavTrap " << this->getName() <<
		" attacks " << target << ", causing " <<
		this->getAttack() << " points of damage!" <<
		std::endl;
}

void	ScavTrap::guradGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
