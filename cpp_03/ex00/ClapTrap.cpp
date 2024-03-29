#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap():
	m_attack(M_NUMBER_DAMAGE), m_energy(M_NUMBER_HIT), m_hit(M_NUMBER_HIT)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	m_name = "None";
}

ClapTrap::ClapTrap(std::string const & name):
	m_name(name), m_attack(M_NUMBER_DAMAGE), m_energy(M_NUMBER_HIT), m_hit(M_NUMBER_HIT)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &a)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(a);
}
ClapTrap& ClapTrap::operator=(const ClapTrap &a)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->m_name = a.m_name;
	this->m_energy = a.m_energy;
	this->m_hit = a.m_hit;
	this->m_attack = a.m_attack;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->m_energy == 0 || this->m_hit <= 0)
	{
		std::cout << "ClapTrap " << this->m_name << " has no hit or energy!" << std::endl;
		return ;
	}
	this->m_energy--;
	std::cout << "ClapTrap " << this->m_name <<
		" attacks " << target << ", causing " <<
		this->m_attack << " points of damage!" <<
		std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->m_hit > 0)
	{
		std::cout << "ClapTrap " << this->m_name <<
		" takes damage of " << amount << " points!" <<
		std::endl;
		this->m_hit -= amount;
	}
	std::cout << "ClapTrap " << this->m_name << " is dead." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->m_energy == 0 || this->m_hit <= 0)
	{
		std::cout << "ClapTrap " << this->m_name << " has no hit or energy!" << std::endl;
		return ;		
	}
	this->m_energy--;
	this->m_hit += amount;
	std::cout << "ClapTrap " << this->m_name <<
		" repaired by " << amount << " points!" <<
		std::endl;
}

int	ClapTrap::getHit() const
{
	return (this->m_hit);
}
