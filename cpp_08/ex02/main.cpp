#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl << "------------" << std::endl;

	MutantStack<int> b = mstack; //check =
	{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << std::endl << "------------" << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		mstack.pop_back();
		//std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << std::endl << "------------" << std::endl;

	MutantStack<double> test_d;
	test_d.push(4.2);
	test_d.push(2.1);
	test_d.push(106.5);
	test_d.push(75.2);

	MutantStack<double> testd2(test_d);
	MutantStack<double>::iterator dob_i1 = testd2.begin();
	MutantStack<double>::iterator dob_i2 = testd2.end();
	std::cout << "size = " << testd2.size() << std::endl;
	while (dob_i1 != dob_i2)
	{
		std::cout << *dob_i1 << std::endl;
		++dob_i1;
	}

	return 0;
}

