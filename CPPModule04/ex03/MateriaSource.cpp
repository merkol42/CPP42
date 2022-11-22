#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		this->source[i] = NULL;
	std::cout << "MateriaSource Default Constructor Called!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
	*this = rhs;
	std::cout << "MateriaSource Coppy Constructor Called!" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->source[i] != NULL)
			delete	this->source[i];
	}
	std::cout << "MateriaSource Destructor Called!" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->source[i])
			delete	this->source[i];
		if (rhs.source[i] != NULL)
			this->source[i] = rhs.source[i]->clone();
	}
	std::cout << "MateriaSource Assignment Operator Called!" << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	std::cout << "MateriaSource: learnMateria Called!" << std::endl;

	for (size_t i = 0; i < 4; i++)
	{
		if (this->source[i] == NULL)
		{
			this->source[i] = m;
			return ;
		}
	}
	std::cout << "Source capacity is full, so delete is called for parameter" << std::endl;
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	std::cout << "MateriaSource: createMateria Called!" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->source[i] && this->source[i]->getType() == type)
			return (this->source[i]->clone());
	}
	return (0);
}