#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain_ptr;

public:
	Dog();
	~Dog();
	Dog(const Dog &a);
	Dog& operator=(const Dog &a);

	virtual void	makeSound() const;
};

#endif