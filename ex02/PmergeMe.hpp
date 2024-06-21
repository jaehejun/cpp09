#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

//typedef struct
//{
//	int value;
//	long index;
//}	element;

class PmergeMe
{
	private:
		static int compairCount;
		
		std::vector<int> unsortedVector;
		std::vector<int> sortedVector;

		std::deque<int> unsortedDeque;
		std::deque<int> sortedDeque;

		long inputSize;

		clock_t vectorTime;
		clock_t dequeTime;
		clock_t start;
	
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

	public:
		PmergeMe(int argc, char** argv);
		~PmergeMe();

		//main argument error handling
		static int checkInputString(const std::string &input);
		// integer value overflow (argv[i])추가해야함

		//jacobsthalNumber
		long jacobsthalNumber(long number);

		//vector 
		std::vector<int> getVector();
		std::vector<int> mergeInsertion(std::vector<int> mainChain);
		std::vector<long> makeJacobsthalVector(long mainSize);
		void binaryInsertion(std::vector<int> &sorted, int value, long rightEnd);
		
		//deque 
		std::deque<int> getDeque();
		std::deque<int> mergeInsertion(std::deque<int> mainChain);
		std::deque<long> makeJacobsthalDeque(long mainSize);
		void binaryInsertion(std::deque<int> &sorted, int value, long rightEnd);
		
		
		//display
		void displayUnsorted();
		void displaySorted();
		void displayVectorTime();
		void displayDequeTime();

		//time
		void setStartTime();
		void calculateVectorTime();
		void calculateDequeTime();
};

#endif