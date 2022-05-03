#include "Animal.hpp"
#include <iostream>

Animal::Animal(): type("None")
{
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const std::string str): type(str)
{
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal& a)
{
	this->type = a.type;
}

Animal& Animal::operator=(const Animal &a)
{
	this->type = a.type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Bzzzzz" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}
