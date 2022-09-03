//						<copy/move constructor>
// https://en.cppreference.com/w/cpp/language/rule_of_three

#include<iostream>
#include<string>

class Cat
{
public:
	Cat() = default; //default constructor를 default로 지정
	Cat(std::string name, int age)
		:mName{ std::move(name) }
		, mAge{ age }
	{
		std::cout << mName << " constructor" << std::endl;
	}

	~Cat()
	{
		std::cout << mName << " destructor" << std::endl;
	}

	Cat(const Cat& ref) //copy constructor
		:mName(ref.mName)
		,mAge(ref.mAge)
	{
		std::cout << mName << " copy constructor" << std::endl;
	}

	Cat(Cat&& other)
		:mName{ std::move(other.mName) }
		, mAge{ other.mAge }
	{
		std::cout << mName << " move constructor" << std::endl;	
		
		//(참고)
		//mPtr = other.mPtr;
		//other.mPtr = nullptr;
	}

	Cat& operator=(const Cat& other)
	{
		mName = other.mName;
		mAge = other.mAge;
		std::cout << mName << " copy assignment" << std::endl;
		return *this;
	}

	void print()
	{
		std::cout << mName << " " << mAge << std::endl;
	}

private:
	std::string mName;
	int mAge;
	//char* mPtr; //raw 포인터를 만들어 관리를 할 시 아래의 메소드를 구현해야 한다.
};

//위처럼 클래스 구성 시 자동으로 만들어 지는것 
//1. constructor
//2. destructor
//3. copy/move constructor
//4. copy/move assignment

int main()
{
	Cat kitty{ "kitty", 1 };
	//Cat nabi; //default constructor를 default로 지정하여 해결

	Cat kitty2{ kitty };
	//Cat kitty3 = kitty; //copy constructor 호출 !! assignment랑 헷갈리므로.. {} 사용하는 방식이 더 좋다.

	Cat kitty3{ std::move(kitty) }; //move constructor 호출 -> kitty의 desturctor가 호출될때 mName은 없어짐
									//                         move를 통해 mName의 소유권을 kitty3에게 뺏김
	return 0;
}