#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character: public ICharacter
{
private:
	std::string	name;
	AMateria	*inventory[4];
	AMateria	*dropped_materials[20];
public:
	Character();
	Character(std::string _name);
	Character(const Character& rhs);
	~Character();

	Character&	operator=(const Character& rhs);

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif // CHARACTER_HPP
