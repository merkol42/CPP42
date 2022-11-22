#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& rhs);
	~Brain();

	Brain&	operator=(const Brain& rhs);
	
	const std::string&	getIdeas(int i);
};

#endif