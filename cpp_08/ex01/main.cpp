#include <iostream>
#include "Span.hpp"

/*
int main(void)
{
	
	
	try
	{
		a.addNumber(10);
		a.addNumber(11);
		a.addNumber(12);
		a.addNumber(13);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	
	std::cout << "longest: "<< a.longestSpan() << std::endl;
	std::cout << "shortest: "<< a.shortestSpan() << std::endl;
	return (0);
}
*/

int main(void)
{
	Span a(3);

	try
	{
		a.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-----------" << std::endl;
	Span big = Span(1000000);
	try
	{
		big.addNumber(1000000, 3);
		//big.addNumber(5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "-----------" << std::endl;
	Span sp(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &ec)
	{
		std::cerr << ec.what() << std::endl;
	}
	Span temp1 = sp;
	Span temp2(sp);
	std::cout << "-----------" << std::endl;
	try
	{
		std::cout << temp1.shortestSpan() << std::endl;
		std::cout << temp1.longestSpan() << std::endl;
		std::cout << temp2.shortestSpan() << std::endl;
		std::cout << temp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
