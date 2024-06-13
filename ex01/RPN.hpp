#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN
{
	private:
		std::stack<int> rpnStack;
		bool error;

		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

	public:
		RPN();
		~RPN();

		int isWrongElement(char element);
		void pushElement(char element);

		void plus();
		void minus();
		void devide();
		void multiple();

		bool isError();

		int getStackSize();
		int getResult();
};

#endif