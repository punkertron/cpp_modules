#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap Constructor called" << std::endl;
	this->name = name;
	this->m_hit = 100; //FragTrap::m_hit;
	this->m_energy = 50; //ScavTrap::m_energy;
	this->m_attack = 30; //FragTrap::m_attack;
}

DiamondTrap::DiamondTrap(): ClapTrap("None_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "Default DiamondTrap Constructor called" << std::endl;
	this->name = "None";
	this->m_hit = 100; //FragTrap::m_hit;
	this->m_energy = 50; //ScavTrap::m_energy;
	this->m_attack = 30; //FragTrap::m_attack;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &a): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(a);
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &a)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->m_name = a.m_name;
	this->ClapTrap::m_name = a.ClapTrap::getName();
	this->m_energy = a.m_energy;
	this->m_hit = a.m_hit;
	this->m_attack = a.m_attack;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Diamond: " << this->name << std::endl <<
		"ClapTrap: " << this->getName() << std::endl;
}
