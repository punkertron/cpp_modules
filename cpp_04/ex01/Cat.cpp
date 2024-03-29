#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat")
{
	std::cout << "Cat Constructor called" << std::endl;
	this->brain_ptr = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->brain_ptr;
}

Cat::Cat(const Cat &a): Animal("Cat")
{
	operator=(a);
}

Cat&	Cat::operator=(const Cat &a)
{
	this->type = a.type;
	this->brain_ptr = new Brain(*a.brain_ptr);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
