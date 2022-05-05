#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(): type("None")
{
	std::cout << "Animal Constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

AAnimal::AAnimal(const std::string str): type(str)
{
	std::cout << "Animal Constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& a)
{
	this->type = a.type;
}

AAnimal& AAnimal::operator=(const AAnimal &a)
{
	this->type = a.type;
	return (*this);
}

void	AAnimal::makeSound() const
{
	std::cout << "Bzzzzz" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}
