#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Form;

class RobotomyRequestForm : public Form
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& ref);
		
		std::string	getTarget() const;
		void		execute(const Bureaucrat& executor) const;

		// Failure
		class FailureException : public Form::Exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif