#include "RPN.hpp"

RPN::RPN() : error(false)
{}

RPN::~RPN()
{}

int RPN::isWrongElement(char element)
{
	if (element >= '0' || element <= '9')
		return 0;
	else if (element == '+' || element == '-' || element == '/' || element == '*' || element == ' ')
		return 0;
	else
		return -1;
}

void RPN::pushElement(char element)
{
	rpnStack.push(element - '0');
}

void RPN::plus()
{
	if (rpnStack.size() < 2)
		error = true;
	else
	{
		int temp = rpnStack.top();
		rpnStack.pop();
		int result = rpnStack.top() + temp; 
		rpnStack.pop();
		rpnStack.push(result);
	}
}

void RPN::minus()
{
	if (rpnStack.size() < 2)
		error = true;
	else
	{
		int temp = rpnStack.top();
		rpnStack.pop();
		int result = rpnStack.top() - temp; 
		rpnStack.pop();
		rpnStack.push(result);
	}
}

void RPN::devide()
{
	if (rpnStack.size() < 2)
		error = true;
	else
	{
		int temp = rpnStack.top();
		if (temp == 0)
			error = true;
		else
		{
			rpnStack.pop();
			int result = rpnStack.top() / temp; 
			rpnStack.pop();
			rpnStack.push(result);
		}
	}
}

void RPN::multiple()
{
	if (rpnStack.size() < 2)
		error = true;
	else
	{
		int temp = rpnStack.top();
		rpnStack.pop();
		int result = rpnStack.top() * temp; 
		rpnStack.pop();
		rpnStack.push(result);
	}
}

bool RPN::isError()
{
	return error;
}

int RPN::getStackSize()
{
	return rpnStack.size();
}

int RPN::getResult()
{
	return rpnStack.top();
}
