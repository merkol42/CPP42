#include "RPN.hpp"

RPN::RPN(): _result(0) {}

RPN::RPN(const RPN& cpy)
{
	*this = cpy;
}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
	{
		this->_data = rhs._data;
		this->_result = rhs._result;
	}
	return (*this);
}

bool	RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

void	RPN::reversePolishNotation(const std::string& arg)
{
	std::string	tok;

	for (size_t i = 0; i < arg.length(); i++)
	{
		if (arg[i] == ' ')
			continue;
		else if (isdigit(arg[i]))
		{
			tok = arg[i];
			this->_data.push(atoi(tok.c_str()));
			tok.clear();
		}
		else if (isOperator(static_cast<char>(arg[i])))
		{
			if (_data.size() < 2)
				throw insufficientOperands();
			int	num2 = this->_data.top(); this->_data.pop();
			int	num1 = this->_data.top(); this->_data.pop();
			calculate(num1, num2, arg[i]);
		}
		else
			throw invalidToken();
	}
	if (_data.size() != 1)
		throw tooManyOperands();
	this->_result = _data.top();
	_data.pop();
}

void	RPN::calculate(int num1, int num2, char op)
{
	switch (op)
	{
		case '+':
			_data.push(num1 + num2);
			break;
		case '-':
			_data.push(num1 - num2);
			break;
		case '*':
			_data.push(num1 * num2);
			break;
		case '/':
			if (num2 == 0)
				throw divisionByZero();
			_data.push(num1 / num2);
			break;
	}
}

int	RPN::getResult(void) const
{
	return (this->_result);
}

std::ostream& operator<<(std::ostream& os, const RPN& obj)
{
	os << obj.getResult();
	return (os);
}