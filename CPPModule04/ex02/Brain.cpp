#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called!!!" << std::endl;
}

Brain::Brain(Brain const &rsc)
{
	std::cout << "Brain copy constructor called!!!" << std::endl;
	*this = rsc;
}

Brain&	Brain::operator=(Brain const &rhs)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = rhs.ideas[i];
	}
	std::cout << "Brain Coppy Assignment Operator Called!" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!!!" << std::endl;
}

const	std::string&	Brain::getIdeas(int i)
{
	return (this->ideas[i]);
}