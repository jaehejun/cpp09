#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, int> marketPrice;
		//std::map<std::string, int> balance;
		std::string date;
		int balance;
		float balance;
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		// make marketPrice
		void getData(data.csv);
		/*
		parse data.csv
		std::getline()
		{
			substring(',')
			marketPrice.insert date-value
		}
		
*/

		// make balance
		void getInput(std::string &inputLine);
		/*
		parse input
		std::getline()
		{
			substring('|')
			balance.insert date-value
		}


		*/


		// print result
		void printResult()
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