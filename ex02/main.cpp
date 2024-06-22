#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe myFord(argc, argv);
	myFord.sort();
	myFord.verify();
	myFord.printResult();
	
	return 0;
}

//int main(int argc, char** argv)
//{
//	if (argc < 3)
//		return std::cout << "Error" << std::endl, -1;

//	std::string inputString;
//	for (int i = 1; i < argc; ++i)
//	{
//		inputString.append(argv[i]);
//	}
//	if (PmergeMe::isValidInputString(inputString))
//		return std::cout << "Error" << std::endl, -1;


//	//make  first vector;
//	//make  first deque;
//	PmergeMe myFord(argc, argv);


////@@@@@@@@@@@@@@@@@@@@@@@@@@  VECTOR @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//	myFord.setStartTime();
//	std::vector<int> result = myFord.mergeInsertion(myFord.getVector());
//	myFord.calculateVectorTime();

////@@@@@@@@@@@@@@@@@@@@@@@@@@  DEQUE @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//	myFord.setStartTime();
//	std::deque<int> dequeResult = myFord.mergeInsertion(myFord.getDeque());
//	myFord.calculateDequeTime();


//	//compair sorted vector with sorted deque;
//	//if same, print sorted vector or deque;

//	//before numberSequence print
//	myFord.displayUnsorted();
//	//after numberSequence print
//	//myFord.displaySorted();
//	std::cout << "After:  ";
//	for (size_t i = 0; i < result.size(); ++i)
//		std::cout << result[i] << " ";
//	std::cout << std::endl;


//	//vector time print
//	myFord.displayVectorTime();
//	//deque time print
//	myFord.displayDequeTime();

//	return 0;
//}

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