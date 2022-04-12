#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string str, Weapon *weap):
	name(str), weaponB(weap) {}

HumanB::~HumanB(){}

void	HumanB::attack() const
{
	std::string str;
	if (weaponB)
		str = weaponB->getType();
	else
		str = "<No weapon!>";
	
	std::cout << this->name << " attacks with their "
		<< str << std::endl;
}

void	HumanB::setWeapon(Weapon & weap)
{
	this->weaponB = &weap;
}
