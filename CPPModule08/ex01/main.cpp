#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span : " <<sp.longestSpan() << std::endl << std::endl;
	
	std::cout << "---MY TEST---" << std::endl;
	Span sp1(10000);

	sp1.addNumber(1, 10000);

	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl << std::endl;

	std::cout << "---Exception Test---" << std::endl;
	Span	sp2(0);
	try
	{
		sp2.addNumber(-10);
	}
	catch(std::out_of_range &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		sp2.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		sp2.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}