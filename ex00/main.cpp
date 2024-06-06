#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
		std::cout << "Error: could not open file." << std::endl;
	
	BitcoinExchange bitcoinExchange;

	bitcoinExchange.getData(data.csv);

	while (std::getline(argv[1]) != NULL)
	{
		std::string inputLine;
		bitcoinExchange.getInput(inputLine);

		bitcoinExchange.checkInput();
		bitcoinExchange.calculate();
		bitcoinExchange.print()
	}
	


	return 0;
}

//date,exchange_rate
//2009-01-02,0
//2009-01-05,0
//2009-01-08,0
//2009-01-11,0
//2009-01-14,0
//2009-01-17,0
//2009-01-20,0
//2009-01-23,0
//2009-01-26,0

data.csv -> map ㅇㅔ ㅈㅓ자ㅇ

input.txt -> 한줄씩 읽으면서 파일 끝날때까지 실행
getline() -> std::string date, int or float balance
input.txt의 잔고가 int일때 -> int val에 저장, float-> float val에 저장

date validity 확인 -> 에러출력
balance validity 확인 -> 에러출력

둘다 valid 하다면
[first] input date >= marketPrice.date 찾아서 marketprice.price
balance * price

규칙에 맞게 출력

BitcoinExchange