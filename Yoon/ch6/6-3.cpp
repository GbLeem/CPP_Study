//static 

//c 언어
//전역변수로 선언된 static : 선언된 파일 내에서만 참조 허용
//함수 내에서 선언된 static : 한번만 초기화, 함수를 빠져나가도 소멸 x

//c++
//static 멤버변수 : 클래스당 하나만 생성
//static 멤버변수는 생성자에서 초기화하는 것 x

//static 멤버함수 -> 객체의 멤버로 존재하지 않는다.
//static 멤버함수 내에서는 static 멤버변수와 static 멤버함수만 호출이 가능하다.

//const static

//mutable keyword
//const 함수 내에서의 값의 변경을 예외적으로 허용함 (많이 쓰는거 아님)
#include<iostream>
using namespace std;

class Widget
{
private:
	int num1;
	mutable int num2;
public:
	Widget(int n1,int n2)
		:num1(n1)
		,num2(n2)
	{}
	void ShowData() const
	{
		cout << num1 << ", " << num2 << endl;
	}
	void CopyToNum2() const //mutable로 인해 const 함수 안에서 값의 변경이 일어남
	{
		num2 = num1;
	}
};

int main()
{
	Widget w(1, 2);
	w.ShowData();
	w.CopyToNum2();
	w.ShowData();
	return 0;
}