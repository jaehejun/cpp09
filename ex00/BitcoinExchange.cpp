#include "BitcoinExchange.hpp"

std::map<std::string,float> BitcoinExchange::marketPrice;

BitcoinExchange::BitcoinExchange(std::string &date, float &value) :  inputDate(date), inputValue(value)
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
		std::string date = line.substr(0,10);
		std::stringstream value(line.substr(11));
		value >> rate;
		marketPrice[date] = rate;
	}
}

void BitcoinExchange::loadInput(std::string &inputLine)
{
	std::stringstream inputStream(inputLine);
	std::string date, value, year, month, day;
	//float fValue;

	std::getline(inputStream, date, '|');
	if (date.empty())
		throw std::exception();
}

void BitcoinExchange::checkDate()
{
	// inputDate 가 빈문자열 -> 
	if (inputDate.empty())
		throw std::exception();
	
	std::stringstream checkStream(inputDate);
	std::string year, month, day;
	int intYear, intMonth, intDay;

	std::getline(checkStream, year, '-');
	std::stringstream checkYear(year);
	checkYear >> intYear;


	std::getline(checkStream, month, '-');
	std::stringstream checkMonth(month);
	checkMonth >> intMonth;


	std::getline(checkStream, day, '-');
	std::stringstream checkDay(day);
	checkDay >> intDay;


	std::cout << "Y:" << intYear << std::endl;
	std::cout << "M:" << intMonth << std::endl;
	std::cout << "D:" << intDay << std::endl;
	//size_t pos = inputDate.find("-");
	//std::string year = inputDate.substr(0,pos);
	

	// inputDate가 data.csv의 가격형성일 이전
	std::map<std::string,float>::iterator it = marketPrice.begin();
	if (inputDate < it->first)
		throw std::exception();
	//std::map<std::string,float>::iterator it = marketPrice.upper_bound(inputDate);
	//std::cout << it->first << ":" << it->second << std::endl;
}

void BitcoinExchange::checkValue()
{
	if (inputValue == 0)
		throw std::exception();
	

}

std::string BitcoinExchange::getDate()
{
	return inputDate;
}

float BitcoinExchange::getValue()
{
	return inputValue;
}

std::string BitcoinExchange::getMarketDate(std::string &date)
{
	std::map<std::string,float>::iterator it = marketPrice.upper_bound(date);
	--it;
	return it->first;
}

float BitcoinExchange::getMarketValue(std::string &date)
{
	std::map<std::string,float>::iterator it = marketPrice.upper_bound(date);
	--it;
	return it->second;
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