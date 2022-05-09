#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <exception>

Base::~Base(){};

Base	*generate(void)
{
	Base *ptr = NULL;
	
	srand(time(NULL));
	switch (rand() % 3)
	{
	case 0:
		ptr = new A();
		break;
	case 1:
		ptr = new B();
		break;
	case 2:
		ptr = new C();
		break;
	}
	return (ptr);
}

void	identify(Base* p)
{
	std::cout << "type - ";
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "wtf" << std::endl;
}

void	identify(Base& p)
{
	std::cout << "type - ";
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(std::exception&)
	{
		try
		{
			dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			return ;
		}
		catch(std::exception&)
		{
			std::cout << "C" << std::endl;
			return ;
		}
	}
}
