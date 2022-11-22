#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Bureaucrat Constructor:" << std::endl;
	Bureaucrat	mete("Mete", 1);
	Bureaucrat	apollo11("Apollo11", 132);

	std::cout << std::endl << std::endl;

	std::cout << "Form Constructor:" << std::endl;
	Form		a("agreement1", 13, 52);
	Form		b("agreement2", 146, 135);

	std::cout << std::endl << std::endl;
	
	std::cout << "Exception Test:" << std::endl;
	try
	{
		Form	c("deneme", 311, 242);
	}
	catch (Form::Exception &e)
	{
		std::cout << "Constructor fail: " << e.what() << std::endl;
	}

	try
	{
		Form	c("seaa", -400, -300);
	}
	catch (Form::Exception &e)
	{
		std::cout << "Constructor fail: " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST1(OK)" << std::endl;
	mete.signForm(a);
	std::cout << a << " <- current status" << std::endl;
	a.setSigned(false);
	std::cout << std::endl << std::endl;

	std::cout << "TEST2(KO)" << std::endl;
	apollo11.signForm(a);
	std::cout << a << " <- current status" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "TEST3(OK)" << std::endl;
	mete.signForm(b);
	std::cout << b << " <- current status" << std::endl;
	b.setSigned(false);
	std::cout << std::endl << std::endl;
	
	std::cout << "TEST4(OK)" << std::endl;
	apollo11.signForm(b);
	std::cout << b << " <- current status" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "DESTRUCTORS:" << std::endl;
	return (0);
}