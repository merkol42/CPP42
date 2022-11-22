#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;//150 = lowest, 1 = highest
public:
	Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	Bureaucrat(const Bureaucrat& ref);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& ref);

	void	incrementGrade();
	void	decrementGrade();

	const std::string	getName(void) const;
	int					getGrade(void) const;

	void				setGrade(int _grade);

	//Exceptions
	class Exception: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public Exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooHighException: public Exception
	{
		public:
			virtual const char* what() const throw();
	};

	// Ex01
	void	signForm(Form& ref);

	// Ex02
	void	executeForm(Form const & form);
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& ref);

#endif