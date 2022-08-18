//클래스와 함수에 대한 friend 선언

//A 클래스가 B 클래스를 대상으로 friend 선언을 하면, B클래스는 A 클래스의 private 멤버에 접근 가능
//A가 B를 친구로 생각하고 다 보여줌
#include<iostream>
using namespace std;

class B;

class A
{
private:
	int secret;
	friend class B; //B 클래스를 friend로 선언
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