//					<copy/ move assignment>


#include<iostream>
#include<string>

class Cat
{
public:
	Cat() = default; 
	Cat(std::string name, int age)
		:mName{ std::move(name) }
		, mAge{ age }
	{
		std::cout << mName << " constructor" << std::endl;
	}

	// **예외 던져지지 않는 경우 noexcept 꼭 써주기 : destructor, move constructor, move assignment
	~Cat() noexcept 
	{
		std::cout << mName << " destructor" << std::endl;
	}

	Cat(const Cat& ref) //copy constructor
		:mName(ref.mName)
		, mAge(ref.mAge)
	{
		std::cout << mName << " copy constructor" << std::endl;
	}

	Cat(Cat&& other) noexcept //move constructor
		:mName{ std::move(other.mName) }
		, mAge{ other.mAge }
	{
		std::cout << mName << " move constructor" << std::endl;
	}

	Cat& operator=(const Cat& other) //copy assignment
	{
		if (&other == this) //self assignment 방지
			return *this;

		mName = other.mName;
		mAge = other.mAge;
		std::cout << mName << " copy assignment" << std::endl;
		return *this;
	}

	Cat& operator=(Cat&& other) noexcept //move assignment
	{
		if (&other == this) //self assignment 방지
			return *this;

		mName = std::move(other.mName);
		mAge = other.mAge;
		std::cout << mName << " move assignment" << std::endl;
		return *this;
	}

	void print()
	{
		std::cout << mName << " " << mAge << std::endl;
	}

private:
	std::string mName;
	int mAge;
};


int main()
{
	Cat kitty{ "kitty",1 };
	Cat nabi{ "nabi",2 };

	//kitty = nabi; //copy assignment
	//kitty.print();

	kitty = std::move(nabi); //move assignment
	kitty.print();
	nabi.print();

	//kitty = kitty;
	//kitty = std::move(kitty); //포인터 멤버 변수가 있을때 이런 행동 위험함..위처럼 방지 코드 만들기

	return 0;
}

//클래스에서 포인터로 리소스 관리하는 경우 위에서 구현한것을 그때마다 구현해주어야 한다.-> 생산성이 낮아짐
//포인터를 통한 리소스 관리는 좋지 않다네...
//(포인터가 아닌 경우 생성자만 만들어 주면 된다.)


//			<delete>
//Cat(const Cat& other) = delete; //강제로 컴파일러가 copy constructor 만드는 것을 금지시킴(delete 키워드)
//static 메소드만 있는 클래스의 경우 오브젝트를 만들 필요 x -> 생성자를 delete로 만든다.
//singleton 패턴의 경우 copy constructor 등을 막기
//private 쪽에 메소드들에 들어있는 것은 C++11 이전의 방법(delete와 같은 내용)