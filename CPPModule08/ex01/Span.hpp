#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
// #include <cmath>

class Span
{
private:
	unsigned int		n;
	unsigned int		n_size;
	std::vector<int>	vec;
public:
	Span(unsigned int _n);
	Span(const Span& ref);
	~Span();

	Span&	operator=(const Span& ref);

	void	addNumber(int nmber); // nmber varsa exception throw
	void	addNumber(int start, int end);
	int		shortestSpan(); // if there are no numbers stored or only one throw exception
	int		longestSpan();
};

#endif