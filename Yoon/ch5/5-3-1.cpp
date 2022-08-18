//복사 생성자의 호출시점

//1. 기존에 생성된 객체를 이용해서 새로운 객체를 초기화하는 경우
//2. call-by-value방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
//3. 객체를 반환하되, 참조형으로 반환하지 않는 경우


//함수가 값을 반환하면 별도의 메모리 공간이 할당되고, 이 공간에 반환 값이 저장된다.(반환 값으로 초기화)

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
	cout << "함수 호출 전" << endl;
	FuncObj(obj); //ob 객체의 복사 생성자가 호출 obj객체가 인자로 들어간다.
	cout << "함수 호출 후" << endl;
	return 0;
}
