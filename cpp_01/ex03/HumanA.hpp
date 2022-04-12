#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string		name;
	Weapon	&weaponA;

public:
	HumanA(std::string str, Weapon & weap);
	~HumanA();

	void	attack() const;
};

#endif