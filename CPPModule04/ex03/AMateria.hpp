#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class	ICharacter;

class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	AMateria(const AMateria& rhs);
	AMateria(std::string const &type);
	virtual ~AMateria();

	AMateria&	operator=(const AMateria& rhs);

	std::string const &getType() const;// return type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif