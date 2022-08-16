//this 포인터

#include<iostream>
#include<cstring>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n)
		:num(n)
	{
		cout << "num = " << num << ", ";
		cout << "address = " << this << endl;
	}
	void ShowSimpleData()
	{
		cout << num << endl;
	}
	SoSimple* GetThisPointer()
	{
		return this;
	}
};

int main()
{
	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
}

//this는 주소값과 자료형이 정해져있지 않은 포인터

//멤버 변수와 지역 변수 혼돈 막아줌
class Widget
{
private:
	int num;

public:
	void ThisFunc(int num)
	{
		this->num = 207; //멤버 변수값 변경
		num = 105;//매개변수값 변경
	}
};