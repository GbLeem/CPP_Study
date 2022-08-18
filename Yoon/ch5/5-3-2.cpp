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
	cout << "return ����" << endl;
	return ob; //�ӽ� ��ü�� ����, �Լ� ȣ�� ����Ǹ�, ob��ü�� �Ҹ�
}

int main()
{
	Widget obj(7);
	FuncObj(obj).Addnum(30).showData();
	obj.showData();
	cout << endl << endl;

	Widget(1000);//�ӽð�ü ���� -> ���� ������ �Ѿ�鼭 �ٷ� �Ҹ�ȴ�.
	Widget w = Widget(20);
	const Widget& ref = Widget(10);//�ӽð�ü ������ �ӽð�ü�� ������ ��ȯ -> �����ڰ� �����ϴ� �ӽð�ü�� �ٷ� �Ҹ�x
	w.showData();
	
	return 0;
}

