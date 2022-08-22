#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base Constructor" << endl;
	}
	void SimpleFunc()
	{
		cout << "BaseOne" << endl;
	}
};

class MiddleDerivedOne :virtual public Base
{
public:
	MiddleDerivedOne() 
		:Base()
	{
		cout << "MiddleDerivedOne Constructor" << endl;
	}
	void MiddleFuncOne()
	{
		SimpleFunc();
		cout << "MiddleDerivedOne" << endl;
	}
};

class MiddleDerivedTwo :virtual public Base
{
public:
	MiddleDerivedTwo()
		:Base()
	{
		cout << "MiddleDerivedTwo Constructor" << endl;
	}
	void MiddleFuncTwo()
	{
		SimpleFunc();
		cout << "MiddleDerivedTwo" << endl;
	}
};

class LastDerived :public MiddleDerivedOne, public MiddleDerivedTwo 
	//LastDerived 클래스는 Base 클래스를 간접적으로 2번 상속한다
{
public:
	LastDerived()
		:MiddleDerivedOne()
		, MiddleDerivedTwo()
	{
		cout << "LastDerived Constructor" << endl;
	}
	void ComplexFunc()
	{
		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc(); //가상 상속을 통해 해당 부분에서 Base가 한개만 존재
					  //가상 상속이 아니었다면... MiddleDerivedTwo::SimpleFunc() 이런 식으로 써야 한다.
	}
};

int main()
{
	cout << "객체생성 전..... " << endl;
	LastDerived ldr;
	cout << "객체생성 후..... " << endl;
	ldr.ComplexFunc();
	return 0;
}