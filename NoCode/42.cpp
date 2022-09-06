//								<Weak Pointer>


//object�� shared pointeró�� ����ų �� ������ reference counter�� ������ ���� �ʴ´�.

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

		if (const auto spt = wPtr.lock()) //weak pointer�� ����Ϸ��� lock�� ����ؾ� �Ѵ�.
		{
			std::cout << "count: " << sPtr.use_count() << std::endl;
			spt->speak();
		}
	}

	return 0;
}


//======================= ��� variable�� unique, shared pointer�� �ִ� ��� ===========================
//member variable�� unique_ptr �� �����ٸ�...
//�����Ϸ��� copy constructor�� ���ֹ�����(unique�Ѱ��� ��Ű�� ���ؼ�) -> ���Ѵٸ� ���� ���� ���� �ȴ�.

//member variable�� shared_ptr �� �����ٸ�...
//class�� �ּ��� �޾��ֱ�
//clone�̶�� deep copy interface�� ����� �ֱ�

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