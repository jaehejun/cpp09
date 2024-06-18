//merge-insertion sort performs the following steps, on an input X of n elements.

//1. Group the elements of X into [n/2] pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
//2. Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.
//3. Recursively sort the [n/2] larger elements from each pair, creating a sorted sequence S of [n/2] of the input elements, in ascending order.
//4. Insert at the start of S the element that was paired with the first and smallest element of S.
//5. Insert the remaining [n/2] - 1 elements of X \ S into S, one at a time, with a specially chosen insertion ordering described below. 
//Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.

//The algorithm is designed to take advantage of the fact that the binary searches used to insert elements into S are most efficient (from the point of view of worst case analysis) when the length of the subsequence that is searched is one less than a power of two. 
//This is because, for those lengths, all outcomes of the search use the same number of comparisons as each above (before inserting the remaining elements), and let Xi denote the ith element of this sorted sequence.
//Thus, S = (x1, x2, x3, ...),
//where each element xi with i >= 3 is paired with an element yi < xi that has not yet been inserted.(there are no elements y1 or y2 because x1 and x2 were paired with each other.)
//If n is odd, the remaining unpaired element should also be numbered as yi with i larger than the indexes of the paired elements. Then, the final step of the outline above can be expanded into the following steps.
// - Partitioning the uninserted elements yi into groups with contiguous indexes. There are two elements y3 and y4 in the first group, and the sums of sizes of every two adjacent groups form a sequence of powers of two.
// Thus, the sizes of groups are : 2, 2, 6, 10, 22, 42, ...
// - Order the uninserted elements by their groups(smaller indexes to larger indexes), but within each group order them from larger indexes to smaller indexes. Thus, the ordering becomes
// y4, y3, y6, y5, y12, y11, y10, y9, y8, y7, y22, y21 ...
// - Use this ordering to insert the elements yi into S. For each element yi, use a binary search from the start of S up to but not including xi to determine where to insert yi.


	//std::cout << "SIZE:" << pairs.size() << std::endl;
	//for (size_t i = 0; i < pairs.size(); ++i)
	//	std::cout << "PAIRS[" << i << "] : " << pairs[i].first << "-" << pairs[i].second << std::endl;

	//for (std::vector<std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	//{
	//	std::cout << "First:" << it->first << "Second:" << it->second << std::endl;
	//}

#include <iostream>
#include <vector>

int main()
{

	std::vector<int> input;
	input.push_back(12);
	input.push_back(4);
	input.push_back(16);
	input.push_back(1);
	input.push_back(6);
	input.push_back(19);
	input.push_back(5);
	input.push_back(9);
	input.push_back(2);
	input.push_back(20);
	input.push_back(11);
	input.push_back(18);
	input.push_back(7);
	input.push_back(14);
	input.push_back(3);
	input.push_back(13);
	input.push_back(8);
	input.push_back(17);
	input.push_back(10);
	input.push_back(15);

	std::cout << "INPUT SIZE:" << input.size() << std::endl;
// first string input

// first pair
	std::vector<std::pair<int,int> > pairs;
	for (size_t i = 0; i + 1 < input.size();)
	{
		pairs.push_back(std::make_pair(input[i], input[i + 1]));
		i += 2;
	}
// first pair swap
	for (std::vector<std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);

		std::cout << "First:" << it->first << "Second:" << it->second << std::endl;
	}
	std::cout << "1st SIZE:" << pairs.size() << std::endl;


// first pair pointer vector
	std::vector<std::pair<int,int> *> ptrVector;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		ptrVector.push_back(&pairs[i]);
	}
	for (size_t i = 0; i + 1 < ptrVector.size();)
	{
		if (ptrVector[i]->first < ptrVector[i+1]->first)
			std::swap(ptrVector[i], ptrVector[i+1]);
		i += 2;
	}
	std::cout << "1st SIZE:" << ptrVector.size() << std::endl;


	for (size_t i = 0; i < ptrVector.size(); ++i)
	{
		std::cout << "FIRST:" << ptrVector[i]->first << " SECOND:" << ptrVector[i]->second << std::endl;
		std::cout << "ADD:" << ptrVector[i] << std::endl;
	}


	std::vector< std::pair<int,int>*, std::pair<int,int>* > ptrSecond;
	for (size_t i = 0; i < ptrVector.size();)
	{
		ptrSecond.push_back(ptrVector[i]);
		i += 2;
	}
	std::cout << "2nd SIZE:" << ptrSecond.size() << std::endl;
	//for (size_t i = 0; i < ptrSecond.size(); ++i)
	//{
	//	std::cout << "First:" << ptrSecond[i]->first << " Second:" << ptrSecond[i]->second << std::endl;
	//	std::cout << "ADD:" << ptrSecond[i] << std::endl;
		//std::cout << "+1First:" << (ptrSecond[i]+1)->first << " +1Second:" << (ptrSecond[i]+1)->second << std::endl;
	//}


	//std::cout << "1st SIZE:" << pairs.size() << std::endl;





	//std::vector<std::pair<int,int> > pairs;

	//pairs.push_back(std::make_pair(12,4));
	//pairs.push_back(std::make_pair(16,1));
	//pairs.push_back(std::make_pair(6,19));
	//pairs.push_back(std::make_pair(5,9));
	//pairs.push_back(std::make_pair(2,20));
	//pairs.push_back(std::make_pair(11,18));
	//pairs.push_back(std::make_pair(7,14));
	//pairs.push_back(std::make_pair(3,13));
	//pairs.push_back(std::make_pair(8,17));
	//pairs.push_back(std::make_pair(10,15));


	//std::cout << "@@@@@@@@@AFTER SWAP@@@@@@@@@" << std::endl;

	//for (std::vector<std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	//{
	//	if (it->first < it->second)
	//		std::swap(it->first, it->second);

	//	std::cout << "First:" << it->first << "Second:" << it->second << std::endl;
	//}

	//for (size_t i = 0; i < pairs.size(); ++i)
	//{
	//	pairs.push_back(std::make_pair(pairs[i], pairs[i + 1]))
	//}
}