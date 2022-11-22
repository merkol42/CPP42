#include "AForm.hpp"

Form::Form() : name("Default"), grade_to_sign(150), grade_to_execute(150), _signed(0)
{
	std::cout << "A default " << this->name << " has been constructed" << std::endl;
}

Form::~Form()
{
	std::cout << "form : " << this->name << " has been destroyed" << std::endl;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute), _signed(0)
{
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw (Form::GradeTooLowException());
	else if (grade_to_sign < 1 || grade_to_execute < 1)
		throw (Form::GradeTooHighException());
	else
		std::cout << "Form :" << this->name << " has been constructed" << std::endl;
}

Form::Form(const Form& ref) : name(ref.getName()), grade_to_sign(ref.getGradeToSign()), grade_to_execute(ref.getGradeToExecute()), _signed(ref.getSigned())
{
	std::cout << "Coppy Constructor Called for : " << *this << std::endl;
}

Form & Form::operator=(const Form& ref)
{
	this->_signed = ref.getSigned();
	return (*this);
}

// Get & Set
const std::string	Form::getName() const
{
	return (this->name);
}

int		Form::getGradeToSign() const
{
	return (this->grade_to_sign);
}

int		Form::getGradeToExecute() const
{
	return (this->grade_to_execute);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

// set
void	Form::setSigned( const bool new_value)
{
	std::cout << this->name << " signed value was set to " << new_value << std::endl;
	this->_signed = new_value;
}

// Nested Exception Classes
const char* Form::Exception::what() const throw()
{
	return ("FormException");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("the grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("the grade is too high");
};

const char* Form::UnsignedFormException::what() const throw()
{
	return ("Cannot execute an unsigned form");
};

std::ostream&	operator<<(std::ostream& os, Form const & rhs)
{
	os << "Form " << rhs.getName() << " having a grade_to_sign : " << rhs.getGradeToSign() << " , grade_to_execute : "
		<< rhs.getGradeToExecute() << " , signed : " << rhs.getSigned() << ".";
	return (os);
}

void	Form::beSigned(Bureaucrat& ref)
{
	int	grade = ref.getGrade();

	if (grade > grade_to_sign)
	{
		throw (Form::GradeTooLowException());
		return ;
	}
	_signed = true;
	std::cout << *this << " was just signed by the bureaucrat " << ref.getName() << " with a grade " << ref.getGrade() << std::endl;
}