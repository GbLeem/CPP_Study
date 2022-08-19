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

//[] : 캡쳐
int main()
{
	int three{ 3 };

	auto lamda3 =
		[three](int x) //capture by value
	{
		return x + three; 
	};

	VERYLARGEOBJECT object; //매우큰 타입의 object

	auto lamdaLarge =
		[&object](int x) //capture by reference : 매우 큰 값일 경우 효율성 높이기 위함
	{
		return x + object;
	};

	auto lamdaval =
		[=](int x) //{}; 안에서 사용한 것에 대한 value를 스스로 찾아서 적용
	{
		return x + three;
	};
	auto lamdaref =
		[&](int x) //{}; 안에서 사용한 것에 대한 reference를 스스로 찾아서 적용
	{
		return x + object;
	};

	auto lamdaPlus3 = 
		[localVar = 3](int x) //lamda function -> 위의 클래스의 객체 생성과 같은 역할
	{
		return localVar + x;
	};

	Plus plus3{ 3 };

	std::cout << plus3(10) << std::endl;
	std::cout << lamdaPlus3(10) << std::endl;
}
