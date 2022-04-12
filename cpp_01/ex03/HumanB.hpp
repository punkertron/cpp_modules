#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string		name;
	Weapon			*weaponB;

public:
	HumanB(std::string str, Weapon *weap = NULL);
	~HumanB();

	void	attack() const;
	void	setWeapon(Weapon & weap);
};

#endif