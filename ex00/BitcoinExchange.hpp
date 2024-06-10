#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, float> marketPrice;

		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
	
	public:
		BitcoinExchange();
		~BitcoinExchange();

		void getData(std::ifstream &data);
		float getExchangeRate(std::string &inputDate);

		void printMap();

		

		// make marketPrice

		//void getData(data.csv);
		/*
		parse data.csv
		std::getline()
		{
			substring(',')
			marketPrice.insert date-value
		}
		
*/

		// make balance

		//void getInput(std::string &inputLine);
		/*
		parse input
		std::getline()
		{
			substring('|')
			balance.insert date-value
		}


		*/


		// print result

		//void printResult()
		
		/*

		if marketprice.value == 0
		{

		}
		if balance.date == invalid
		{
			"Error: bad input => " << balance.date 
		}
		if balance.value == invalid
		{
			if (balance.value < 0)
			"Error: not a positive number"
			if (balance.value == 0 )
			"Error: too small a number"
			if (balance.value >= 1000)
			"Error: too large a number"

			else
			"Error: not a number"
		}
		print
		balace.key << " => " << balance.value << " = " << nearestMarketPrice.value * balance.value
		*/


};

#endif