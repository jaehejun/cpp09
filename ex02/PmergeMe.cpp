#include "PmergeMe.hpp"

int PmergeMe::compairCount = 0;

// main execute func
void PmergeMe::sort()
{
	setStartTime();
	//std::cout << "@@@@@@@@@@@  Set VEC Time @@@@@@@@@@@@" << std::endl;
	setUnsorted(unsortedVector);
	//std::cout << "@@@@@@@@@@@  Set UNSORTED VEC @@@@@@@@@@@@" << std::endl;
	sortedVector = mergeInsertion(unsortedVector);
	//std::cout << "@@@@@@@@@@@  SORTING VEC @@@@@@@@@@@@" << std::endl;
	calculateVectorTime();
	//std::cout << "@@@@@@@@@@@  CAL TIME FOR  VEC @@@@@@@@@@@@" << std::endl;

	setStartTime();
	//std::cout << "@@@@@@@@@@@  Set DEQ Time @@@@@@@@@@@@" << std::endl;
	setUnsorted(unsortedDeque);
	//std::cout << "@@@@@@@@@@@  Set UNSORTED DEQ @@@@@@@@@@@@" << std::endl;
	sortedDeque = mergeInsertion(unsortedDeque);
	//std::cout << "@@@@@@@@@@@  SORTING DEQ @@@@@@@@@@@@" << std::endl;
	calculateDequeTime();
	//std::cout << "@@@@@@@@@@@  CAL TIME FOR  DEQ @@@@@@@@@@@@" << std::endl;
}

//verifying std::sort with my fordjohnson
void PmergeMe::verify()
{
	std::sort(unsortedVector.begin(), unsortedVector.end());
	std::sort(unsortedDeque.begin(), unsortedDeque.end());
	for (size_t i = 0; i < unsortedVector.size(); ++i)
	{
		if (unsortedVector[i] == sortedVector[i])
			break;
	}
	for (size_t i = 0; i < unsortedDeque.size(); ++i)
	{
		if (unsortedDeque[i] == sortedDeque[i])
		{

		}
			break;
	}
		std::cout << "Error" << std::endl;
}

void PmergeMe::printResult()
{
	displayUnsorted();
	displaySorted();
	displayVectorTime();
	displayDequeTime();
}

void PmergeMe::setUnsorted(std::vector<int> &unsortedVector)
{
	for (int index = 1; index < argc; ++index)
	{
		unsortedVector.push_back(std::atoi(argv[index]));
	}
}

void PmergeMe::setUnsorted(std::deque<int> &unsortedVector)
{
	for (int index = 1; index < argc; ++index)
	{
		unsortedVector.push_back(std::atoi(argv[index]));
	}
}

// class construction
PmergeMe::PmergeMe(int argc, char** argv) : argc(argc), argv(argv), unsortedVector(), sortedVector(), unsortedDeque(), sortedDeque(), start(0), vectorTime(0), dequeTime(0)
{
	//for (int i = 1; i < argc; ++i)
	//{
	//	unsortedVector.push_back(std::atoi(argv[i]));
	//	pDeque.push_back(std::atoi(argv[i]));
	//}
}

PmergeMe::~PmergeMe()
{}

//main argument error handling
bool PmergeMe::isValidInputString(const std::string &inputString)
{
	for (size_t i = 0; i < inputString.size(); ++i)
	{
		if (inputString[i] < '0' || inputString[i] > '9')
			return false;
	}
	return true;
}



//compair vector-deque
bool PmergeMe::isContainersSame()
{
	size_t vectorSize = unsortedVector.size();
	size_t dequeSize = unsortedDeque.size();
	if (vectorSize != dequeSize)
		return false;
	for (size_t i = 0; i < vectorSize; ++i)
	{
		if (unsortedVector[i] != unsortedDeque[i])
			return false;
	}
	return true;
}

//jacobsthal Number
long PmergeMe::jacobsthalNumber(long number)
{
	if (number == 0)
		return 0;
	else if (number == 1)
		return 1;
	else
		return (jacobsthalNumber(number-1) +jacobsthalNumber(number-2) * 2);
}




//@@@@@@@@@@@@@@@@@@@  vector sorting @@@@@@@@@@@@@@@@@@@@@@@@@@@@@


