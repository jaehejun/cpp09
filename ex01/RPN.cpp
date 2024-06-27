#include "RPN.hpp"

RPN::RPN(int argc, char **argv) : argc(argc), argv(argv), inputString(), rpnStack()
{}

RPN::~RPN()
{}

void RPN::checkArgument()
{
	if (argc != 2)
		throw std::invalid_argument("Error");
	
	inputString = argv[1];
	for (size_t i = 0; i < inputString.size(); ++i)
	{
		if (inputString[i] == ' ')
			break;
		if ((inputString[i] < '0' || inputString[i] > '9') && !isOperation(inputString[i]))
			throw std::invalid_argument("Error");
	}
}

void RPN::getResult()
{
	for (size_t i = 0; i < inputString.length(); ++i)
	{
		if (inputString[i] == ' ')
			continue;
		if (isOperation(inputString[i]))
			calculate(inputString[i]);
		else
			pushElement(inputString[i] - '0');
	}
	if (rpnStack.size() != 1)
		throw std::logic_error("Error");
}

void RPN::diplayResult()
{
	std::cout << rpnStack.top() << std::endl;
}

bool RPN::isOperation(char element)
{
	if (element == '+' || element == '-' || element == '/' || element == '*')
		return true;
	return false;
}

void RPN::pushElement(int element)
{
	rpnStack.push(element);
}

void RPN::calculate(char rpnOperator)
{
	if (rpnStack.size() < 2)
		throw std::logic_error("Error");
	int result;
	int temp = rpnStack.top();
	rpnStack.pop();

	if (rpnOperator == '+')
		result = rpnStack.top() + temp;
	else if (rpnOperator == '-')
		result = rpnStack.top() - temp;
	else if (rpnOperator == '*')
		result = rpnStack.top() * temp;
	else // rpnOperator == '/'
	{
		if (temp == 0)
			throw std::domain_error("Error");
		result = rpnStack.top() / temp;
	}
	//std::cout << rpnStack.top() << " " << rpnOperator << " " << temp << " = " << result << std::endl;
	rpnStack.pop();
	rpnStack.push(result);
	//std::cout << "Top() : " << rpnStack.top() << std::endl;
}
