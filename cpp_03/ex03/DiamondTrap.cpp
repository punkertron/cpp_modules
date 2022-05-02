#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	ClapTrap::setName(getName() + "_clap_name");
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Diamond: " << this->name << std::endl <<
		"ClapTrap: " << this->getName() << std::endl;
}
