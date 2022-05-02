#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap a("BIGBOY");
	std::cout << a.getEnergy() << std::endl;
	std::cout << "-----------" << std::endl;
	a.whoAmI();
	std::cout << "-----------" << std::endl;
	a.highFivesGuys();
	std::cout << "-----------" << std::endl;
	a.ClapTrap::attack("CLAP_TARGET");
	std::cout << "-----------" << std::endl;
	a.attack("DIAMOND_TARGET");
	std::cout << "-----------" << std::endl;
	a.ScavTrap::attack("SCAV_TARGET");
	std::cout << "-----------" << std::endl;

	std::cout << a.getEnergy() << std::endl;
	return (0);
}
