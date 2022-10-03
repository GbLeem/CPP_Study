//				<std::variant>

// union을 안전하게 쓰는 방식
//안전해진 union : type traking 포함하여 overhead가 존재하기는 하다.

#include<iostream>
#include<variant>
#include<vector>

struct S 
{
	int i;
	double d;
	float f;
};

union  U 
{
	int i; 
	double d; 
	float f;
};

int main()
{
	std::variant<int, double,float> V;
	std::cout << sizeof(S) << std::endl; //24
	std::cout << sizeof(U) << std::endl; //8
	std::cout << sizeof(V) << std::endl; //16

	std::variant<std::string, std::vector<int>> sv;
	sv = std::string("good");

	std::cout << std::get<std::string>(sv) << std::endl; //생성자나 소멸자 사용안해도 스스로 관리해줌

	sv = std::vector{ 1,2,3 };

	return 0;
}

//이전에는 tuple 이나 pair로 구현했지만 variant로 구현하면 int와 error_code가 같은 메모리공간을 공유하면서
// 메모리 절약이 가능하다.
//std::variant<int, error_code> divide(int a, int b)
