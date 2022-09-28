//			std::forward_list

//insertion, deletion -> O(1)
//random access -> O(n)
//singly linked list�� ����
//list ���� ���� ������ ����
//������ ������ ����Ű�� ������ x, �տ��� ���� �� �ִ�.

//nums�� ������ �ϳ� ����(ù ������ �ּ� ����Ŵ)

#include<algorithm>
#include<iostream>
#include<forward_list>

int main()
{
	std::forward_list<int>nums{ 1,2,3,4,5 };

	nums.emplace_front(0);

	for (auto num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}


//====================================

//vector VS list  -> vector better!!

//			random access	 Insert/Delete       I/D back(�ڿ�)		find
//vector :    O(1)				O(n)				O(1)			O(n)				
//list   :    O(n)				O(1)				O(1)			O(n)

//vector�� ����ϴ� ���� ������!! 
//find()�� ��� �� �� O(n)�� ���⵵���� ��ǻ���� ���� �� vector�� �� ������
//-> list�� �޸� ������ 3���� (������/������ ��/������ �� ����) ��(���ӵ��� x) ����

//vector�� �޸𸮴� ���ӵ� �������̱� ������ ��ΰ� ���� cache�ȿ� �� �ִ�.
//list �� ������ �����Ƿ� cache miss�� ��� �߻��Ѵ�.
