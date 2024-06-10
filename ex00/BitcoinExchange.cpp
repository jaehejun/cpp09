#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{}

BitcoinExchange::~BitcoinExchange()
{}

void BitcoinExchange::getData(std::ifstream &data)
{
	std::string line;
	//std::string date;
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

float BitcoinExchange::getExchangeRate(std::string &inputDate)
{
	std::map<std::string,float>::iterator it = marketPrice.upper_bound(inputDate);
	--it;
	std::cout << "DATE: " << it->first << std::endl;
	std::cout << "RATE: " << it->second << std::endl;
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