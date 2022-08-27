
//변수 예시
//static int a = 100; //다른 파일에서 찾지 못하게 하기

//함수 예시
#include<iostream>

static void bar()
{
	std::cout << "bar" << std::endl;
}
void foo()
{
	std::cout << "foo" << std::endl;
	bar();
}
