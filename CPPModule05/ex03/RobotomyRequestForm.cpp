#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

//sign 72 , exec 45

RobotomyRequestForm::RobotomyRequestForm() : Form("Default", 72, 45)
{
	this->_target = "Default";
	std::cout << "Robotomy Request : " << this->getName() << " : Default Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robo", 72, 45)
{
	this->_target = target;
	std::cout << "Robotomy Request : " << this->getName()<< " : Target Constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request : " << this->getName() << " has been destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & ref) : Form(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	this->_target = ref.getTarget();
	std::cout << "Robotomy Request : " << this->getName() << " Constructed with Copy Constructor" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & ref)
{
	this->_target = ref.getTarget();
	return (*this);
}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

const char* RobotomyRequestForm::FailureException::what() const throw()
{
	return ("Robotomy failure");
}

//random
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	std::cout << "drilling noises." << std::endl;
	int success = std::rand() % 2;
	if (success == 1)
	{
		std::cout << this->_target << " has been robotomized" << std::endl;
	}
	else
		throw (RobotomyRequestForm::FailureException());
}