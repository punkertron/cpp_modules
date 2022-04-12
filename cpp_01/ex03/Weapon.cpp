#include "Weapon.hpp"

Weapon::Weapon(std::string str): type(str) {};
Weapon::~Weapon() {};

const std::string & Weapon::getType()
{
	std::string const & str = this->type;
	return(str);
}

void Weapon::setType(std::string str)
{
	this->type = str;
}
