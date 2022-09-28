//			std::stack , std::queue


//stack: LIFO -> Last in First out

//#include<iostream>
//#include<stack>
//
//int main()
//{
//	std::stack<int> nums;
//
//	nums.emplace(1);
//	nums.emplace(3);
//	nums.emplace(5);
//
//	std::cout << nums.top() << std::endl;
//	nums.pop();
//	std::cout << nums.top() << std::endl;
//	nums.pop();
//	std::cout << nums.top() << std::endl;
//	nums.pop();
//
//	std::cout << "size: " << nums.size() << std::endl;
//
//	return 0;
//}

//===========================

//queue: FIFO -> first in first out
#include<iostream>
#include<queue>

int main()
{
	std::queue<int> nums;

	nums.emplace(1);
	nums.emplace(3);
	nums.emplace(5);

	std::cout << nums.front() << " " << nums.back() << std::endl;
	nums.pop();
	std::cout << nums.front() << " " << nums.back() << std::endl;
	nums.pop();
	std::cout << nums.front() << " " << nums.back() << std::endl;
	nums.pop();

	std::cout << "size: " << nums.size() << std::endl;

	return 0;
}

//performance를 향상시키려면 implementation 만드는 것이 좋다