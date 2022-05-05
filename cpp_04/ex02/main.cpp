#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

#include "Brain.hpp"

int main(void)
{
	//const AAnimal* meta = new AAnimal(); //error
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();


	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!

	delete j;
	delete i;

	return (0);
}
