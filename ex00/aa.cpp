#include <iostream>
#include <string>
#include <algorithm>

//bool isValid(const std::string &date)
//{
//	struct tm tm = {0};
//	std::istringstream ss(date);

//	ss >> std::get_time(&tm, "%Y-%m-%d");
//	if (ss.fail())
//	{
//		return false;
//	}

//	std::time_t t = std::mktime(&tm);
//	if (t == -1)
//	{
//		return false;
//	}

//	char buf[100];
//	std::strftime(buf, sizeof(buf), "%Y-%m-%d", &tm);
//	return date == buf;
//}

int main()
{
	std::string valid = "123.123";
	std::string invalid = "123.123.123";
	int dotCount = std::count(valid.begin(), valid.end(), '.');
	int indotCount = std::count(invalid.begin(), invalid.end(), '.');

	std::cout << "Valid: " << dotCount << std::endl;
	std::cout << "Invalid: " << indotCount << std::endl;;
}