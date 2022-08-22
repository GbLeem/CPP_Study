#include<iostream>
using namespace std;

class First
{
public:
	/*virtual*/ void MyFunc() //First�� virtual �� �Ǹ�, First�� ����ϴ� Second�� Third ��� virtual �� �ȴ�.
	{
		cout << "First" << endl;
	}
};

class Second :public First
{
public:
	/*virtual*/ void MyFunc()
	{
		cout << "Second" << endl;
	}
};

class Third :public Second
{
public:
	/*virtual*/ void MyFunc()
	{
		cout << "Third" << endl;
	}
};

int main()
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc(); //virtual �� ������ sptr�� First�� Second�� �������̵� ����� ���� -> �������̵� �� Second�� �Լ� ȣ�� (�ڷ����� ���)
					//virtual �� ������ ������ ������ ������ ����Ű�� ��ü�� �����ؼ� ����� ����Ѵ�.
	tptr->MyFunc(); 

	//virtual �� ���ٸ� First Second Third�� ���
	//virtual �� �ִٸ� �� ��� ��� Third�� ��� 
	return 0;
}