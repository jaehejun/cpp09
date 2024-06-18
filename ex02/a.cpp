#include <iostream>
#include <vector>

std::vector<int> pMerge(std::vector<int> &pVector, int &depth)
{
	int swapCount = pVector.size() / (depth * 2);
	int index = 0;
	while (swapCount > 0)
	{
		std::cout << "SWAP_C:" << swapCount << std::endl;
		std::cout << "INDEX: " << index << std::endl;
		if (pVector[index] < pVector[index+depth])
		{
			for (size_t sub = 0; sub < depth; ++sub)
				std::swap(pVector[index+sub], pVector[index+sub+depth]);
		}
		index += 2 * depth;
		--swapCount;
	}

	// swap 이후 출력
	for (size_t index = 0; index < pVector.size(); ++index)
		std::cout << "pVector[" << depth << "]:" << pVector[index] << std::endl;

	depth *= 2; // 2

	return pVector;
}

std::vector<int> pInsert(std::vector<int> & pVector, int &depth)
{
	std::cout << "DEPTH:" << depth << std::endl; // depth = 4
	for (size_t sub = 0; sub < depth; ++sub)
		std::swap(pVector[sub], pVector[sub+depth]);

	// swap 이후 출력
	for (size_t index = 0; index < pVector.size(); ++index)
		std::cout << "pVector[" << depth << "]:" << pVector[index] << std::endl;
	//for (size_t index = 0; index < pVector.size();)
	//{
		
	//}

	depth /= 2;

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

	//size_t size = first.size();
	int depth = 1; // 1

	int mergeCount = first.size();
	for (int mergeCount = first.size(); mergeCount > 1; mergeCount /= 2)
	{
		std::cout << "MERGE COUNT:" << mergeCount << std::endl;
		std::vector<int> pVector = pMerge(first, depth);
	}

	depth /= 2;
	
	//for (int insertCount = depth; insertCount > 1; insertCount /= 2)
	//{
	//	std::cout << "INSERT COUNT:" << insertCount << std::endl;
	//	std::vector<int> insertVector = pInsert(first, depth);
	//}




	//for (size_t index = 0; index < size;)
	//{
	//	if (first[index] < first[index+depth])
	//	{
	//		for (size_t sub = 0; sub < depth; ++sub)
	//			std::swap(first[index+sub], first[index+sub+depth]);
	//	}
	//	index += 2 * depth;
	//}
	//for (size_t index = 0; index < size; ++index)
	//	std::cout << "FIRST:" << first[index] << std::endl;


	//depth *= 2; // 2
	////std::vector<int> second;
	////second = first;
	//for (size_t index = 0; index < size;)
	//{
	//	if (first[index] < first[index+depth])
	//	{
	//		for (size_t sub = 0; sub < depth; ++sub)
	//			std::swap(first[index+sub], first[index+sub+depth]);
	//	}
	//	index += 2 * depth;
	//}
	//for (size_t index = 0; index < size; ++index)
	//	std::cout << "SECOND:" << first[index] << std::endl;


	//depth *= 2; // 4
	////std::vector<int> third;
	////third = second;
	//for (size_t index = 0; index < size;)
	//{
	//	if (first[index] < first[index+depth])
	//	{
	//		for (size_t sub = 0; sub < depth; ++sub)
	//			std::swap(first[index+sub], first[index+sub+depth]);
	//	}
	//	index += 2 * depth;
	//}
	//for (size_t index = 0; index < size; ++index)
	//	std::cout << "THIRD:" << first[index] << std::endl;

}