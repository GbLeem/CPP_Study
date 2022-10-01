//				<std::set>

//���� ���� �������� ����
//red-black tree�� ���� or
//balanced binary search tree => ����� ���ʿ��� �ڽź��� ���� �� �����ʿ��� �ڽź��� ū ��

//set �� �ð� ���⵵ -> 
//find : O(logn)
//insert, deletion : O(logn)

//set�� �ߺ��� ������� ���� < - > multi-set : �ߺ��� �ִ� set
//set�� ������ ���������� ���ĵǾ��ִ�. < - > unordered_set : ���� Ư���� ���� set (hash function�� ���)

#include<iostream>
#include<set>

int main()
{
	std::set<int>nums{ 1,2,3,4,5 };
	
	// set�� �ߺ� ��� x
	nums.emplace(3);
	nums.emplace(3);
	nums.emplace(3);
	nums.emplace(3);
	//1 2 3 4 5 ���

	nums.emplace(-1);
	nums.emplace(100);
	nums.emplace(2);
	//-1 1 2 3 4 5 100 ���

	for (const int num : nums)
	{
		std::cout << num << " "; 
	}
	std::cout << std::endl;

	return 0;
}