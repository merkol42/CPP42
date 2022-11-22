#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor" << std::endl;
}

Intern::Intern(Intern const & ref)
{
	(void)ref;
	std::cout << "Intern Coppy Constructor" << std::endl;
}

Intern&	Intern::operator=(Intern const & ref)
{
	(void)ref;
	std::cout << "Intern Assignment Constructor" << std::endl;
	return (*this);
}

const char*	Intern::Exception::what() const throw()
{
	return ("Unknown Form exception");
}


//make form funcs
static Form*	make_robo(std::string target)
{
	Form *robo = new RobotomyRequestForm(target);
	return (robo);
}

static Form*	make_president(std::string target)
{
	Form *president = new PresidentialPardonForm(target);
	return (president);
}

static Form*	make_shrub(std::string target)
{
	Form *shrub = new ShrubberyCreationForm(target);
	return (shrub);
}

Form*	Intern::makeForm(std::string _form, std::string target)
{
	std::string	formsg[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form*	(*form_funcs[3])(std::string target) = { make_robo, make_president, make_shrub};
	
	Form	*ret = NULL;
	
	for (int i = 0; i < 3; i++)
	{
		if (_form == formsg[i])
			ret = form_funcs[i](target);
	}
	if (ret)
		std::cout << "Intern creates " << *ret << std::endl;
	else
		throw (Intern::Exception());
	return (ret);
}