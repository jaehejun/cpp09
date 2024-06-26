#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc == 1)
		return std::cout << "Error: could not open file." << std::endl, -1;
	if (argc > 2)
		return std::cout << "Error: too many arguments." << std::endl, -1;
	
	std::ifstream inputFile(argv[1]);
	std::string inputLine;
	if (!inputFile.is_open() || !getline(inputFile, inputLine))
		return std::cout << "Error: could not open file" << std::endl, -1;

	std::ifstream data("data.csv");
	if (!data.is_open())
		return std::cout << "Error: could not open data.csv file." << std::endl, -1;
	
	BitcoinExchange::loadData(data);

	while (std::getline(inputFile, inputLine))
	{
		if (inputLine.empty())
			continue;
		std::stringstream inputStream(inputLine);
		std::string date, value;

		std::getline(inputStream, date, '|');
		int inputDate = BitcoinExchange::loadDate(date);
		if (inputDate == -1)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		
		std::getline(inputStream, value);
		float inputValue = BitcoinExchange::loadValue(value);
		if (inputValue == -1)
			continue;

		BitcoinExchange inputData(inputDate, inputValue);
		std::cout << date << " => " << inputData.getValue() << " = " << inputData.getExchangeRate() * inputData.getValue() << std::endl;
	}
	return 0;
}