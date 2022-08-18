//**임시객체 이해**


#include<iostream>
using namespace std;

class Widget
{
private:
	int num;

public:
	Widget(int n)
		:num(n)
	{
		cout << "New obj: " << this << endl;
	}
	Widget(const Widget& copy)
		:num(copy.num)
	{
		cout << "Copy obj: " << this << endl;
	}
	~Widget()
	{
		cout << "destruct obj : " << this << endl;
	}
};

Widget Func(Widget ob)
{
	cout << "Parameter address: " << &ob << endl;
	return ob;
}

int main()
{
	Widget obj(7);
	Func(obj);
	cout << endl;

	Widget w = Func(obj);
	cout << "return obj: " << &w << endl;
	return 0;
}