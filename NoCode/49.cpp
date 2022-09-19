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
	//function object와 lambda function은 둘 다 같은 어셈블리코드(메모리 공간 차지)
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

	//아래 두가지 경우는 자동으로 찾아줌
	auto lambda1 = [=](int x)  //value 찾아줌
	{
		return x + three;
	};

	auto lambda2 = [&](int x) //reference 찾아줌
	{
		return x + object;
	};

	std::cout << plus3(10) << std::endl; //13
	std::cout << lambdaPlus3(10) << std::endl; //13

}