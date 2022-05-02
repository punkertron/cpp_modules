#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap	a("BIGBOY");

	a.guradGate();
	std::cout <<
		"name = " << a.getName() << std::endl <<
		"hit = " << a.getHit() << std::endl <<
		"energy = " << a.getEnergy() << std::endl <<
		"attack = " << a.getAttack() << std::endl;
	a.ScavTrap::attack("BIGBOY");
	return (0);
}
