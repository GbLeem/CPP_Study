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

void test(Window w) //���� �ս�
{
	w.show();
}

void test2(const Window& w)//��� ��ü �����ڿ� ���� ����
{
	w.show();
}

int main()
{
	ScrollWindow sw;
	cout << "before call func" << endl;
	//test(sw); //show window -> ������ ���� ��� �߻�!
	test2(sw);  //show scroll
	cout << "after call func" << endl;
	return 0;
}