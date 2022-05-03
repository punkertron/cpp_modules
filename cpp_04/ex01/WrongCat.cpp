#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &a): WrongAnimal("WrongCat")
{
	this->type = a.type;
}

WrongCat&	WrongCat::operator=(const WrongCat &a)
{
	this->type = a.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WRONG__Meow" << std::endl;
}
