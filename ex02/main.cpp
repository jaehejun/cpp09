#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 3)
		return std::cout << "Error" << std::endl, -1;

	//std::vector<int> stringInput;

	//for (long i = 1; i < argc; ++i)
	//{
	//	//std::vector<std::string> stringInput;
	//	stringInput.push_back(std::atoi(argv[i]));
	//}

	//for (int i = 0; i < stringInput.size(); ++i)
	//	std::cout << stringInput[i] << std::endl;

	std::string inputString;
	for (int i = 1; i < argc; ++i)
	{
		inputString.append(argv[i]);
	}
	if (PmergeMe::checkInputString(inputString))
		return std::cout << "Error" << std::endl, -1;



	//PmergeMe pMergeMe();

	//make  first vector;
	//make  first deque;
	PmergeMe myFord(argc, argv);

	//start time for vector;
	myFord.startTime();
	// mergeInsertion(vector);
	//check time for vector;  // store vector time
	myFord.finishTime();
	myFord.calculateTime();

	//start time for deque;
	//mergeInsertion(deque);
	//check time for deque; // store deque time

	//compair sorted vector with sorted deque;
	//if same, print sorted vector or deque;

	//before numberSequence print
	myFord.displayUnsorted();
	//after numberSequence print
	myFord.displaySorted();

	//vector time print
	myFord.displayVectorTime();
	//deque time print
	myFord.displayDequeTime();



	return 0;
}

//$> ./PmergeMe 3 5 9 7 4
//Before: 3 5 9 7 4
//After: 3 4 5 7 9
//Time to process a range of 5 elements with std::[..] : 0.00031 us
//Time to process a range of 5 elements with std::[..] : 0.00014 us
//$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
//Before: 141 79 526 321 [...]
//After: 79 141 321 526 [...]
//Time to process a range of 3000 elements with std::[..] : 62.14389 us
//Time to process a range of 3000 elements with std::[..] : 69.27212 us
//$> ./PmergeMe "-1" "2"
//Error
//$> # For OSX USER:
//$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
//[...]
//$>