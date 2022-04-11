#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	std::string	name;

public:
	Zombie(std::string str = "default");
	~Zombie();

	void	announce( void );
	void	set_name(std::string str);
};

Zombie* zombieHorde( int N, std::string name );

#endif