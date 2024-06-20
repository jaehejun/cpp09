#include <iostream>
#include <vector>

int binaryInsertion(std::vector<int> sorted, size_t range, int value)
{
	int left = 0;
	int right = range;
	while (left < right)
	{
		int mid = (left + right) / 2;
		//std::cout << "LEFT:" << left << std::endl;
		//std::cout << "RIGHT:" << right << std::endl;
		//std::cout << "MID:" << mid << std::endl;
		if (value < sorted[mid])
			right = mid;
		else //(value > sorted[mid])
			left = mid + 1;
	}
	//sorted.insert(sorted.begin() + left, value);
	//std::vector<int> result = sorted;
	//result.insert(result.begin() + left, value);

	//return result;
	return left;
}
std::vector<int> binaryInsertion(int value, std::vector<int> sorted)
{
	int left = 0;
	int right = sorted.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		//std::cout << "LEFT:" << left << std::endl;
		//std::cout << "RIGHT:" << right << std::endl;
		//std::cout << "MID:" << mid << std::endl;
		if (value < sorted[mid])
			right = mid - 1;
		else //(value > sorted[mid])
			left = mid + 1;
	}
	sorted.insert(sorted.begin() + left, value);
	//std::vector<int> result = sorted;
	//result.insert(result.begin() + left, value);

	//return result;
	return sorted;
}

std::vector<int> mergeInsertion(std::vector<int> mainChain)
{
	//step 1 : pairwise comparison
	int n = mainChain.size();
	std::cout << "MAIN SIZE: " << n << std::endl;
	std::vector<int> main;
	std::vector<int> pending;
	std::vector<std::pair<int,int> > pairs;
	for (size_t index = 0; index < n / 2; ++index)
	{
		if (mainChain[index] < mainChain[n/2 + index])
		{
			main.push_back(mainChain[n/2 + index]);
			pending.push_back(mainChain[index]);
			pairs.push_back(std::make_pair(mainChain[n/2 + index], mainChain[index]));
		}
		else
		{
			main.push_back(mainChain[index]);
			pending.push_back(mainChain[n/2 + index]);
			pairs.push_back(std::make_pair(mainChain[index], mainChain[n/2 + index]));
		}
	}
	if (n % 2 == 1)
		pending.push_back(mainChain[n-1]);

	//std::cout << "MAIN ADD:" << &main << std::endl;
	for (int i = 0; i < main.size(); ++i)
		std::cout << "MAIN:" << main[i] << std::endl;
	//std::cout << "PEND ADD:" << &pending << std::endl;
	for (int i = 0; i < pending.size(); ++i)
		std::cout << "PEND:" << pending[i] << std::endl;

	//step 2 : Recursion and Renaming
	if (main.size() > 1)
		main = mergeInsertion(main);

	//step 3 : Insertion
	std::cout << "@@@@@@@@MAIN BEFORE SORTED@@@@@@@@@@@@@" << std::endl;
	for (int i = 0; i < main.size(); ++i)
		std::cout << main[i] << std::endl;
	std::cout << "@@@@@@@@PEND BEFORE SORTED@@@@@@@@@@@@@" << std::endl;
	for (int i = 0; i < pending.size(); ++i)
		std::cout << pending[i] << std::endl;
	
	for (int i = 0; i < main.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == main[i])
				pending[i] = pairs[j].second;
		}
	}
	std::cout << "@@@@@@@@PEND CHANGED!!!! @@@@@@@@@@@@@" << std::endl;
	for (int i = 0; i < pending.size(); ++i)
		std::cout << pending[i] << std::endl;

	std::vector<int> sorted = main;
	// pending[0] < main[0] 항상 만족하므로 먼저 맨앞에 넣고 나머지 insert
	sorted.insert(sorted.begin(), pending[0]);
	//for (int i = 2; i < main.size() + pending.size(); ++i)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


	//step 4 : Binary Insertion
	//while (sorted.size() < main.size() + pending.size())
	//{
	//	int pendingIndex = 1;
	//	//std::vector<int> result = binaryInsertion(pending[index], main);
	//	//std::cout << "BEFORE BINARY" << std::endl;
	//	sorted = binaryInsertion(pending[pendingIndex], sorted);
	//	//std::cout << "AFTER BINARY" << std::endl;
	//}
	std::cout << "@@@@@@@@SORTED@@@@@@@@@@@@@" << std::endl;
	for (int i = 0; i < sorted.size(); ++i)
		std::cout << sorted[i] << std::endl;

	std::cout << "@@@@@@@@MAIN after SORTED@@@@@@@@@@@@@" << std::endl;
	for (int i = 0; i < main.size(); ++i)
		std::cout << main[i] << std::endl;
	std::cout << "@@@@@@@@PEND after SORTED@@@@@@@@@@@@@" << std::endl;
	for (int i = 0; i < pending.size(); ++i)
		std::cout << pending[i] << std::endl;

	return sorted;
}


int main()
{
	std::vector<int> mainChain;
	mainChain.push_back(1);
	mainChain.push_back(0);
	mainChain.push_back(12);
	mainChain.push_back(2);
	mainChain.push_back(5);
	mainChain.push_back(6);
	mainChain.push_back(11);
	mainChain.push_back(9);
	mainChain.push_back(8);
	mainChain.push_back(3);
	mainChain.push_back(10);
	mainChain.push_back(7);
	mainChain.push_back(4);

	//size_t size = mainChain.size();
	int groupSize = 1; // 1

	//int mergeCount = mainChain.size();

	std::vector<int> sorted = mergeInsertion(mainChain);

	std::cout << "@@@@@ RESULT @@@@@" << std::endl;
	for (int i = 0; i < sorted.size(); ++i)
		std::cout << sorted[i] << std::endl;
}