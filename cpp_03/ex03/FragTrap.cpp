#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string const & name):
	ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Default FragTrap Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &a): ClapTrap()
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(a);
}

FragTrap& FragTrap::operator=(const FragTrap &a)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setName(a.getName());
	this->setEnergy(a.getEnergy());
	this->setHit(a.getHit());
	this->setAttack(a.getAttack());
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << ": Hi five, guys!" << std::endl;
}
