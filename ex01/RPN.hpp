#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <stack>
#include <iostream>

class RPN
{
	private:
		std::stack<int> rpnStack;
		int result;

		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

	public:
		RPN();
		~RPN();
};

#endif