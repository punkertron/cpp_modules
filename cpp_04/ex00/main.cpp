#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const WrongAnimal* t = new WrongCat();
	const WrongAnimal* p = new WrongAnimal();

	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << meta->getType() << std::endl;
	meta->makeSound();

	std::cout << std::endl << "Test Wrong:" << std::endl;
	std::cout << t->getType() << std::endl;
	t->makeSound();
	std::cout << p->getType() << std::endl;
	p->makeSound();

	delete meta;
	delete j;
	delete i;

	delete p;
	delete t;
	return (0);
}