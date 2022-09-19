//			<Functional Programming Introduction>

//C++ -> OOP + High Performance(by Cache hit <- data oriented programming)
//C++11 -> lambda expression

//function 프로그래밍 : 함수를 변수처럼 다루는 것이 시작
//function pointer / function object / javascript

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
	//c++에서 javascript랑 유사하게 만든것
	Plus plus3{ 3 }; //function object
	Plus plus5{ 5 };

	std::cout << plus3(10) << std::endl; //13
	std::cout << plus5(10) << std::endl; //15

}