#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap a("TEST_ATTACK");
	ClapTrap b("TEST_REPAIRE");
	ClapTrap c("TEST_TAKE_DAMAGE");

	std::cout << "test attack:" << std::endl;
	for (int i = 1; i < 12 ; i++)
	{
		std::cout << i << ") ";
		a.attack("Strong");
	}
	
	std::cout << std::endl << "test repaire:" << std::endl;
	for (int i = 1; i < 10 ; i++)
	{
		std::cout << i << ") ";
		b.attack("Strong");
	}
	b.beRepaired(10);
	std::cout << b.getHit() << std::endl;
	b.beRepaired(10);

	std::cout << std::endl << "test take_damage:" << std::endl;
	c.takeDamage(10);
	c.beRepaired(10);
	c.takeDamage(1);

	return (0);
}
