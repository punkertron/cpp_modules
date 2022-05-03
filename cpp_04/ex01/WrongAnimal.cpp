#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): type("None")
{
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string str): type(str)
{
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a)
{
	this->type = a.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a)
{
	this->type = a.type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WRONG_Bzzzzz" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}
