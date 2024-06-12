#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

class BitcoinExchange
{
	private:
		static std::map<int, float> marketPrice;
		int inputDate;
		float inputValue;

		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
	
	public:
		BitcoinExchange(int &date, float &value);
		~BitcoinExchange();
		static void loadData(std::ifstream &data);
		static int checkDate(std::string &date);
		static float checkValue(std::string &value);

		int getDate();
		float getValue();

		//static float getExchangeRate();
		float getExchangeRate();
};

#endif