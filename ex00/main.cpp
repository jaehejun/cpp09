#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

//int checkDate(std::string &inputLine)
//{

//	return 0;
//}

//int checkValue(std::string &inputLine)
//{

//	return 0;
//}

int main(int argc, char** argv)
{
	if (argc != 2)
		std::cout << "Error: could not open file." << std::endl;
	
	//BitcoinExchange bitcoinExchange;

	std::ifstream data("data.csv");
	if (data.is_open())
		std::cout << "OPENABLE!" << std::endl;
	
	BitcoinExchange exchange;
	exchange.getData(data);
	//exchange.printMap();

	std::ifstream input(argv[1]);
	if (input.is_open())
		;

	std::string line;
	std::getline(input, line);
	while (std::getline(input, line))
	{
		std::string date = line.substr(0,10);
		float number;
		std::stringstream value(line.substr(13));
		value >> number;

		std::cout << date << std::endl;
		std::cout << number << std::endl;

		exchange.getExchangeRate(date);
		
		//std::cout << date << " => " << number << " = " << exchange.getExchangeRate(date) * number << std::endl;
	}
	



	//bitcoinExchange.getData(data.csv);

	//while (std::getline(argv[1]) != NULL)
	//{
	//	std::string inputLine;
	//	bitcoinExchange.getInput(inputLine);

	//	bitcoinExchange.checkInput();
	//	bitcoinExchange.calculate();
	//	bitcoinExchange.print()
	//}
	


	return 0;
}

//date,exchange_rate
//2009-01-02,0
//2009-01-05,0

//stringstream
//map.upperbound()

//getline() -> 맨윗줄은 건너띄고 끝까지 읽어야함
//data.csv -> map 에 key:date, val:price 로 저장
//"," 을 기준으로 date, price 나눈다

//input.txt -> 한줄씩 읽으면서 파일 끝날때까지 실행
//getline() -> std::string date, int or float balance
//" | " 을 기준으로 date, val 나눈다
//input의 date가 marketPrice에 존재하는가? true -> 해당 date에 대응하는 val 가져온다
//input의 date가 marketPrice에 존재하는가? false -> marketPrice의 date에서 가장 가까운 이전 date에 대응하는 val 가져온다 -> map.upperbound()

//input.txt의 잔고가 int일때 -> int val에 저장, float-> float val에 저장

//date validity 확인 -> 에러출력
//balance validity 확인 -> 에러출력

//둘다 valid 하다면
//[first] input date >= marketPrice.date 찾아서 marketprice.price
//balance * price

//규칙에 맞게 출력

//BitcoinExchange