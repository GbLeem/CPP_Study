#include<iostream>
using namespace std;

class First
{
public:
	/*virtual*/ void MyFunc() //First가 virtual 이 되면, First를 상속하는 Second와 Third 모두 virtual 이 된다.
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
	sptr->MyFunc(); //virtual 이 없을때 sptr은 First와 Second가 오버라이딩 관계로 존재 -> 오버라이딩 된 Second쪽 함수 호출 (자료형을 기반)
					//virtual 이 있을때 포인터 변수가 실제로 가리키는 객체를 참조해서 결과를 출력한다.
	tptr->MyFunc(); 

	//virtual 이 없다면 First Second Third가 출력
	//virtual 이 있다면 세 경우 모두 Third가 출력 
	return 0;
}