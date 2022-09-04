//템플릿에 대한 이해와 함수 템플릿

#include<iostream>
using namespace std;

template<typename T> 
T Add(T a, T b)  //함수 템플릿
{
	return a + b;
}
//컴파일 하는시간이 증가할 여지는 있다.

template<class T1, class T2>
void showData(double num)
{
	cout << (T1)num << ", " << (T2)num << endl;
}

int main()
{
	cout << Add<int>(1, 2) << endl; //템플릿 함수를 만들어서 계산 후 출력
	cout << Add(1.2, 2.2) << endl;

	showData<char, int>(65);
	showData<short, double>(65.1);
}

