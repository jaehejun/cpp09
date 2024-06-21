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
		std::vector<std::pair<int,int> > pVector;
		std::deque<std::pair<int,int> > pDeque;
		long inputSize;
		float vectorTime;
		float dequeTime;
		clock_t start;
		clock_t finish;
	
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

	public:
		PmergeMe(int argc, char** argv);
		~PmergeMe();

		//main argument error handling
		static int checkInputString(const std::string &input);
		// integer value overflow (argv[i])추가해야함

		//vector 
		long jacobsthalNumber(long number);
		std::vector<long> makeJacobsthalArray(long mainSize);
		//void binaryInsertion(std::vector<std::pair<int,int> > &sorted, int value, long rightEnd);
		std::vector<std::pair<int,int> > mergeInsertion(std::vector<std::pair<int,int> > mainChain);

		//display
		void displayUnsorted();
		void displaySorted();
		void displayVectorTime();
		void displayDequeTime();

		//time
		void startTime();
		void finishTime();
		void calculateTime();
};

#endif