#include<string>
#include<iostream>
using namespace std;

class Window
{
public:
	Window()
	{
		cout << "create window" << endl;
	}
	virtual ~Window()
	{
		cout << "destroy window" << endl;
	}
	virtual void show() const
	{
		cout << "show Window" << endl;
	}
};

class ScrollWindow :public Window
{
public:
	ScrollWindow()
	{
		cout << "create ScrollWindow" << endl;
	}
	~ScrollWindow()
	{
		cout << "destroy ScrollWindow" << endl;
	}
	virtual void show() const
	{
		cout << "show Scroll" << endl;
	}
};

void test(Window w) //복사 손실
{
	w.show();
}

void test2(const Window& w)//상수 객체 참조자에 의한 전달
{
	w.show();
}

int main()
{
	ScrollWindow sw;
	cout << "before call func" << endl;
	//test(sw); //show window -> 원하지 않은 결과 발생!
	test2(sw);  //show scroll
	cout << "after call func" << endl;
	return 0;
}