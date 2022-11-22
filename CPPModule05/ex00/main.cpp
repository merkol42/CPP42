#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat mete("Mete", -49);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat mete("Mete", 256);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << "INCREMENT & DECREMENT" << std::endl << "------------------------------------" << std::endl;
	
	Bureaucrat apollo11("Apollo11", 1);
	try
	{
		apollo11.decrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}

	std::cout << apollo11 << std::endl;
	
	try
	{
		apollo11.incrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << apollo11;
	std::cout << std::endl << std::endl;
	
	std::cout << std::endl;
	std::cout << "INCREMENT GRADE:" << std::endl << "----------------------------" << std::endl;
	try
	{
		apollo11.incrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "set grade excp" << std::endl << "---------------------------" << std::endl;
	try
	{
		apollo11.setGrade(145);
	}
	catch(Bureaucrat::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		apollo11.decrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;

	Bureaucrat zaa(apollo11);
	std::cout << zaa << std::endl << std::endl;
	std::cout << "--------Destructor--------" << std::endl;
	return (0);
}