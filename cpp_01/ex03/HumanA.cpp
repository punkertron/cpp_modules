#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon & weap):
	name(str), weaponA(weap) {}

HumanA::~HumanA() {};


void	HumanA::attack() const
{
	std::cout << this->name << " attacks with their "
		<< weaponA.getType() << std::endl;
}
