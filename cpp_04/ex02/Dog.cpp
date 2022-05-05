#include "Dog.hpp"
#include <iostream>

Dog::Dog(): AAnimal("Dog")
{
	std::cout << "Dog Constructor called" << std::endl;
	this->brain_ptr = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->brain_ptr;
}

Dog::Dog(const Dog &a): AAnimal("Dog")
{
	operator=(a);
}

Dog&	Dog::operator=(const Dog &a)
{
	this->type = a.type;
	this->brain_ptr = new Brain(*a.brain_ptr);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
