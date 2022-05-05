#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

#include "Brain.hpp"

int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;


	std::cout << std::endl << "Other test:" << std::endl << std::endl;

	Animal*	arr[6];

	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			arr[i] = new Cat();
		else
			arr[i] = new Dog();
		arr[i]->makeSound();
	}
	for (int i = 0; i < 6; i++) { delete arr[i];}
	
	std::cout << std::endl << "Other test:" << std::endl << std::endl;

	Cat *a;
	Cat *b;

	a = new Cat();
	b = new Cat(*a);

	delete a;
	b->makeSound();

	delete b;

	return (0);
}
