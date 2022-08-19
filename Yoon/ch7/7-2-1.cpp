//���

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

//derived ��ü ������ base ��ü�� �����ڰ� ȣ��ȴ�.
//Ŭ������ ����� �ش� Ŭ������ �����ڸ� ���� �ʱ�ȭ�ؾ� �Ѵ�.

//�Ҹ��ڴ� derived �Ҹ��ڰ� ���� ȣ��ǰ� ���Ŀ� base�Ҹ��ڰ� ȣ��ȴ�.