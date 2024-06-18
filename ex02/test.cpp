#include <iostream>
#include <vector>

int main()
{
	std::vector<int> input;
	input.push_back(12);
	input.push_back(4);
	input.push_back(16);
	input.push_back(1);
	input.push_back(6);
	input.push_back(19);
	input.push_back(5);
	input.push_back(9);
	input.push_back(2);
	input.push_back(20);
	input.push_back(11);
	input.push_back(18);
	input.push_back(7);
	input.push_back(14);
	input.push_back(3);
	input.push_back(13);
	input.push_back(8);
	input.push_back(17);
	input.push_back(10);
	input.push_back(15);

	std::cout << "SIZE:" << input.size() << std::endl;
// n  = 20, depth = 0
	size_t n = input.size();
	int depth = 0;

	for (size_t i = 0; i < n;) 
	{
		if (input[i] < input[i+1])
			std::swap(input[i], input[i+1]);
		i += 2;
	}

// n / 2^depth = 10
	depth += 1; // 1
	std::vector<int> first;
	for (size_t i = 0; i < n;) // n -> 20, depth -> 1
	{
		first.push_back(input[i]);
		++i;
		for (size_t sub = 0; sub < depth; ++sub)
		{
			first.push_back(input[i + sub]);
			++i;
		}
	}
	for (size_t i = 0; i < first.size(); ++i)
	{
		std::cout << "1st:" << first[i] << std::endl;
		i += depth;
	}
	for (size_t i = 0; i < first.size();)
	{
		if (first[i] < first[i+1+depth])
		{
			for (size_t sub = 0; sub < depth; ++sub)
				std::swap(first[i], first[i+1+sub]);

		}
		i += 2 * depth;
	}

	depth += 1; // 2
	std::vector<int> second;
	for (size_t i = 0; i < n;) // n -> 20, depth -> 1
	{
		second.push_back(input[i]);
		++i;
		for (size_t sub = 0; sub < depth; ++sub)
		{
			second.push_back(input[i + sub]);
			++i;
		}
	}
	for (size_t i = 0; i < second.size(); ++i)
	{
		std::cout << "2nd:" << second[i] << std::endl;
		i += depth;
	}


}