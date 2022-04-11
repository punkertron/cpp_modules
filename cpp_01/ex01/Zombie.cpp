#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string str): name(str) {}

Zombie::~Zombie()
{
	std::cout << this->name << ": died" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::set_name(std::string str)
{
	this->name = str;
}
