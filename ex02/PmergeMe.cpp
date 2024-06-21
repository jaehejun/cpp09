#include "PmergeMe.hpp"

int PmergeMe::compairCount = 0;
//main argument error handling
PmergeMe::PmergeMe(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		pVector.push_back(std::make_pair(std::atoi(argv[i]), i));
		pDeque.push_back(std::make_pair(std::atoi(argv[i]), i));
	}
	inputSize = static_cast<long>(pVector.size());
}

PmergeMe::~PmergeMe()
{}

int PmergeMe::checkInputString(const std::string &inputString)
{
	for (size_t i = 0; i < inputString.size(); ++i)
	{
		if (inputString[i] < '0' || inputString[i] > '9')
			return -1;
	}
	return 0;
}

//vector sorting

//void PmergeMe::binaryInsertion(std::vector<std::pair<int,int> > &sorted, int value, long rightEnd)
//{
//	long left = 0;
//	long right = rightEnd;
//	while (left <= right)
//	{
//		long mid = (left + right) / 2;
//		//std::cout << "LEFT:" << left << std::endl;
//		//std::cout << "RIGHT:" << right << std::endl;
//		//std::cout << "MID:" << mid << std::endl;
//		compairCount++;
//		if (value < sorted[mid].first)
//			right = mid - 1;
//		else //(value > sorted[mid])
//			left = mid + 1;
//	}
//	sorted.insert(sorted.begin() + left, value);
//}


std::vector<std::pair<int,int> > PmergeMe::mergeInsertion(std::vector<std::pair<int,int> > mainChain)
{
	//step 1 : pairwise comparison
	size_t n = mainChain.size();
	std::cout << "MAIN SIZE: " << n << std::endl;
	std::vector<std::pair<int,int> > main;
	std::vector<std::pair<int,int> > pending;
	//std::vector<std::pair<int,int> > pairs;
	for (size_t index = 0; index < n / 2; ++index)
	{
		if (mainChain[index].first < mainChain[n/2 + index].first)
		{
			main.push_back(mainChain[n/2 + index]);
			pending.push_back(mainChain[index]);
			//pairs.push_back(std::make_pair(mainChain[n/2 + index], mainChain[index]));
		}
		else
		{
			main.push_back(mainChain[index]);
			pending.push_back(mainChain[n/2 + index]);
			//pairs.push_back(std::make_pair(mainChain[index], mainChain[n/2 + index]));
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
	
	//@@@@@@OG ver of matching pending with main!@@@@
	//for (int i = 0; i < main.size(); ++i)
	//{
	//	for (size_t j = 0; j < pairs.size(); ++j)
	//	{
	//		if (pairs[j].first == main[i])
	//			pending[i] = pairs[j].second;
	//	}
	//}

	for (size_t i = 0; i < main.size(); ++i)
	{
		pending[i] = pending[main[i].second];
	}

	//std::cout << "@@@@@@@@  PEND CHANGED!!!! @@@@@@@@@@@@@" << std::endl;
	//for (int i = 0; i < pending.size(); ++i)
	//	std::cout << pending[i] << std::endl;

	std::vector<std::pair<int,int> > sorted = main;
	std::vector<long> jacobArray = makeJacobsthalArray(pending.size());

	//std::cout << "@@@@@@@@  JACOB @@@@@@@@@" << std::endl;
	//for (int i = 0; i < jacobArray.size(); ++i)
	//	std::cout << jacobArray[i] << std::endl;
	// pending[0] < main[0] 항상 만족하므로 먼저 맨앞에 넣고 나머지 insert
	sorted.insert(sorted.begin(), pending[0]);

	for (size_t i = 1; i < jacobArray.size();) // i : 1부터 binary()
	{
		//std::cout << "BINARY!!!" << std::endl;
		//binary search insertion


		//binaryInsertion(sorted, pending[jacobArray[i]].first, jacobArray[i] + i - 1);
		
		
		
		++i;
	}

	//if (main.size() < pending.size())
	//{
	//	std::cout << "MAIN:" << main.size() << " PEND:" << pending.size() << std::endl;
	//	binaryInsertion(sorted, pending[pending.size()-1], sorted.size()-1);
	//}


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









//jacobsthal making
long PmergeMe::jacobsthalNumber(long number)
{
	if (number == 0)
		return 0;
	else if (number == 1)
		return 1;
	else
		return (jacobsthalNumber(number-1) +jacobsthalNumber(number-2) * 2);
}

std::vector<long> PmergeMe::makeJacobsthalArray(long mainSize)
{
	std::vector<long> jacobArray;
	
	int startJacobNumber = 2;
	long index = 0;
	while (index < mainSize)
	{
		long maxNumber = jacobsthalNumber(startJacobNumber); // 1, 3, 5, 11, 21, 43, 85, ...
		if (maxNumber > mainSize)
			maxNumber = mainSize;
		long putNumber = maxNumber - 1;
		while (index < maxNumber)
		{
			jacobArray.push_back(putNumber--);
			index++;
		}
		startJacobNumber++;
	}
	return jacobArray;
}





//display
void PmergeMe::displayUnsorted()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < pVector.size(); ++i)
		std::cout << pVector[i].first << " ";
	std::cout << std::endl;
}

void PmergeMe::displaySorted()
{
	std::cout << "After:  ";
	for (size_t i = 0; i < pVector.size(); ++i)
		std::cout << pVector[i].first << " ";
	std::cout << std::endl;
}

void PmergeMe::displayVectorTime()
{
	std::cout << "Time to process a range of "<< inputSize << " elements with std::vector : ";
	std::cout << vectorTime << " us" << std::endl;
}

void PmergeMe::displayDequeTime()
{
	std::cout << "Time to process a range of "<< inputSize << " elements with std::deque : ";
	std::cout << dequeTime << " us" << std::endl;
}

void PmergeMe::startTime()
{
	start = clock();
}

void PmergeMe::finishTime()
{
	finish = clock();
}

void PmergeMe::calculateTime()
{
	vectorTime = finish - start;
}

//return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;