#include "RPN.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	std::cout << "+: " << int('+') << std::endl;
	std::cout << "-: " << int('-') << std::endl;
	std::cout << "/: " << int('/') << std::endl;
	std::cout << "*: " << int('*') << std::endl;
	if (argc != 2)
		return std::cout << "Error" << std::endl, -1;

	std::stack<int> rpn;

	std::string input = argv[1];
	
	std::cout << input << std::endl;

	for (size_t i = 0; i < input.length(); ++i)
	{
		//if (!isdigit(input[i]) || input[i] != ' ' || input[i] != '+' || input[i] != '-' || input[i] != '/' || input[i] != '*')
		//	return std::cout << "fError" << std::endl, -1;
		int lvalue;
		int rvalue;
		switch (input[i])
		{
			case ' ':
				break;
			case '+':
				if (rpn.size() != 2)
					return std::cout << "+Error" << std::endl, -1;
				lvalue = rpn.top();
				rpn.pop();
				rvalue = rpn.top();
				rpn.pop();
				rpn.push(lvalue + rvalue);
				break;
			case '-':
				if (rpn.size() != 2)
					return std::cout << "-Error" << std::endl, -1;
				lvalue = rpn.top();
				rpn.pop();
				rvalue = rpn.top();
				rpn.pop();
				rpn.push(lvalue - rvalue);
				break;
			case '/':
				if (rpn.size() != 2)
					return std::cout << "/Error" << std::endl, -1;
				lvalue = rpn.top();
				rpn.pop();
				rvalue = rpn.top();
				rpn.pop();
				rpn.push(lvalue / rvalue);
				break;
			case '*':
				if (rpn.size() != 2)
					return std::cout << "*Error" << std::endl, -1;
				lvalue = rpn.top();
				rpn.pop();
				rvalue = rpn.top();
				rpn.pop();
				rpn.push(lvalue * rvalue);
				break;
			default:
				rpn.push(static_cast<int>(input[i]));
				std::cout << rpn.top() << std::endl;
		}
	}
	return 0;
}