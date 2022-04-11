#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* ptr;

	ptr = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		ptr[i].set_name(name);
	}
	return (ptr);
}
