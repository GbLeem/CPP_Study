//								<Weak Pointer>


//object를 shared pointer처럼 가리킬 수 있지만 reference counter에 영향을 주지 않는다.

#include<iostream>
#include<memory>

class Cat
{
public:
	Cat()
		:mAge{1}
	{
		std::cout << "Cat constructor" << std::endl;
	}
	~Cat()
	{
		std::cout << "Cat desturctor" << std::endl;
	}
	void speak()
	{
		std::cout << "Im cat.." << std::endl;
	}

private:
	int mAge;
};

int main()
{
	std::weak_ptr<Cat> wPtr; 
	{
		std::shared_ptr<Cat> sPtr = std::make_shared<Cat>();
		wPtr = sPtr;
		std::cout << "count: " << sPtr.use_count() << std::endl;

		if (const auto spt = wPtr.lock()) //weak pointer를 사용하려면 lock을 사용해야 한다.
		{
			std::cout << "count: " << sPtr.use_count() << std::endl;
			spt->speak();
		}
	}

	return 0;
}


//======================= 멤버 variable로 unique, shared pointer가 있는 경우 ===========================
//member variable로 unique_ptr 을 가진다면...
//컴파일러가 copy constructor를 없애버린다(unique한것을 지키기 위해서) -> 원한다면 직접 만들어서 쓰면 된다.

//member variable로 shared_ptr 을 가진다면...
//class에 주석을 달아주기
//clone이라는 deep copy interface를 만들어 주기

class Dog
{
public:
	explicit Dog(int n)
		:mVar{ std::make_shared<int>(n) }
	{
		std::cout << "constructor" << std::endl;
	}
	~Dog() noexcept
	{
		std::cout << "destructor" << std::endl;
	}
	Dog clone() const
	{
		Dog temp{ *mVar };
		return temp;
	}
private:
	std::shared_ptr<int> mVar;
};

int main()
{
	const Dog dog1{ 2 };
	const Dog dog2{ dog1.clone() };
}