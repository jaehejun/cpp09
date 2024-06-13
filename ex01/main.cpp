#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return std::cout << "Error" << std::endl, -1;

	std::string input = argv[1];
	for (size_t i = 0; i < input.size(); ++i)
	{
		if (i % 2 == 1 && input[i] != ' ')
			return std::cout << "Error" << std::endl, -1;
	}
	
	RPN rpn;

	for (size_t i = 0; i < input.length(); ++i)
	{
		if (rpn.isWrongElement(input[i]))
			return std::cout << "Error" << std::endl, -1;

		switch(input[i])
		{
			case ' ':
				break;
			case '+':
				rpn.plus();
				break;
			case '-':
				rpn.minus();
				break;
			case '/':
				rpn.devide();
				break;
			case '*':
				rpn.multiple();
				break;
			default:
				rpn.pushElement(input[i]);
		}
		if (rpn.isError())
			return std::cout << "Error" << std::endl, -1;
	}
	if (rpn.getStackSize() != 1)
		return std::cout << "Error" << std::endl, -1;
	std::cout << rpn.getResult() << std::endl;
	return 0;
}