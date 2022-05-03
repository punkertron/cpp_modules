#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &a)
{
	std::cout << "Brain Constructor called" << std::endl;
	operator=(a);
}

Brain& Brain::operator=(const Brain &a)
{
	for (int i = 0; i < ARR_SIZE; i++)
	{
		this->ideas[i] = a.ideas[i];
	}
	return (*this);
}
