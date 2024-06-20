#include <iostream>
#include <vector>
	//int maxJacobNumber = 0;
	//while (jacobsthalNumber(maxJacobNumber) < mainNumber)
	//	++maxJacobNumber;

int jacobsthalNumber(int number)
{
	if (number == 0)
		return 0;
	else if (number == 1)
		return 1;
	else
		return (jacobsthalNumber(number-1) +jacobsthalNumber(number-2) * 2);
}

std::vector<int> makeJacobsthalArray(size_t mainNumber)
{
	std::vector<int> jacobArray;
	
	int startJacobNumber = 2;
	int index = 0;
	while (index < mainNumber)
	{
		int maxNumber = jacobsthalNumber(startJacobNumber); // 1, 3, 5, 11, 21, 43, 85, ...
		if (maxNumber > mainNumber)
			maxNumber = mainNumber;
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

//std::vector<int> jacobArray(size_t pendingSize)
//{
//	int index = 3;
//	int jacobIndex = jacobsthal(index);
//	std::vector<int> jacobArray;
//	while ((jacobIndex = jacobsthal(index)) < pendingSize)
//	{
//		jacobArray.push_back(jacobIndex);
//		++index;
//	}
//	return jacobArray;
//}

int main()
{
	std::vector<int> jacob = makeJacobsthalArray(5);
	std::cout << "jacob(5) : ";
	for (int i = 0; i < jacob.size(); ++i)
		std::cout << jacob[i] << " ";
	std::cout << std::endl;

	std::vector<int> jacob10 = makeJacobsthalArray(10);
	std::cout << "jacob(10) : ";
	for (int i = 0; i < jacob10.size(); ++i)
		std::cout << jacob10[i] << " ";
	std::cout << std::endl;

	std::vector<int> jacob15 = makeJacobsthalArray(15);
	std::cout << "jacob(15) : ";
	for (int i = 0; i < jacob15.size(); ++i)
		std::cout << jacob15[i] << " ";
	std::cout << std::endl;

	std::vector<int> jacob20 = makeJacobsthalArray(20);
	std::cout << "jacob(20) : ";
	for (int i = 0; i < jacob20.size(); ++i)
		std::cout << jacob20[i] << " ";
	std::cout << std::endl;

	std::vector<int> jacob21 = makeJacobsthalArray(21);
	std::cout << "jacob(21) : ";
	for (int i = 0; i < jacob21.size(); ++i)
		std::cout << jacob21[i] << " ";
	std::cout << std::endl;
	return 0;
}