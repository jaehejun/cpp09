#include "BitcoinExchange.hpp"

std::map<int,float> BitcoinExchange::marketPrice;

BitcoinExchange::BitcoinExchange(int &date, float &value) :  inputDate(date), inputValue(value)
{}

BitcoinExchange::~BitcoinExchange()
{}

void BitcoinExchange::loadData(std::ifstream &data)
{
	std::string line;
	float rate;

	std::getline(data, line);
	while (std::getline(data, line))
	{
		std::string date = line.substr(0,4) + line.substr(5,2) + line.substr(8,2);
		int intDate = std::atoi(date.c_str());
		std::stringstream value(line.substr(11));
		value >> rate;
		marketPrice[intDate] = rate;
	}
}

int BitcoinExchange::checkDate(std::string &date)
{
	if (date[10] != ' ' || date.length() != 11)
		return -1;
	if (date[4] != '-' || date[7] != '-')
		return -1;

	std::string trimmed = date.substr(0,4) + date.substr(5,2) + date.substr(8,2);

	// not digit include
	for (size_t i = 0; i < trimmed.length(); ++i)
	{
		if (!isdigit(trimmed[i]))
			return -1;
	}

	int intDate = std::atoi(trimmed.c_str());
	if (intDate < marketPrice.begin()->first)
		return -1; // bad input + date(no rate exists)

	int year, month, day;
	year = std::atoi(date.substr(0,4).c_str());
	month = std::atoi(date.substr(5,2).c_str());
	day = std::atoi(date.substr(8,2).c_str());

	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day < 1 || day > 31)
				return -1;
			break;
		case 4: case 6: case 9: case 11:
			if (day < 1 || day > 31)
				return -1;
			break;
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			{
				if (day < 1 || day > 29)
					return -1;
			}
			if (day < 1 || day > 28)
				return -1;
			break;
		default:
				return -1;
	}
	return intDate;
}

float BitcoinExchange::checkValue(std::string &value)
{
	float fValue;

	if (value.empty() || value.length() < 2 || value[0] != ' ')
		return std::cout << "Error: not a number" << std::endl, -1;
	if (int dotCount = std::count(value.begin(), value.end(), '.') > 1)
		return std::cout << "Error: not a valid number" << std::endl, -1;
	for (size_t i = 1; i < value.length(); ++i)
	{
		if (!(isdigit(value[i]) || value[i] == '.' || value[i] == '-'))
			return std::cout << "Error: not a number" << std::endl, -1;
	}
	if (value[1] == '-')
		return std::cout << "Error: not a positive nubmer" << std::endl, -1;
	std::stringstream valStream(value);
	valStream >> fValue;

	if (fValue > 1000)
		return std::cout << "Error: too large a number" << std::endl, -1;

	return fValue;
}

int BitcoinExchange::getDate()
{
	return inputDate;
}

float BitcoinExchange::getValue()
{
	return inputValue;
}

float BitcoinExchange::getExchangeRate()
{
	std::map<int,float>::iterator it = marketPrice.upper_bound(inputDate);
	if (it == marketPrice.begin())
		return -1;
	--it;
	return it->second;
}