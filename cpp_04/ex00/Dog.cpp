#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &a): Animal("Dog")
{
	this->type = a.type;
}

Dog&	Dog::operator=(const Dog &a)
{
	this->type = a.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
