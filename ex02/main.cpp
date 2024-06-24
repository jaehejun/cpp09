#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		PmergeMe myFord(argc, argv);
		myFord.checkInputString();
		myFord.executeSorting();
		myFord.verify();
		//myFord.printResult();

	}
	catch (std::logic_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}