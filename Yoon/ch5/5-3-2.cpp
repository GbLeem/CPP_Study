#include<iostream>
using namespace std;

class Widget
{
private:
	int num;
public:
	Widget(int n)
		:num(n)
	{}
	Widget(const Widget& copy)
		:num(copy.num)
	{
		cout << "called Widget copy" << endl;
	}
	~Widget()
	{
		cout << "destructor" << endl;
	}
	Widget& Addnum(int n)
	{
		num += n;
		return *this;
	}
	void showData()
	{
		cout << "num : " << num << endl;
	}
};

Widget FuncObj(Widget ob)
{
	cout << "return 이전" << endl;
	return ob; //임시 객체의 생성, 함수 호출 종료되면, ob객체가 소멸
}

int main()
{
	Widget obj(7);
	FuncObj(obj).Addnum(30).showData();
	obj.showData();
	cout << endl << endl;

	Widget(1000);//임시객체 생성 -> 다음 행으로 넘어가면서 바로 소멸된다.
	Widget w = Widget(20);
	const Widget& ref = Widget(10);//임시객체 생성시 임시객체의 참조값 반환 -> 참조자가 참조하는 임시객체는 바로 소멸x
	w.showData();
	
	return 0;
}

