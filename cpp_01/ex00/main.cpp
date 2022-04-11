#include "Zombie.hpp"

int main(void)
{
	Zombie	Bar("Stack");
	Bar.announce();

	Zombie *ptr;
	
	ptr = newZombie("Heap");
	ptr->announce();

	randomChump("random_stack");


	delete ptr;
	return (0);
}