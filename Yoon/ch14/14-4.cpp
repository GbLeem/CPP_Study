// 템플릿과 static


#include<iostream>
using namespace std;

template<typename T>
void ShowStaticValue(void)
{
	static T num = 0;
	num += 1;
	cout << num << " ";
}

int main()
{
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	cout << endl;
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	cout << endl;
	ShowStaticValue<double>();
	ShowStaticValue<double>();
	ShowStaticValue<double>();
	cout << endl;

	//1 2 3 이 세번 출력된다. -> 각 템플릿의 타입당 static 변수가 유지되는 것을 알 수 있음
	return 0;
}