std::vector<int> PmergeMe::mergeInsertion(std::vector<int> mainChain)
{
	//step 1 : pair comparison
	size_t n = mainChain.size();
	std::vector<int> main;
	std::vector<int> pending;
	std::vector<std::pair<int,int> > pairs;
	for (size_t i = 0; i < n / 2; ++i)
	{
		if (mainChain[i] < mainChain[n/2 + i])
		{
			main.push_back(mainChain[n/2 + i]);
			pending.push_back(mainChain[i]);
			pairs.push_back(std::make_pair(mainChain[n/2 + i], mainChain[i]));
		}
		else
		{
			main.push_back(mainChain[i]);
			pending.push_back(mainChain[n/2 + i]);
			pairs.push_back(std::make_pair(mainChain[i], mainChain[n/2 + i]));
		}
	}
	if (n % 2 == 1)
		pending.push_back(mainChain[n-1]);


	//step 2 : Recursion and Renaming
	if (main.size() > 1)
		main = mergeInsertion(main);
	
	//step 3 : Insertion
	for (size_t i = 0; i < main.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == main[i])
				pending[i] = pairs[j].second;
		}
	}
	std::vector<int> sorted = main;
	std::vector<long> jacobArray = makeJacobsthalVector(pending.size());

	sorted.insert(sorted.begin(), pending[0]);
	for (size_t i = 1; i < jacobArray.size();)
	{
		binaryInsertion(sorted, pending[jacobArray[i]], jacobArray[i] + i - 1);
		++i;
	}
	return sorted;
	//vec = sorted;
}

std::vector<long> PmergeMe::makeJacobsthalVector(long mainSize)
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

void PmergeMe::binaryInsertion(std::vector<int> &sorted, int value, long rightEnd)
{
	long left = 0;
	long right = rightEnd;
	long mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		compairCount++;
		if (value < sorted[mid])
			right = mid - 1;
		else //(value > sorted[mid])
			left = mid + 1;
	}
	sorted.insert((sorted.begin() + left), value);
}


//@@@@@@@@@@@@@@@@@@@  Deque sorting @@@@@@@@@@@@@@@@@@@@@@@@@@@@@

std::deque<int> PmergeMe::mergeInsertion(std::deque<int> mainChain)
{
	//step 1 : pair comparison
	size_t n = mainChain.size();
	std::deque<int> main;
	std::deque<int> pending;
	std::deque<std::pair<int,int> > pairs;
	for (size_t i = 0; i < n / 2; ++i)
	{
		if (mainChain[i] < mainChain[n/2 + i])
		{
			main.push_back(mainChain[n/2 + i]);
			pending.push_back(mainChain[i]);
			pairs.push_back(std::make_pair(mainChain[n/2 + i], mainChain[i]));
		}
		else
		{
			main.push_back(mainChain[i]);
			pending.push_back(mainChain[n/2 + i]);
			pairs.push_back(std::make_pair(mainChain[i], mainChain[n/2 + i]));
		}
	}
	if (n % 2 == 1)
		pending.push_back(mainChain[n-1]);


	//step 2 : Recursion and Renaming
	if (main.size() > 1)
		main = mergeInsertion(main);
	
	//std::cout << "@@@@@@@ END MERGE @@@@@" << std::endl;

	//step 3 : Insertion
	for (size_t i = 0; i < main.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == main[i])
				pending[i] = pairs[j].second;
		}
	}
	//@@@@@@OG ver of matching pending with main!@@@@
	std::deque<int> sorted = main;
	std::deque<long> jacobArray = makeJacobsthalDeque(pending.size());

	// pending[0] < main[0] 항상 만족하므로 먼저 맨앞에 넣고 나머지 insert
	sorted.insert(sorted.begin(), pending[0]);

	for (size_t i = 1; i < jacobArray.size();) // i : 1부터 binary()
	{
		//std::cout << "BINARY!!!" << std::endl;
		//binary search insertion

		binaryInsertion(sorted, pending[jacobArray[i]], jacobArray[i] + i - 1);
		++i;
	}
	return sorted;
}

std::deque<long> PmergeMe::makeJacobsthalDeque(long mainSize)
{
	std::deque<long> jacobArray;
	
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


void PmergeMe::binaryInsertion(std::deque<int> &sorted, int value, long rightEnd)
{
	long left = 0;
	long right = rightEnd;
	long mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		compairCount++;
		if (value < sorted[mid])
			right = mid - 1;
		else //(value > sorted[mid])
			left = mid + 1;
	}
	sorted.insert((sorted.begin() + left), value);
}



//display
void PmergeMe::displayUnsorted()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < unsortedVector.size(); ++i)
		std::cout << unsortedVector[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::displaySorted()
{
	std::cout << "After:  ";
	for (size_t i = 0; i < sortedVector.size(); ++i)
		std::cout << sortedVector[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::displayVectorTime()
{
	std::cout << "Time to process a range of "<< unsortedVector.size() << " elements with std::vector : ";
	std::cout << static_cast<double>(vectorTime) / (CLOCKS_PER_SEC * 1000000.0) << " us" << std::endl;
}

void PmergeMe::displayDequeTime()
{
	std::cout << "Time to process a range of "<< unsortedDeque.size() << " elements with std::deque : ";
	std::cout << static_cast<double>(dequeTime) / (CLOCKS_PER_SEC * 1000000.0) << " us" << std::endl;
}

//time
void PmergeMe::setStartTime()
{
	start = clock();
}

void PmergeMe::calculateVectorTime()
{
	vectorTime = clock() - start;
}

void PmergeMe::calculateDequeTime()
{
	dequeTime = clock() - start;
}

//return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;