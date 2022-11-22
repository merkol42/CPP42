#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "Default Bureaucrat Constructor Called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		this->grade = grade;
		std::cout << "A Bureaucrat " << name << " with a grade " << grade << " has been constructed" << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called for : " << name << " with a grade " << grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref) : name(ref.getName() + "_copy")
{
	this->grade = ref.getGrade();
	std::cout << "Coppy Constructor : A Bureaucrat " << name << " with a grade " << grade << " has been constructed" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &ref)
{
	this->grade = ref.getGrade();
	return (*this);
}

void	Bureaucrat::incrementGrade()
{
	std::cout << "Incrementing bureaucrat " << name << "'s grade " << grade << " by 1" << std::endl;
	if (this->grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		this->grade--;
	}
}

void	Bureaucrat::decrementGrade()
{
	std::cout << "Decrementing bureaucrat " << name << "'s grade " << grade << " by 1" << std::endl;
	if (this->grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
	{
		this->grade++;
	}
}

//Get & Set
const std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::setGrade(const int newgrade)
{
	if (newgrade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (newgrade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		this->grade = newgrade;
		std::cout << "Bureaucrat " << this->name << "'s grade was set to " << newgrade << std::endl;
	}
}

// << operator overload
std::ostream & operator<<( std::ostream & os, Bureaucrat const & rhs)
{
	os << rhs.getName() << " bureaucrat grade = " << rhs.getGrade();
	return (os);
}

// Exceptions
const char* Bureaucrat::Exception::what() const throw()
{
	return ("BureaucratException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Cannot get a grade > 150!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Cannot get a grade < 1!");
};