//			std::list

//doubly linked list로 구성
//nums는 첫 주소와 마지막 주소를 알고 있다.
//나머지는 링크드 리스트로 연결

//emplace 함수들은 O(1) time complexity
//random access에서는 O(1)이 아님!! -> vector와 다른점

//merge, splice 

#include<iostream>
#include<list>

int main()
{
	std::list<int> nums{ 1,2,3,4,5 };

	nums.emplace_back(6);
	nums.emplace_front(0);

	auto it = std::find(nums.begin(), nums.end(), 3); //O(n)의 find + O(1)의 emplace
	if (it != nums.end())
	{
		nums.emplace(it, 100);
	}

	for (auto num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}

