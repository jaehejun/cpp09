#include <iostream>
#include <map>
#include <stack>
#include <fstream>
#include <sstream>

void printMap(std::map<std::string, float> &m)
{
	for (std::map<std::string, float>::iterator itr = m.begin(); itr != m.end(); ++itr)
	{
		std::cout << itr->first << " " << itr->second << std::endl;
	}
}

int main(int argc, char** argv)
{
	std::stringstream ss(argv[1]);
	std::string date;
	std::string value;
	float fValue;

	std::getline(ss, date, '|');
	std::getline(ss, value, '|');

	std::stringstream val(value);
	val >> fValue;

	std::cout << "DATE:" << date << std::endl;
	std::cout << "VALL:" << fValue << std::endl;

	//std::string date1 = "2011-01-10";
	//std::string date2 = "2011-01-09";

	//if (date1 < date2)
	//	std::cout << date1 << std::endl;
	//else
	//	std::cout << date2 << std::endl;

	//std::map<std::string, float> marketPrice;

	//marketPrice["2022-03-22"] = 42372.67;
	//marketPrice.insert(std::pair<std::string, float>("2022-03-25", 44334.33));
	//marketPrice.insert(std::make_pair("2022-03-29", 47115.93));


	//std::cout << "2022/03/22 : " << marketPrice["2022-03-22"] << std::endl;
	//std::map<std::string,float>::iterator it = marketPrice.find("2022-03-25");
	//if (it != marketPrice.end())
	//	std::cout << it->second << std::endl;

	return 0;
}