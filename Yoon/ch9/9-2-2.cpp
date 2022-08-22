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
	//LastDerived Ŭ������ Base Ŭ������ ���������� 2�� ����Ѵ�
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
		SimpleFunc(); //���� ����� ���� �ش� �κп��� Base�� �Ѱ��� ����
					  //���� ����� �ƴϾ��ٸ�... MiddleDerivedTwo::SimpleFunc() �̷� ������ ��� �Ѵ�.
	}
};

int main()
{
	cout << "��ü���� ��..... " << endl;
	LastDerived ldr;
	cout << "��ü���� ��..... " << endl;
	ldr.ComplexFunc();
	return 0;
}