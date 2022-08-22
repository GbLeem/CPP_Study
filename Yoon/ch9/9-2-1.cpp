//다중상속에 대한 이해


#include<iostream>
using namespace std;

class BaseOne
{
public:
	void SimpleFunc()
	{
		cout << "BaseOne" << endl;
	}
};

class BaseTwo
{
public:
	void SimpleFunc()
	{
		cout << "BaseTwo" << endl;
	}
};

class MultiDerived :public BaseOne, protected BaseTwo
{
public:
	void ComplexFunc() //다중상속의 모호성과 해결방법
	{
		BaseOne::SimpleFunc();
		BaseTwo::SimpleFunc();
	}
};

int main()
{
	MultiDerived mdr;
	mdr.ComplexFunc();
	return 0;
}