//				<union>

//for memory saving
//그림 참고

#include<iostream>

struct S //4+(4)+8 = 16 (4) : memory padding
{
	int i;
	double d;
};

union  U //8
{
	int i; //4
	double d; //8
};

int main()
{
	std::cout << sizeof(S) << std::endl;
	std::cout << sizeof(U) << std::endl;

	U u;
	u.i = 10;
	std::cout << u.i << std::endl; //10

	u.d = 0.3;
	std::cout << u.i << std::endl; //전혀 상관없는 숫자 나옴 -> undefined behavior!!
	std::cout << u.d << std::endl; //0.3

	//union 안에 string이나 vector가 있는 경우 desructor를 호출해 준후 다른 type을 할당하지 않으면 오류가 발생
	//-> type tracking을 사용
	//-> std::variant (C++17)로 안전하게 사용 가능 
	return 0;
}