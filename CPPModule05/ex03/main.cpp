#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));

	Intern	intern;
	Form	*robo;
	Form	*shrub;
	Form	*president;;
	
	std::cout << "--INTERN--" << std::endl;
	std::cout << "--1--" << std::endl;
	robo = intern.makeForm("robotomy request", "Mete");
	std::cout << "Created : " << *robo << std::endl;

	std::cout << "--2--" << std::endl;
	president = intern.makeForm("presidential pardon", "Apollo11");
	std::cout << "Created : " << *president << std::endl;

	std::cout << "--3--" << std::endl;
	shrub = intern.makeForm("shrubbery creation", "BigF");
	std::cout << "Created : " << *shrub << std::endl;

	std::cout << "--Unknown Form Test--" << std::endl;
	Form	*unknown;
	try
	{
		unknown = intern.makeForm("Lozan", "aggreement");
		std::cout << "Created : " << *unknown << std::endl << std::endl;
		delete unknown;
	}
	catch (Intern::Exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "DESTRUCTORS:" << std::endl;
	delete robo;
	delete shrub;
	delete president;
	return (0);
}