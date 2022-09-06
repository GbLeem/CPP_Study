//							<Shared Pointer>


//Shared ownership을 제공함!!
//그러나 모든 pointer는 RAII 기능을 갖추어야 한다.
//reference counter를 가지고 메모리 leak을 방지한다.

#include<iostream>
#include<memory>

class Cat
{
public:
	Cat()
		:mAge{ 0 }
	{
		std::cout << "Cat constructor" << std::endl;
	}
	~Cat()
	{
		std::cout << "Cat desturctor" << std::endl;
	}

private:
	int mAge;
};

class Dog
{
public:
	Dog()
	{
		std::cout << "Dog constructor" << std::endl;
	}
	~Dog()
	{
		std::cout << "Dog desturctor" << std::endl;
	}

	std::shared_ptr<Dog> mVar;//메모리 leka용 멤버 variable
	std::shared_ptr<Dog> mFriend; //가장 많이 하는 실수용 멤버 variable
};

int main()
{
	/*Cat* catptr1 = new Cat();
	Cat* catptr2 = catptr1;
	delete catptr1;*/


	//Shared pointer 의 좋은 예시
	//std::shared_ptr<Cat> catPtr1 = std::make_shared<Cat>();
	//std::cout << "count: " << catPtr1.use_count() << std::endl;
	//std::shared_ptr<Cat>catPtr2 = catPtr1;
	//std::cout << "count: " << catPtr1.use_count() << std::endl;


	//Shared pointer의 leak 예시
	//std::shared_ptr<Dog>mPtr = std::make_shared <Dog>();
	//mPtr->mVar = mPtr; //자기 자신을 가리키면서 reference count를 올라감
	//
	//std::cout << "count : " << mPtr.use_count() << std::endl;


	//자주 하는 실수 예시
	std::shared_ptr<Dog> dogPtr1 = std::make_unique<Dog>();
	std::shared_ptr<Dog> dogPtr2 = std::make_unique<Dog>();

	dogPtr1->mFriend = dogPtr2;
	dogPtr2->mFriend = dogPtr1; 
	// destructor 호출이 되지 않았다!! -> memory leak
	//circular reference가 만들어짐!!! -> 문제가 발생합니다..

	return 0;
}