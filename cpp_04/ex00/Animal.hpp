#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string	type;

public:
	Animal();
	Animal(const std::string str);
	virtual ~Animal();
	Animal(const Animal& a);
	Animal& operator=(const Animal &a);

	std::string	getType() const;

	virtual void	makeSound() const;
};

#endif