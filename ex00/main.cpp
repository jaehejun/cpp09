#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return -1;
	}
	
	std::ifstream inputFile(argv[1]);
	std::string inputLine;
	if (!inputFile.is_open() || !getline(inputFile, inputLine))
	{
		std::cout << "Error: not openable or empty file" << std::endl;
		return -1;
	}

	std::ifstream data("data.csv");
	if (!data.is_open())
	{
		std::cout << "Error: could not open data.csv file." << std::endl;
		return -1;
	}
	
	BitcoinExchange::loadData(data);

	while (std::getline(inputFile, inputLine))
	{
		if (inputLine.empty())
			continue;
		std::stringstream inputStream(inputLine);
		std::string date, value;

		std::getline(inputStream, date, '|');
		int inputDate = BitcoinExchange::checkDate(date);
		if (inputDate == -1)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		
		std::getline(inputStream, value);
		float inputValue = BitcoinExchange::checkValue(value);
		if (inputValue == -1)
			continue;

		BitcoinExchange inputData(inputDate, inputValue);
		std::cout << date << " => " << inputData.getValue() << " = " << inputData.getExchangeRate() * inputData.getValue() << std::endl;
	}
	return 0;
}