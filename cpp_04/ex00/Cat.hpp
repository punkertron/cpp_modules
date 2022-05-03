#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat &a);
	Cat& operator=(const Cat &a);

	virtual void	makeSound() const;
};

#endif