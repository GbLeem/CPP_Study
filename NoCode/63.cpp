//			std::forward_list

//insertion, deletion -> O(1)
//random access -> O(n)
//singly linked list로 구성
//list 보다 적은 공간을 차지
//마지막 공간을 가리키는 포인터 x, 앞에만 넣을 수 있다.

//nums는 포인터 하나 가짐(첫 공간의 주소 가리킴)

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

//			random access	 Insert/Delete       I/D back(뒤에)		find
//vector :    O(1)				O(n)				O(1)			O(n)				
//list   :    O(n)				O(1)				O(1)			O(n)

//vector를 사용하는 것이 빠르다!! 
//find()의 경우 둘 다 O(n)의 복잡도지만 컴퓨터의 구조 상 vector가 더 빠르다
//-> list는 메모리 구조상 3개씩 (포인터/저장할 값/포인터 의 구조) 띄어서(연속되지 x) 존재

//vector의 메모리는 연속된 데이터이기 때문에 모두가 같은 cache안에 들어가 있다.
//list 는 떨어져 있으므로 cache miss가 계속 발생한다.
