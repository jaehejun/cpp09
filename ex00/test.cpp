#include <iostream>
#include <map>
#include <vector>
#include <stack>

int main()
{
	//std::string date1 = "2011-01-10";
	//std::string date2 = "2011-01-09";

	//if (date1 < date2)
	//	std::cout << date1 << std::endl;
	//else
	//	std::cout << date2 << std::endl;

	std::vector<int> my;

	std::cout << &my << std::endl;
	std::cout << "size: " << my.size() << std::endl;
	my.push_back(3);
	my.push_back(4);
	std::vector<int>::iterator it = my.begin();
	std::vector<int>::iterator itEnd = my.end();
	std::cout << "begin(): " << &it << std::endl;
	std::cout << "end(): " << &itEnd << std::endl;
	std::cout << "begin() is pointing: " << &*it << std::endl;
	std::cout << "vector[0]: " << &my[0] << std::endl;
	std::cout << "end() is pointing: " << &*itEnd << std::endl;
	std::cout << "vector[1]: " << &my[1] << std::endl;
	std::cout << "vector[2]: " << &my[2] << std::endl;


	//std::cout << "begin: " << *it << std::endl;
	//std::cout << "end: " << *(--itEnd) << std::endl;

	return 0;
}