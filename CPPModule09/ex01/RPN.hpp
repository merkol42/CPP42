#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>

class RPN
{
private:
	std::stack<int>	_data;
	int				_result;
public:
	RPN();
	RPN(const RPN& cpy);
	~RPN();

	RPN&	operator=(const RPN& rhs); 

	void	reversePolishNotation(const std::string& arg);
	bool	isOperator(char c);
	void	calculate(int num1, int num2, char op);
	int		getResult(void) const;

	class insufficientOperands : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("[Error]: insufficient operands");
			}
	};

	class invalidToken : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("[Error]: invalid operand");
			}
	};

	class tooManyOperands : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("[Error]: too many operands");
			}
	};

	class divisionByZero : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("[Error]: division by zero");
			}
	};
};

std::ostream&	operator<<(std::ostream& os, const RPN& obj);

#endif