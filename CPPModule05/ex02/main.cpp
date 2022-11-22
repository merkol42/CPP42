#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));
	/*
		ShrubberryCreation		sign 145, exec 137
		RobotomyRequest			sign 72, exec 45
		PresidentialPardon		sign 25, exec 5
	*/
	std::cout << std::endl << "--CONSTRUCTOR--" << std::endl;
	Bureaucrat				mete("Mete", 1);
	Bureaucrat				apollo11("Apollo11", 142);
	ShrubberyCreationForm	shrub("Shrubb");
	RobotomyRequestForm		robo("Roboo");
	PresidentialPardonForm	president("Presidentt");
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "ShrubberyCreationForm:" << std::endl;

	mete.executeForm(shrub);
	shrub.beSigned(mete);

	mete.executeForm(shrub);
	std::cout << std::endl;

	apollo11.executeForm(shrub);
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "RobotomyRequestForm:" << std::endl;
	mete.executeForm(robo);
	robo.beSigned(mete);


	std::cout << std::endl << "--%50 chance--" << std::endl;
	mete.executeForm(robo);
	mete.executeForm(robo);
	mete.executeForm(robo);
	mete.executeForm(robo);
	std::cout << std::endl;

	std::cout << std::endl << "--1--" << std::endl;
	apollo11.executeForm(robo);
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "PresidentialPardonForm:" << std::endl;

	std::cout << std::endl << "--2--" << std::endl;
	mete.executeForm(president);
	president.beSigned(mete);

	std::cout << std::endl << "--3--" << std::endl;
	mete.executeForm(president);
	std::cout << std::endl;

	std::cout << std::endl << "--4--" << std::endl;
	apollo11.executeForm(president);
	std::cout << std::endl << std::endl;

	std::cout << "--DESTRUCTORS--" << std::endl;
	return (0);
}