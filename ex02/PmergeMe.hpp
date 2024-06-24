#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
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

		int argc;
		char **argv;
		
		std::vector<int> unsortedVector;
		std::vector<int> sortedVector;

		std::deque<int> unsortedDeque;
		std::deque<int> sortedDeque;

		clock_t start;
		clock_t vectorTime;
		clock_t dequeTime;
	
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

	//common methods

		//time
		void setStartTime();
		void calculateVectorTime();
		void calculateDequeTime();
		
		//jacobsthal
		long jacobsthalNumber(long number);
		
		//display
		void displayUnsorted();
		void displaySorted();
		void displayVectorTime();
		void displayDequeTime();


	//vector methods
		void setUnsorted(std::vector<int> &unsortedVector);
		std::vector<int> mergeInsertion(std::vector<int> mainChain);
		std::vector<int> makeJacobsthalVector(int mainSize);
		void binaryInsertion(std::vector<int> &sorted, int value, int rightEnd);
		
	//deque methods
		void setUnsorted(std::deque<int> &unsortedDeque);
		std::deque<int> mergeInsertion(std::deque<int> mainChain);
		std::deque<int> makeJacobsthalDeque(int mainSize);
		void binaryInsertion(std::deque<int> &sorted, int value, int rightEnd);

	public:
		PmergeMe(int argc, char** argv);
		~PmergeMe();

	// main methods
		void checkInputString();
		void executeSorting();
		void verify();
		void printResult();


};

#endif