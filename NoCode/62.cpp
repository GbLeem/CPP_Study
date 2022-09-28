//			std::list

//doubly linked list�� ����
//nums�� ù �ּҿ� ������ �ּҸ� �˰� �ִ�.
//�������� ��ũ�� ����Ʈ�� ����

//emplace �Լ����� O(1) time complexity
//random access������ O(1)�� �ƴ�!! -> vector�� �ٸ���

//merge, splice 

#include<iostream>
#include<list>

int main()
{
	std::list<int> nums{ 1,2,3,4,5 };

	nums.emplace_back(6);
	nums.emplace_front(0);

	auto it = std::find(nums.begin(), nums.end(), 3); //O(n)�� find + O(1)�� emplace
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

