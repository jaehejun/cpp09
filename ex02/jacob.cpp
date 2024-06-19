#include <iostream>
#include <vector>

int jacobsthal(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	int i = jacobsthal(n-1) + 2 * jacobsthal(n-2);
	return i;
}


//{
//	size_t	remain_size;
//	size_t	jacobsthal_idx;
//	int	index;

//	remain_size = this->remain.size();
//	index = 3;	//이미 remain의 첫 번째는 처리했으므로 3(그 다음 최소 야콥스탈 수)부터 처리한다.

//	while ((jacobsthal_idx = this->Jacobsthal(index)) < remain_size)	//remain의 갯수보다 작을 때까지 반복해서 돌리며 배열에 넣어준다.
//	{
//		this->jacob_arr.push_back(jacobsthal_idx);
//		index++;
//	}
//}

std::vector<int> jacobArray(size_t pendingSize)
{
	int index = 3;
	int jacobIndex = jacobsthal(index);
	std::vector<int> jacobArray;
	while ((jacobIndex = jacobsthal(index)) < pendingSize)
	{
		jacobArray.push_back(jacobIndex);
		++index;
	}
	return jacobArray;
}

int main()
{
	std::vector<int> test;

	std::cout << "@@@@ 2 @@@@" << std::endl;
	test = jacobArray(3);
	for (int i = 0; i < test.size(); ++i)
		std::cout << test[i] << std::endl;

	std::cout << "@@@@ 3 @@@@" << std::endl;
	test = jacobArray(3);
	for (int i = 0; i < test.size(); ++i)
		std::cout << test[i] << std::endl;
	
	std::cout << "@@@@ 7 @@@@" << std::endl;
	test = jacobArray(3);
	for (int i = 0; i < test.size(); ++i)
		std::cout << test[i] << std::endl;
	
	return 0;
	
}