#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN myRpn(argc, argv);
	try
	{
		myRpn.checkArgument();
		myRpn.getResult();
		myRpn.diplayResult();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}