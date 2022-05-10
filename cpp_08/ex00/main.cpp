#include "easyfind.hpp"

#include <iostream>
#include <list>
#include <deque>


int main()
{
	std::deque<int> deq;

	deq.push_back(1);
	deq.push_front(2);
	deq.push_back(5);
	deq.push_front(-4);
	std::deque<int>::iterator it_deq;

	// print deq
	/*
	for (it_deq = deq.begin(); it_deq < deq.end(); ++it_deq)
	{
		std::cout << *it_deq << std::endl;
	}
	*/
	try
	{
		it_deq = easyfind(deq, 5);
		std::cout << *it_deq << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	std::list<int> t;
	t.push_front(1);
	t.push_front(2);
	t.push_front(3);
	std::list<int>::const_iterator it_list;

	// print list
	/*
	it_list = t.begin();
	while (it_list != t.end())
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}
	*/

	try
	{
		it_list = easyfind(t, 1);
		std::cout << *it_list << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}


	return (0);
}
