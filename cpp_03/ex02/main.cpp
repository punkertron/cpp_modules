#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap	a("FRAGBOY");

	a.highFivesGuys();
	std::cout <<
		"name = " << a.getName() << std::endl <<
		"hit = " << a.getHit() << std::endl <<
		"energy = " << a.getEnergy() << std::endl <<
		"attack = " << a.getAttack() << std::endl;
	return (0);
}
