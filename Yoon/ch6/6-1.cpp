//const와 관련한 이야기

//const를 붙인 객체의 경우 객체의 const 멤버 함수만 호출 가능하다.
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
	Widget& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void showData() const
	{
		cout << "num : " << num << endl;
	}
};

int main()
{
	const Widget obj(10);
	//obj.AddNum(20); 불가능
	obj.showData(); //가능
	return 0;
}

//const 여부로 오버로딩 가능