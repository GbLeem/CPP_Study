//Ŭ������ �Լ��� ���� friend ����

//A Ŭ������ B Ŭ������ ������� friend ������ �ϸ�, BŬ������ A Ŭ������ private ����� ���� ����
//A�� B�� ģ���� �����ϰ� �� ������
#include<iostream>
using namespace std;

class B;

class A
{
private:
	int secret;
	friend class B; //B Ŭ������ friend�� ����
public:
	A(int num)
		:secret(num)
	{

	}

	void add(A& a,int num);
};

class B
{
private:
	int secret;

public:
	B(int num)
		:secret(num)
	{}
	void showA(const A& a)
	{
		cout << a.secret << endl;
	}
	void showB()
	{
		cout << secret << endl;
	}

	friend void A::add(A& a, int num);
};

void A::add(A& a, int num)
{
	a.secret += num;
}

int main()
{
	B b(0);
	A a(10);

	a.add(a, 20);
	b.showA(a);
}