//가상 함수

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
	// --> C++ 컴파일러는 포인터 연산의 가능성 여부를 **포인터의 자료형**을 기준으로 판단한다.(실제 가리키는 객체의 자료형 x)
	//Derived* dptr1 = bptr; no! base를 Deirved에 넣을수는 없다
	Derived* dptr2 = new Derived();
	Base* bptr2 = dptr2; //ok --> dptr은 Derived 클래스 포인터 변수(Base를 상속하는 객체일 것이다)
} 

//포인터 형에 해당하는 클래스에 정의된 멤버에만 접근 가능하다.