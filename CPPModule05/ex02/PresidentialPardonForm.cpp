#include "PresidentialPardonForm.hpp"

//sign 25, exec 5

PresidentialPardonForm::PresidentialPardonForm() : Form("Default President", 25, 5)
{
	this->_target = "Default";
	std::cout << "Presidential Pardon : " << this->getName() << " : Default Constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("President", 25, 5)
{
	this->_target = target;
	std::cout << "Presidential Pardon : " << this->getName() << " : Target Constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon : " << this->getName() << " has been destroyed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : Form(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	this->_target = ref.getTarget();
	std::cout << "Presidential Pardon : " << this->getName() << " Constructed with Copy Constructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & ref)
{
	this->_target = ref.getTarget();
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (this->getSigned() == false)
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	else
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}