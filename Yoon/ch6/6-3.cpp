//static 

//c ���
//���������� ����� static : ����� ���� �������� ���� ���
//�Լ� ������ ����� static : �ѹ��� �ʱ�ȭ, �Լ��� ���������� �Ҹ� x

//c++
//static ������� : Ŭ������ �ϳ��� ����
//static ��������� �����ڿ��� �ʱ�ȭ�ϴ� �� x

//static ����Լ� -> ��ü�� ����� �������� �ʴ´�.
//static ����Լ� �������� static ��������� static ����Լ��� ȣ���� �����ϴ�.

//const static

//mutable keyword
//const �Լ� �������� ���� ������ ���������� ����� (���� ���°� �ƴ�)
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
	void CopyToNum2() const //mutable�� ���� const �Լ� �ȿ��� ���� ������ �Ͼ
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