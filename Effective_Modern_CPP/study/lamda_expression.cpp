#include<iostream>

class Plus
{
public:
	explicit Plus(int a):localVar{a}
	{}

	int operator() (int x) const
	{
		return localVar + x;
	}
private:
	int localVar;
};

//[] : ĸ��
int main()
{
	int three{ 3 };

	auto lamda3 =
		[three](int x) //capture by value
	{
		return x + three; 
	};

	VERYLARGEOBJECT object; //�ſ�ū Ÿ���� object

	auto lamdaLarge =
		[&object](int x) //capture by reference : �ſ� ū ���� ��� ȿ���� ���̱� ����
	{
		return x + object;
	};

	auto lamdaval =
		[=](int x) //{}; �ȿ��� ����� �Ϳ� ���� value�� ������ ã�Ƽ� ����
	{
		return x + three;
	};
	auto lamdaref =
		[&](int x) //{}; �ȿ��� ����� �Ϳ� ���� reference�� ������ ã�Ƽ� ����
	{
		return x + object;
	};

	auto lamdaPlus3 = 
		[localVar = 3](int x) //lamda function -> ���� Ŭ������ ��ü ������ ���� ����
	{
		return localVar + x;
	};

	Plus plus3{ 3 };

	std::cout << plus3(10) << std::endl;
	std::cout << lamdaPlus3(10) << std::endl;
}
