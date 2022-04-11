#include "Zombie.hpp"

int main(void)
{
	int	amount = 2;
	Zombie* ptr;

	ptr = zombieHorde(amount, "John");

	for (int i = 0; i < amount; i++)
	{
		ptr[i].announce();
	}

	delete[] ptr;
	return (0);
}
