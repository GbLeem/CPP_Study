//���� �Լ�

#include<iostream>
using namespace std;

class Base
{
public:
	void BaseFunc()
	{
		cout << "Base" << endl;
	}
};

class Derived :public Base
{
public:
	void DerivedFunc()
	{
		cout << "Derived" << endl;
	}
};

int main()
{
	Base* bptr = new Derived();
	bptr->BaseFunc();//ok
	//bptr->DerivedFunc() : no  
	// --> C++ �����Ϸ��� ������ ������ ���ɼ� ���θ� **�������� �ڷ���**�� �������� �Ǵ��Ѵ�.(���� ����Ű�� ��ü�� �ڷ��� x)
	//Derived* dptr1 = bptr; no! base�� Deirved�� �������� ����
	Derived* dptr2 = new Derived();
	Base* bptr2 = dptr2; //ok --> dptr�� Derived Ŭ���� ������ ����(Base�� ����ϴ� ��ü�� ���̴�)
} 

//������ ���� �ش��ϴ� Ŭ������ ���ǵ� ������� ���� �����ϴ�.