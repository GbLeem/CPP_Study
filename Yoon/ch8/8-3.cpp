//���� �Ҹ��ڿ� �������� ���� ���ɼ�


//���� �Ҹ���
#include<iostream>
using namespace std;

//class First
//{
//public:
//	virtual ~First()
//	{
//		cout << "first" << endl;
//	}
//};
//
//class Second :public First
//{
//public:
//	virtual ~Second()
//	{
//		cout << "Second" << endl;
//	}
//};
//
//class Third :public Second
//{
//public:
//	virtual ~Third()
//	{
//		cout << "Third" << endl;
//	}
//};
//
//int main()
//{
//	First* ptr = new Third;
//	delete ptr;
//
//	//Third Second First�� ��µȴ�.
//}


//���� ������
//C++���� AAA�� �����ڴ� AAA��ü �Ǵ� AAA�� ��.���������� ����ϴ� ��� ��ü�� ������ �� �ִ�.

class First
{
public:
	void FirstFunc()
	{
		cout << "FirstFunc()" << endl;
	}
	virtual void SimpleFunc()
	{
		cout << "First's SimpleFunc()" << endl;
	}
};

class Second : public First
{
public:
	void SecondFunc()
	{
		cout << "SecondFunc()" << endl;
	}
	virtual void SimpleFunc()
	{
		cout << "Second's SimpleFunc()" << endl;
	}
};

class Third:public Second
{
public:
	void ThirdFunc()
	{
		cout << "ThirdFunc()" << endl;
	}
	virtual void SimpleFunc()
	{
		cout << "Third's SimpleFunc()" << endl;
	}
};

int main()
{
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& ref = obj;
	ref.FirstFunc();
	ref.SecondFunc();
	ref.SimpleFunc(); //SimpleFunc�� �����Լ��̹Ƿ� ������ ����Ű�� ��� ���� ��� ���

	First& ref2 = obj; //ref2�� First �ڷ����̹Ƿ� First�� ���ǵ� �Լ��� ȣ�� ����������.
	ref2.FirstFunc();
	ref2.SimpleFunc();

	return 0;
}
