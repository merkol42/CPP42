#include "ShrubberyCreationForm.hpp"
#include <iomanip>
#include <fstream>

//sign 145 , exec 137

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Default Shrub", 145, 137)
{
	this->_target = "Default";
	std::cout << "Shrubbery Creation : " << this->getName() << " : Default Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrub", 145, 137)
{
	this->_target = target;
	std::cout << "Shrubbery Creation : " << this->getName() << " : Target Constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation : " << this->getName() << " has been destroyed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : Form(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	this->_target = ref.getTarget();
	std::cout << "Shrubbery Creation : " << this->getName() << " Constructed with Copy Constructor" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	this->_target = ref.getTarget();
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}


void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::string	tree = 
						"     ccee88oo          \n"
						"  C8O8O8Q8PoOb o8oo    \n"
						" dOB69QO8PdUOpugoO9bD  \n"
						"CgggbU8OU qOp qOdoUOdcb\n"
						"   6OuU  /p u gcoUodpP \n"
						"      \\\\//  /douUP   \n"
						"        \\\\////       \n"
						"         |||/\\        \n"
						"         |||\\/        \n"
						"         |||||         \n"
						"  .....\\//||||\\....  \n";

	if (this->getSigned() == false)
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	else
	{
		std::cout << " FILE CREATEEE " << std::endl;
		// std::fstream	ofs(this->_target + "_shrubbery", std::ios::out);
		// if (!ofs.is_open())
		// {
		// 	std::cout << "Coulnd't open the output file" << std::endl;
		// 	return ;
		// }
		// ofs << tree;
		// ofs.close();
	}
}