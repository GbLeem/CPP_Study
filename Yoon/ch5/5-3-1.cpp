//���� �������� ȣ�����

//1. ������ ������ ��ü�� �̿��ؼ� ���ο� ��ü�� �ʱ�ȭ�ϴ� ���
//2. call-by-value����� �Լ�ȣ�� �������� ��ü�� ���ڷ� �����ϴ� ���
//3. ��ü�� ��ȯ�ϵ�, ���������� ��ȯ���� �ʴ� ���


//�Լ��� ���� ��ȯ�ϸ� ������ �޸� ������ �Ҵ�ǰ�, �� ������ ��ȯ ���� ����ȴ�.(��ȯ ������ �ʱ�ȭ)

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
		cout << "call Widget copy " << endl;
	}
	void showData()
	{
		cout << "num : " << num << endl;
	}
};

void FuncObj(Widget ob)
{
	ob.showData();
}
int main()
{
	Widget obj(7);
	cout << "�Լ� ȣ�� ��" << endl;
	FuncObj(obj); //ob ��ü�� ���� �����ڰ� ȣ�� obj��ü�� ���ڷ� ����.
	cout << "�Լ� ȣ�� ��" << endl;
	return 0;
}
