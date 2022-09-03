//						<copy/move constructor>
// https://en.cppreference.com/w/cpp/language/rule_of_three

#include<iostream>
#include<string>

class Cat
{
public:
	Cat() = default; //default constructor�� default�� ����
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
		
		//(����)
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
	//char* mPtr; //raw �����͸� ����� ������ �� �� �Ʒ��� �޼ҵ带 �����ؾ� �Ѵ�.
};

//��ó�� Ŭ���� ���� �� �ڵ����� ����� ���°� 
//1. constructor
//2. destructor
//3. copy/move constructor
//4. copy/move assignment

int main()
{
	Cat kitty{ "kitty", 1 };
	//Cat nabi; //default constructor�� default�� �����Ͽ� �ذ�

	Cat kitty2{ kitty };
	//Cat kitty3 = kitty; //copy constructor ȣ�� !! assignment�� �򰥸��Ƿ�.. {} ����ϴ� ����� �� ����.

	Cat kitty3{ std::move(kitty) }; //move constructor ȣ�� -> kitty�� desturctor�� ȣ��ɶ� mName�� ������
									//                         move�� ���� mName�� �������� kitty3���� ����
	return 0;
}