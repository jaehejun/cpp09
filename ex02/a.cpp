#include <iostream>
#include <vector>
//std::vector<int> mergeInsertion(std::vector<int> &vector, int &groupSize)
//{
//	//step 1 : pairwise comparison
//	int swapCount = vector.size() / (groupSize * 2);
//	int index = 0;
//	while (swapCount > 0)
//	{
//		if (vector[index] < vector[index+groupSize])
//		{
//			for (size_t sub = 0; sub < groupSize; ++sub)
//				std::swap(vector[index+sub], vector[index+groupSize+sub]);
//		}
//		index += 2 * groupSize;
//		--swapCount;
//	}

//	for (size_t index = 0; index < vector.size(); ++index)
//		std::cout << "vector[" << groupSize << "]:" << vector[index] << std::endl;


//	//step 2 : Recursion and Renaming
//	groupSize *= 2;
//	if (vector.size() / groupSize > 2)
//		std::vector<int> sorted = mergeInsertion(vector, groupSize);


//	//step 3 : Insertion
//	std::vector<int> main;
//	std::vector<int> pending;




//			//step 4 : Binary Insertion

//	return vector;
//}


std::vector<int> pMerge(std::vector<int> &pVector, int &groupSize)
{
	int swapCount = pVector.size() / (groupSize * 2);
	int index = 0;
	while (swapCount > 0)
	{
		std::cout << "SWAP_C:" << swapCount << std::endl;
		std::cout << "INDEX: " << index << std::endl;
		if (pVector[index] < pVector[index+groupSize])
		{
			for (size_t sub = 0; sub < groupSize; ++sub)
				std::swap(pVector[index+sub], pVector[index+groupSize+sub]);
		}
		index += 2 * groupSize;
		--swapCount;
	}

	// swap 이후 출력
	for (size_t index = 0; index < pVector.size(); ++index)
		std::cout << "pVector[" << groupSize << "]:" << pVector[index] << std::endl;

	groupSize *= 2; // 2

	return pVector;
}

std::vector<int> pInsert(std::vector<int> & pVector, int &groupSize)
{
	std::cout << "DEPTH:" << groupSize << std::endl; // groupSize = 4
	for (size_t sub = 0; sub < groupSize; ++sub)
		std::swap(pVector[sub], pVector[sub+groupSize]);

	// swap 이후 출력
	for (size_t index = 0; index < pVector.size(); ++index)
		std::cout << "pVector[" << groupSize << "]:" << pVector[index] << std::endl;
	//for (size_t index = 0; index < pVector.size();)
	//{
		
	//}

	groupSize /= 2;

	return pVector;
}

int main()
{
	std::vector<int> first;
	first.push_back(0);
	first.push_back(1);
	first.push_back(2);
	first.push_back(3);
	first.push_back(4);
	first.push_back(5);
	first.push_back(6);
	first.push_back(7);
	first.push_back(8);
	first.push_back(9);
	first.push_back(10);
	first.push_back(11);
	first.push_back(12);

	//size_t size = first.size();
	int groupSize = 1; // 1

	int mergeCount = first.size();

	mergeInsertion(first, groupsize);

	for (int mergeCount = first.size(); mergeCount > 1; mergeCount /= 2)
	{
		std::cout << "MERGE COUNT:" << mergeCount << std::endl;
		std::vector<int> pVector = pMerge(first, groupSize);
	}

	groupSize /= 2;
	
	//for (int insertCount = groupSize; insertCount > 1; insertCount /= 2)
	//{
	//	std::cout << "INSERT COUNT:" << insertCount << std::endl;
	//	std::vector<int> insertVector = pInsert(first, groupSize);
	//}




	//for (size_t index = 0; index < size;)
	//{
	//	if (first[index] < first[index+groupSize])
	//	{
	//		for (size_t sub = 0; sub < groupSize; ++sub)
	//			std::swap(first[index+sub], first[index+sub+groupSize]);
	//	}
	//	index += 2 * groupSize;
	//}
	//for (size_t index = 0; index < size; ++index)
	//	std::cout << "FIRST:" << first[index] << std::endl;


	//groupSize *= 2; // 2
	////std::vector<int> second;
	////second = first;
	//for (size_t index = 0; index < size;)
	//{
	//	if (first[index] < first[index+groupSize])
	//	{
	//		for (size_t sub = 0; sub < groupSize; ++sub)
	//			std::swap(first[index+sub], first[index+sub+groupSize]);
	//	}
	//	index += 2 * groupSize;
	//}
	//for (size_t index = 0; index < size; ++index)
	//	std::cout << "SECOND:" << first[index] << std::endl;


	//groupSize *= 2; // 4
	////std::vector<int> third;
	////third = second;
	//for (size_t index = 0; index < size;)
	//{
	//	if (first[index] < first[index+groupSize])
	//	{
	//		for (size_t sub = 0; sub < groupSize; ++sub)
	//			std::swap(first[index+sub], first[index+sub+groupSize]);
	//	}
	//	index += 2 * groupSize;
	//}
	//for (size_t index = 0; index < size; ++index)
	//	std::cout << "THIRD:" << first[index] << std::endl;

}