#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN
{
	private:
		int argc;
		char **argv;
		std::string inputString;
		std::stack<int> rpnStack;

		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		bool isOperation(char element);
		void pushElement(int element);
		void calculate(char rpnOperator);

	public:
		RPN(int argc, char **argv);
		~RPN();

		void checkArgument();
		void getResult();
		void diplayResult();
};

#endif