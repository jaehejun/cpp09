#include "BitcoinExchange.hpp"

std::map<std::string,float> BitcoinExchange::marketPrice;

BitcoinExchange::BitcoinExchange(std::string &date, float &value) :  inputDate(date), inputValue(value)
{}

BitcoinExchange::~BitcoinExchange()
{}

void BitcoinExchange::getData(std::ifstream &data)
{
	std::string line;
	float rate;

	std::getline(data, line);
	while (std::getline(data, line))
	{
		std::string date = line.substr(0,10);
		std::stringstream value(line.substr(11));
		value >> rate;
		marketPrice[date] = rate;
	}
}

void BitcoinExchange::checkValid()
{
	//inputDate
	//inputValue

	//throw std::exception();
	;
}

std::string BitcoinExchange::getDate()
{
	return inputDate;
}
float BitcoinExchange::getValue()
{
	return inputValue;
}

float BitcoinExchange::getExchangeRate(std::string &inputDate)
{
	std::map<std::string,float>::iterator it = marketPrice.upper_bound(inputDate);
	--it;
	return it->second;
}

void BitcoinExchange::printMap()
{
	std::map<std::string, float>::iterator it;
	for (it = marketPrice.begin(); it != marketPrice.end(); ++it)
	{
		std::cout << it->first << " : " << it->second << std::endl;
	}
}