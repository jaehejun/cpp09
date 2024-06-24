#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char** argv) 
: argc(argc), argv(argv), unsortedVector(), sortedVector(), unsortedDeque(), sortedDeque(), start(0), vectorTime(0), dequeTime(0)
{}

PmergeMe::~PmergeMe()
{}

int PmergeMe::compairCount = 0;

// main execute func

////check input arguments
void PmergeMe::checkInputString()
{
	if (argc < 2)
		throw std::invalid_argument("Error");
	
	std::string inputString;
	std::string element;
	for (int i = 1; i < argc; ++i)
	{
		inputString = argv[i];
		std::istringstream inputNumbers(inputString);
		while (inputNumbers >> element)
		{
			for (size_t i = 0; i < element.size(); ++i)
			{
				if ((element[i] < '0' || element[i] > '9') && element[i] != ' ')
					throw std::invalid_argument("Error");
			}
			long number = std::atol(element.c_str());
			if (number > INT_MAX)
				throw std::invalid_argument("Error");
		}
	}
}

////actual execute all
void PmergeMe::executeSorting()
{
	// for std::vector
	setStartTime();
	setUnsorted(unsortedVector);
	sortedVector = mergeInsertion(unsortedVector);
	calculateVectorTime();

	// for std::deque
	setStartTime();
	setUnsorted(unsortedDeque);
	sortedDeque = mergeInsertion(unsortedDeque);
	calculateDequeTime();
}

////verifying result wiht std::sort()
void PmergeMe::verify()
{
	std::vector<int> stdVector(unsortedVector);
	std::deque<int> stdDeque(unsortedDeque);
	std::sort(stdVector.begin(), stdVector.end());
	std::sort(stdDeque.begin(), stdDeque.end());
	for (size_t i = 0; i < stdVector.size(); ++i)
	{
		if (stdVector[i] != sortedVector[i])
			throw std::logic_error("Error");
	}
	for (size_t i = 0; i < stdDeque.size(); ++i)
	{
		if (stdDeque[i] != sortedDeque[i])
	  		throw std::logic_error("Error");
	}
}

////print each lines
void PmergeMe::printResult()
{
	displayUnsorted();
	displaySorted();
	displayVectorTime();
	displayDequeTime();
}

// common methods

////time
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

////jacobsthal
long PmergeMe::jacobsthalNumber(long number)
{
	if (number == 0)
		return 0;
	else if (number == 1)
		return 1;
	else
		return (jacobsthalNumber(number-1) +jacobsthalNumber(number-2) * 2);
}

////display
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
	std::cout << static_cast<double>(vectorTime) / CLOCKS_PER_SEC * 1000000.0 << " us" << std::endl;
}

void PmergeMe::displayDequeTime()
{
	std::cout << "Time to process a range of "<< unsortedDeque.size() << " elements with std::deque  : ";
	std::cout << static_cast<double>(dequeTime) / CLOCKS_PER_SEC * 1000000.0 << " us" << std::endl;
}

// methods for vector
void PmergeMe::setUnsorted(std::vector<int> &unsortedVector)
{
	std::string inputString;
	std::string element;
	for (int i = 1; i < argc; ++i)
	{
		inputString = argv[i];
		std::istringstream inputNumbers(inputString);
		while (inputNumbers >> element)
			unsortedVector.push_back(std::atoi(element.c_str()));
	}
}

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
		for (size_t j = 0; j < main.size(); ++j)
		{
			if (main[i] == pairs[j].first)
			{
				pending[i] = pairs[j].second;
				pairs[j].first = -1;
				break;
			}
		}
	}

	std::vector<int> sorted = main;
	std::vector<int> jacobArray = makeJacobsthalVector(pending.size());

	sorted.insert(sorted.begin(), pending[0]);
	for (size_t i = 1; i < jacobArray.size();)
	{
		binaryInsertion(sorted, pending[jacobArray[i]], jacobArray[i] + i - 1);
		++i;
	}
	return sorted;
}

std::vector<int> PmergeMe::makeJacobsthalVector(int mainSize)
{
	std::vector<int> jacobArray;
	
	int startJacobNumber = 2;
	int index = 0;
	while (index < mainSize)
	{
		int maxNumber = jacobsthalNumber(startJacobNumber); // 1, 3, 5, 11, 21, 43, 85, ...
		if (maxNumber > mainSize)
			maxNumber = mainSize;
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

void PmergeMe::binaryInsertion(std::vector<int> &sorted, int value, int rightEnd)
{
	int left = 0;
	int right = rightEnd;
	int mid;
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

// methods for deque
void PmergeMe::setUnsorted(std::deque<int> &unsortedDeque)
{
	std::string inputString;
	std::string element;
	for (int i = 1; i < argc; ++i)
	{
		inputString = argv[i];
		std::istringstream inputNumbers(inputString);
		while (inputNumbers >> element)
			unsortedDeque.push_back(std::atoi(element.c_str()));
	}
}

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
	
	//step 3 : Insertion
	for (size_t i = 0; i < main.size(); ++i)
	{
		for (size_t j = 0; j < main.size(); ++j)
		{
			if (main[i] == pairs[j].first)
			{
				pending[i] = pairs[j].second;
				pairs[j].first = -1;
				break;
			}
		}
	}
	std::deque<int> sorted = main;
	std::deque<int> jacobArray = makeJacobsthalDeque(pending.size());

	sorted.insert(sorted.begin(), pending[0]);

	for (size_t i = 1; i < jacobArray.size();) // i : 1부터 binary()
	{
		binaryInsertion(sorted, pending[jacobArray[i]], jacobArray[i] + i - 1);
		++i;
	}
	return sorted;
}

std::deque<int> PmergeMe::makeJacobsthalDeque(int mainSize)
{
	std::deque<int> jacobArray;
	
	int startJacobNumber = 2;
	int index = 0;
	while (index < mainSize)
	{
		int maxNumber = jacobsthalNumber(startJacobNumber); // 1, 3, 5, 11, 21, 43, 85, ...
		if (maxNumber > mainSize)
			maxNumber = mainSize;
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

void PmergeMe::binaryInsertion(std::deque<int> &sorted, int value, int rightEnd)
{
	int left = 0;
	int right = rightEnd;
	int mid;
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