//       <Variables in memory>

//stack memory
//처음 생성되는 변수가 메모리 공간의 가장 위쪽 (높은 주소값)을 차지한다.
//위에서 아래로 변수가 쌓인다.

#include<iostream>

int main()
{
	int a = 0;
	double b = 2.5;
	int c = 3;

	std::cout << "a : " << (long)&a << std::endl;
	std::cout << "b : " << (long)&b << std::endl;
	std::cout << "c : " << (long)&c << std::endl;
}