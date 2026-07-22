#include "RPN.hpp"

RPN::RPN() : _stack()
{
}

RPN::RPN(const RPN &other) : _stack(other._stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

void RPN::pushNumber(const int num)
{
	_stack.push(num);
}

int RPN::compute(const char op)
{
	int	num1;
	int	num2;
	int	result;

	if (op != '+' && op != '*' && op != '-' && op != '/')
		return (0);
	if (_stack.size() < 2)
		return (0);
	num1 = _stack.top();
	_stack.pop();
	num2 = _stack.top();
	_stack.pop();
	result = 0;
	if (op == '+')
		result = num2 + num1;
	else if (op == '-')
		result = num2 - num1;
	else if (op == '*')
		result = num2 * num1;
	else if (op == '/')
	{
		if (num1 == 0)
		{
			// restore stack state
			_stack.push(num2);
			_stack.push(num1);
			return (0);
		}
		result = num2 / num1;
	}
	_stack.push(result);
	return (1);
}

int RPN::top() const
{
	return (_stack.top());
}

bool RPN::empty() const
{
	return (_stack.empty());
}

int RPN::size() const
{
	return (static_cast<int>(_stack.size()));
}
