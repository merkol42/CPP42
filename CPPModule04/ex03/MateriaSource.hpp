#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*source[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& rhs);
	~MateriaSource();

	MateriaSource	&operator=(const MateriaSource& rhs);

	void		learnMateria(AMateria *m);
	AMateria	*createMateria(std::string const &type);

};

#endif