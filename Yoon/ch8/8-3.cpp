//가상 소멸자와 참조자의 참조 가능성


//가상 소멸자
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
//	//Third Second First가 출력된다.
//}


//가상 참조자
//C++에서 AAA형 참조자는 AAA객체 또는 AAA를 직.간접적으로 상속하는 모든 객체를 참조할 수 있다.

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
	ref.SimpleFunc(); //SimpleFunc는 가상함수이므로 실제로 가리키는 대상에 대한 결과 출력

	First& ref2 = obj; //ref2는 First 자료형이므로 First에 정의된 함수만 호출 가능해진다.
	ref2.FirstFunc();
	ref2.SimpleFunc();

	return 0;
}
