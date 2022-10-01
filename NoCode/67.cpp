//				<std::set>

//순서 없는 정보들의 집합
//red-black tree로 구현 or
//balanced binary search tree => 노드의 왼쪽에는 자신보다 작은 것 오른쪽에는 자신보다 큰 것

//set 의 시간 복잡도 -> 
//find : O(logn)
//insert, deletion : O(logn)

//set은 중복을 허락하지 않음 < - > multi-set : 중복이 있는 set
//set은 스스로 내부적으로 정렬되어있다. < - > unordered_set : 정렬 특성이 없는 set (hash function을 사용)

#include<iostream>
#include<set>

int main()
{
	std::set<int>nums{ 1,2,3,4,5 };
	
	// set은 중복 허락 x
	nums.emplace(3);
	nums.emplace(3);
	nums.emplace(3);
	nums.emplace(3);
	//1 2 3 4 5 출력

	nums.emplace(-1);
	nums.emplace(100);
	nums.emplace(2);
	//-1 1 2 3 4 5 100 출력

	for (const int num : nums)
	{
		std::cout << num << " "; 
	}
	std::cout << std::endl;

	return 0;
}