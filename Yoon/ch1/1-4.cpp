//인라인 함수예시

#include<iostream>

inline int SQUARE(int x)
{
	return x * x;
}

int main()
{
	std::cout << SQUARE(5) << std::endl;
	std::cout << SQUARE(10) << std::endl;
}