#include <iostream>
#include <vector>
#include <cstdlib> //rand
#include <ctime> //srand

static int compairCount = 0;
//int binaryInsertion(std::vector<int> sorted, size_t range, int value)
//{
//	int left = 0;
//	int right = range;
//	while (left < right)
//	{
//		int mid = (left + right) / 2;
//		//std::cout << "LEFT:" << left << std::endl;
//		//std::cout << "RIGHT:" << right << std::endl;
//		//std::cout << "MID:" << mid << std::endl;
//		if (value < sorted[mid])
//			right = mid;
//		else //(value > sorted[mid])
//			left = mid + 1;
//	}
//	//sorted.insert(sorted.begin() + left, value);
//	//std::vector<int> result = sorted;
//	//result.insert(result.begin() + left, value);

//	return left;
//}

int jacobsthalNumber(int number)
{
	if (number == 0)
		return 0;
	else if (number == 1)
		return 1;
	else
		return (jacobsthalNumber(number-1) +jacobsthalNumber(number-2) * 2);
}

std::vector<int> makeJacobsthalArray(size_t mainNumber)
{
	std::vector<int> jacobArray;
	
	int startJacobNumber = 2;
	int index = 0;
	while (index < mainNumber)
	{
		int maxNumber = jacobsthalNumber(startJacobNumber); // 1, 3, 5, 11, 21, 43, 85, ...
		if (maxNumber > mainNumber)
			maxNumber = mainNumber;
		int putNumber = maxNumber - 1;
		while (index < maxNumber)
		{
			jacobArray.push_back(putNumber--);
			index++;
		}
		startJacobNumber++;
	}
	return jacobArray;
}


void binaryInsertion(std::vector<int> &sorted, int value, int rightEnd)
{
	int left = 0;
	int right = rightEnd;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		//std::cout << "LEFT:" << left << std::endl;
		//std::cout << "RIGHT:" << right << std::endl;
		//std::cout << "MID:" << mid << std::endl;
		compairCount++;
		if (value < sorted[mid])
			right = mid - 1;
		else //(value > sorted[mid])
			left = mid + 1;
	}
	sorted.insert(sorted.begin() + left, value);
}

std::vector<int> mergeInsertion(std::vector<int> mainChain)
{
	//step 1 : pairwise comparison
	int n = mainChain.size();
	std::cout << "MAIN SIZE: " << n << std::endl;
	std::vector<int> main;
	std::vector<int> pending;
	std::vector<std::pair<int,int> > pairs;
	for (size_t index = 0; index < n / 2; ++index)
	{
		if (mainChain[index] < mainChain[n/2 + index])
		{
			main.push_back(mainChain[n/2 + index]);
			pending.push_back(mainChain[index]);
			pairs.push_back(std::make_pair(mainChain[n/2 + index], mainChain[index]));
		}
		else
		{
			main.push_back(mainChain[index]);
			pending.push_back(mainChain[n/2 + index]);
			pairs.push_back(std::make_pair(mainChain[index], mainChain[n/2 + index]));
		}
	}
	if (n % 2 == 1)
		pending.push_back(mainChain[n-1]);

	//for (int i = 0; i < main.size(); ++i)
	//	std::cout << "MAIN:" << main[i] << std::endl;
	//for (int i = 0; i < pending.size(); ++i)
	//	std::cout << "PEND:" << pending[i] << std::endl;

	//step 2 : Recursion and Renaming
	if (main.size() > 1)
		main = mergeInsertion(main);

	//step 3 : Insertion

	//std::cout << "@@@@@@@@MAIN BEFORE SORTED@@@@@@@@@@@@@" << std::endl;
	//for (int i = 0; i < main.size(); ++i)
	//	std::cout << main[i] << std::endl;
	//std::cout << "@@@@@@@@PEND BEFORE SORTED@@@@@@@@@@@@@" << std::endl;
	//for (int i = 0; i < pending.size(); ++i)
	//	std::cout << pending[i] << std::endl;
	
	for (int i = 0; i < main.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == main[i])
				pending[i] = pairs[j].second;
		}
	}

	//std::cout << "@@@@@@@@  PEND CHANGED!!!! @@@@@@@@@@@@@" << std::endl;
	//for (int i = 0; i < pending.size(); ++i)
	//	std::cout << pending[i] << std::endl;

	std::vector<int> sorted = main;
	std::vector<int> jacobArray = makeJacobsthalArray(main.size());

	//std::cout << "@@@@@@@@  JACOB @@@@@@@@@" << std::endl;
	//for (int i = 0; i < jacobArray.size(); ++i)
	//	std::cout << jacobArray[i] << std::endl;
	// pending[0] < main[0] 항상 만족하므로 먼저 맨앞에 넣고 나머지 insert
	sorted.insert(sorted.begin(), pending[0]);

	for (int i = 1; i < jacobArray.size();) // i : 1부터 binary()
	{
		//std::cout << "BINARY!!!" << std::endl;
		//binary search insertion
		binaryInsertion(sorted, pending[jacobArray[i]], jacobArray[i] + i - 1);
		++i;
	}

	if (main.size() < pending.size())
	{
		std::cout << "MAIN:" << main.size() << " PEND:" << pending.size() << std::endl;
		binaryInsertion(sorted, pending[pending.size()-1], sorted.size()-1);
	}


	//std::cout << "@@@@@@@@SORTED@@@@@@@@@@@@@" << std::endl;
	//for (int i = 0; i < sorted.size(); ++i)
	//	std::cout << sorted[i] << std::endl;

	//std::cout << "@@@@@@@@MAIN after SORTED@@@@@@@@@@@@@" << std::endl;
	//for (int i = 0; i < main.size(); ++i)
	//	std::cout << main[i] << std::endl;
	//std::cout << "@@@@@@@@PEND after SORTED@@@@@@@@@@@@@" << std::endl;
	//for (int i = 0; i < pending.size(); ++i)
	//	std::cout << pending[i] << std::endl;

	return sorted;
}


int main()
{


	std::vector<int> mainChain;
	//mainChain.push_back(1);
	//mainChain.push_back(0);
	//mainChain.push_back(12);
	//mainChain.push_back(2);
	//mainChain.push_back(5);
	//mainChain.push_back(5);
	//mainChain.push_back(6);
	//mainChain.push_back(11);
	//mainChain.push_back(9);
	//mainChain.push_back(8);
	//mainChain.push_back(3);
	//mainChain.push_back(10);
	//mainChain.push_back(7);
	//mainChain.push_back(4);

	std::srand(std::time(NULL));
	for (int i = 0; i < 17; ++i)
	{
		int random = rand() % INT_MAX;
		mainChain.push_back(random + 1);
	}

	std::cout << "@@@@@ BEFORE @@@@@" << std::endl;
	for (int i = 0; i < mainChain.size(); ++i)
		std::cout << mainChain[i] << " ";
	std::cout << std::endl;

	std::vector<int> sorted = mergeInsertion(mainChain);

	std::cout << "@@@@@ RESULT @@@@@" << std::endl;
	for (int i = 0; i < sorted.size(); ++i)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;

	std::cout << "COMPAIR COUNT: " << compairCount << std::endl;
}