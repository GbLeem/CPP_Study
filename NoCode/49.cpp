//				<Lambda Expression>

#include<iostream>

class Plus
{
public:
	explicit Plus(int a)
		:localVar{ a }
	{}
	int operator() (int x)const
	{
		return localVar + x;
	}
private:
	int localVar;
};

int main()
{
	//function object�� lambda function�� �� �� ���� ������ڵ�(�޸� ���� ����)
	Plus plus3{ 3 }; //function object

	auto lambdaPlus3 = 
		[localVar = 3](int x) //lambda function
	{
		return localVar + x;
	};

	// capture : []
	//1. capture by value -> deep copy
	//2. capture by ref
	//3. capture by this

	int three{ 3 };
	auto lambdaPlus3 = [three](int x) // capture by value
	{
		return x + three;
	};

	VERYLARGEOBJECT object;
	auto lambdaLarge = [&object](int x) // capture by reference
	{
		return x + object;
	};

	//�Ʒ� �ΰ��� ���� �ڵ����� ã����
	auto lambda1 = [=](int x)  //value ã����
	{
		return x + three;
	};

	auto lambda2 = [&](int x) //reference ã����
	{
		return x + object;
	};

	std::cout << plus3(10) << std::endl; //13
	std::cout << lambdaPlus3(10) << std::endl; //13

}