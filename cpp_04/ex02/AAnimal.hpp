#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class AAnimal
{
protected:
	std::string	type;

public:
	AAnimal();
	AAnimal(const std::string str);
	virtual ~AAnimal();
	AAnimal(const AAnimal& a);
	AAnimal& operator=(const AAnimal &a);


	std::string	getType() const;

	virtual void	makeSound() const = 0;
};

#endif