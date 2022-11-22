#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			grade_to_sign;
		const int			grade_to_execute;
		bool				_signed;
	public:
		Form();
		~Form();
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(Form const &ref);

		Form&	operator=(Form const &ref);

		const std::string	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		bool				getSigned(void) const;

		void				setSigned(const bool new_value);

		void				beSigned(Bureaucrat& ref);

		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public Form::Exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooHighException : public Form::Exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<( std::ostream & o, Form const & rhs);

#endif