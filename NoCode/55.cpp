//					<vector memeory>


//맨 뒤에 push, pop하는 경우 O(1) 그러나 보장되지는 않음
//가끔보다 자주 O(n)이 된다..

#include<iostream>
#include<vector>
#include<string>

//int main()
//{
//	std::vector<int>nums;
//	std::cout << sizeof(nums) << std::endl; //24
//	//아무것도 없는 벡터인데 24 바이트가 나온다
//	//1. heap위에있는 array의 시작을 가리키는 포인터(8byte)
//	//2. size (8byte) -> 현재 벡터에 들어있는 element의 갯수
//	//3. capacity (8byte) -> 벡터가 확보한 메모리의 크기-> 확보된 빈array에 넣으면 되므로 o(1)의 complexity!
//	//capacity를 증가해둔것 보다 더 많은 양의 데이터를 넣을때는 O(n)의 complexity가 되는것이다.
//	//공간이 없을때는 전체가 복사 또는 move를 해야하므로 O(n) -> reserve로 미리 공간을 만들어 두는 것이 좋다. 
//
//	//capacity를 증가시키는 함수 : reserve
//	nums.reserve(10000);
//	std::cout << nums.size() << std::endl; //0
//	std::cout << nums.capacity() << std::endl; //10000
//
//	return 0;
//}


class Cat
{
public:
	explicit Cat(std::string name)
		:mName{ std::move(name) }
	{
		std::cout << mName << " cat constructor" << std::endl;
	}
	~Cat()
	{
		std::cout << "cat destructor" << std::endl;
	}
	Cat(const Cat& other)
		:mName(other.mName)
	{
		std::cout << mName << " copy constructor" << std::endl;
	}
	Cat(Cat&& other) noexcept
		:mName(other.mName)
	{
		std::cout << mName << " move constructor" << std::endl;
	}
private:
	std::string mName;
};
int main()
{
	std::vector<Cat>cats;
	cats.reserve(2); // migration 없애기! -> 가장 좋은 방법
	cats.emplace_back("kitty");
	cats.emplace_back("nabi");
	return 0;
	
	//<출력>
	//kitty cat constructor
	//nabi cat constructor
	//kitty copy constructor -> move constructor를 noexcept로 하면 move constructor 사용한다.
	//cat destructor
	//cat destructor
	//cat destructor

	//destructor, move constructor, move assignment는 noexcept를 붙이기
}