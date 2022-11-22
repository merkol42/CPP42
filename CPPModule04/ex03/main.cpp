#include <iostream>
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <string.h>

int main(void)
{
	std::cout << "------------CONSTRUCTOR------------ " << std::endl;
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::string name = me->getName();
	std::cout << name << std::endl;

	std::cout << "-----------MATERIA INIT-------------- " << __LINE__ << std::endl;

	AMateria* tmp, *tmp1;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);
	std::cout << std::endl;

	std::cout << "-----------NEW CHARACTER USE-------------- " << __LINE__ << std::endl;

	ICharacter* bob = new Character("bob");
	me->use(2, *bob);
	me->use(4, *bob);
	std::cout << std::endl;
	me->use(10, *bob);
	me->use(-1, *bob);
	std::cout << std::endl;

	std::cout << "-----------DEEP COPPY TESTS-------------- " << __LINE__ << std::endl;
	Character	*mete = new Character("mete");
	tmp = src->createMateria("ice");
	mete->equip(tmp);
	tmp = src->createMateria("cure");
	mete->equip(tmp);
	tmp = src->createMateria("fire");
	mete->equip(tmp);
	Character	*metecpy = new Character("denemeçar");
	std::cout << std::endl;

	std::cout << "-----------MATERIA OVERFLOW AND LEAKS TEST-------------- " << __LINE__ << std::endl;

	IMateriaSource *materia = new MateriaSource();
	materia->learnMateria(new Ice());
	materia->learnMateria(new Ice());
	materia->learnMateria(new Ice());
	materia->learnMateria(new Ice());
	materia->learnMateria(new Ice());

	delete materia;

	std::cout << std::endl;
	std::cout << "-----------ASSIGNMENT && PROTECT TEST-------------- " << __LINE__ << std::endl;
	Character	*zaa = new Character("sea");
	Character	*a = zaa;
	*zaa = *a;
	std::cout << zaa->getName() << std::endl;

	std::cout << "-----------UNEQUIP TEST-------------- " << __LINE__ << std::endl;
	me->unequip(0);
	me->unequip(0);
	me->use(0, *bob);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	std::cout << std::endl;

	std::cout << "-----------DELETE-------------- " << __LINE__ << std::endl;
	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
	delete mete;
	delete metecpy;
	delete zaa;
	return 0;
}