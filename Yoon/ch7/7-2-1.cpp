//상속

#include<iostream>
using namespace std;

class Base
{
private:
	int baseNum;
public:
	Base()
		:baseNum(20)
	{
		cout << "Base()" << endl;
	}
	Base(int n)
		:baseNum(n)
	{
		cout << "Base(int n)" << endl;
	}
	void ShowBaseData() const
	{
		cout << baseNum << endl;
	}
};

class Derived :public Base
{
private:
	int deriveNum;
public:
	Derived()
		:deriveNum(30)
	{
		cout << "Derived()" << endl;
	}
	Derived(int n)
		:deriveNum(n)
	{
		cout << "Derived(int n)" << endl;
	}
	Derived(int n1, int n2)
		:Base(n1)
		, deriveNum(n2)
	{
		cout << "Derived(int n1, int n2)" << endl;
	}
	void ShowDerivedData() const
	{
		ShowBaseData();
		cout << deriveNum << endl;
	}
};

int main()
{
	cout << "Case1....." << endl;
	Derived dr1;
	dr1.ShowDerivedData();
	cout << "-----------------" << endl;

	cout << "Case2....." << endl;
	Derived dr2(12);
	dr2.ShowDerivedData();
	cout << "-----------------" << endl;

	cout << "Case3....." << endl;
	Derived dr3(23, 24);
	dr3.ShowDerivedData();

	return 0;
}

//derived 객체 생성시 base 객체의 생성자가 호출된다.
//클래스의 멤버는 해당 클래스의 생성자를 통해 초기화해야 한다.

//소멸자는 derived 소멸자가 먼저 호출되고 이후에 base소멸자가 호출된다.