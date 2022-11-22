#include "Character.hpp"
#include "AMateria.hpp"

Character::Character():ICharacter()
{
	std::cout << "Character Default Constructor Called!" << std::endl;
	for (size_t i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (size_t i = 0; i < 20; i++)
		this->dropped_materials[i] = NULL;
}

Character::Character(std::string _name) :ICharacter(), name(_name)
{
	std::cout << this->name << ": Character String Constructor Called!" << std::endl;
	for (size_t i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (size_t i = 0; i < 20; i++)
		this->dropped_materials[i] = NULL;
}

Character::Character(const Character& rhs) :name(rhs.name + "_copy")
{
	std::cout << "Character Copy Constructor Called!" << std::endl;
	*this = rhs;
}

Character::~Character()
{
	std::cout << this->name << ": Character Destructor Called!" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
			delete	this->inventory[i];
	}
	for (size_t i = 0; i < 20; i++)
	{
		if (this->dropped_materials[i] != NULL)
			delete	this->dropped_materials[i];
	}
}

Character&	Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.getName();
		for (size_t i = 0; i < 4; i++)
		{
			this->inventory[i] = NULL;
			if (rhs.inventory[i] != NULL)
				this->inventory[i] = rhs.inventory[i]->clone();
		}
		for (size_t i = 0; i < 20; i++)
		{
			this->dropped_materials[i] = NULL;
			if (rhs.dropped_materials[i] != NULL)
				this->dropped_materials[i] = rhs.dropped_materials[i]->clone();
		}
		std::cout << "Character Assignment Operator Called!" << std::endl;
		return (*this);
	}
	std::cout << "Character :" << this->name << " Already same :" << rhs.name << std::endl;
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "There is a nothing materia to equip!" << std::endl;
		return ;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			std::cout << "Character equip() Called!" << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full! Delete is called for parameter" << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (this->inventory[idx] != NULL)
	{
		for (size_t i = 0; i < 20; i++)
		{
			if (this->dropped_materials[i] == NULL)
			{
				std::cout << this->getName() << ": unequip materia at the index :" << idx << std::endl;
				this->dropped_materials[i] = this->inventory[idx];
				this->inventory[idx] = NULL;
				return ;
			}
		}
	}
	std::cout << "There is nothing available in the index for unequip" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if ((idx < 0 || idx >= 4) || !this->inventory[idx])
	{
		std::cout	<< this->getName() << ": There is nothing available in the index for use : " 
					<< idx << std::endl;
		return ;
	}
	this->inventory[idx]->use(target);
}