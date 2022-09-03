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

	// **���� �������� �ʴ� ��� noexcept �� ���ֱ� : destructor, move constructor, move assignment
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
		if (&other == this) //self assignment ����
			return *this;

		mName = other.mName;
		mAge = other.mAge;
		std::cout << mName << " copy assignment" << std::endl;
		return *this;
	}

	Cat& operator=(Cat&& other) noexcept //move assignment
	{
		if (&other == this) //self assignment ����
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
	//kitty = std::move(kitty); //������ ��� ������ ������ �̷� �ൿ ������..��ó�� ���� �ڵ� �����

	return 0;
}

//Ŭ�������� �����ͷ� ���ҽ� �����ϴ� ��� ������ �����Ѱ��� �׶����� �������־�� �Ѵ�.-> ���꼺�� ������
//�����͸� ���� ���ҽ� ������ ���� �ʴٳ�...
//(�����Ͱ� �ƴ� ��� �����ڸ� ����� �ָ� �ȴ�.)


//			<delete>
//Cat(const Cat& other) = delete; //������ �����Ϸ��� copy constructor ����� ���� ������Ŵ(delete Ű����)
//static �޼ҵ常 �ִ� Ŭ������ ��� ������Ʈ�� ���� �ʿ� x -> �����ڸ� delete�� �����.
//singleton ������ ��� copy constructor ���� ����
//private �ʿ� �޼ҵ�鿡 ����ִ� ���� C++11 ������ ���(delete�� ���� ����)