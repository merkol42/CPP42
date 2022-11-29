#include "Span.hpp"

Span::Span(unsigned int _n) : n(_n)
{
	n_size = 0;
	vec.reserve(n);
	// std::cout << "Span Has Been Constructed!" << std::endl;
}

Span::~Span()
{
	// std::cout << "Destructor Called!!" << std::endl;
}

Span::Span(const Span& ref) : n(ref.n), vec(ref.vec)
{
	n_size = ref.vec.size();
	// std::cout << "Coppy Constructor Called!" << std::endl;
}

Span&	Span::operator=(const Span& ref)
{
	this->n = ref.n;
	this->vec = ref.vec;
	this->n_size = ref.vec.size();
	// std::cout << "Assignment Operator Called!" << std::endl;
	return (*this);
}

void	Span::addNumber(int	nmber)
{
	if (vec.size() >= n || n_size >= n)
		throw(std::out_of_range("Cannot add anymore elements"));
	vec.push_back(nmber);
	n_size++;
}

void	Span::addNumber(int start, int end)
{
	for (int i = start; i <= end; i++)
		addNumber(i);
}

int	Span::longestSpan()
{
	if (!n || n_size == 1)
		throw(std::length_error("No Longest Span!"));
	std::vector<int>::const_iterator	max = std::max_element(vec.cbegin(), vec.cend());
	std::vector<int>::const_iterator	min = std::min_element(vec.cbegin(), vec.cend());
	return (*max - *min);
}

int	Span::shortestSpan()
{
	std::vector<int>	v = vec;

	if (!n || n_size == 1)
		throw(std::length_error("No Shortest Span!"));
	int	span = *std::max_element(vec.begin(), vec.end());

	std::sort(v.begin(), v.end());
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (i && std::abs(v[i] - v[i - 1]) < span)
			span = std::abs(v[i] - v[i - 1]);
	}
	return (span);
}