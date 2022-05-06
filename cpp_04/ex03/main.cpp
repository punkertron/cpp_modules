#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include <iostream>

int main()
{
	/*
	{
		std::cout << "test equip/unequip, clone:" << std::endl;
		Character a("BIGBOY");
		Cure	cure;
		Ice		ice;
		ICharacter *bob = new Character("Bob");

		std::cout << a.getName() << std::endl;
		for (int i = 0; i < 5; i++) a.equip(&cure);
		for (int i = 0; i < 5; i++) a.unequip(i);

		a.use(0, *bob);
		ice.use(*bob);

		AMateria		*ice2 = ice.clone();
		std::cout << ice2->getType() << std::endl;
		delete ice2;

		delete bob;
	}
*/
	

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	
	return (0);
}
