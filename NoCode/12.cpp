//				<Preprocessor>

// #include, #define, #ifdef, #pragma once ...

//preprocessor ����
//1. conditionally
//2. replace


//#define MAX_UINT16 65535 //modern c++ ������ #define���� �����ϴ°� bad
//#define MAX(a,b) (((a)>(b))?(a):(b)) STL ���°��� better
//#define ABCD 2 constexpr ����

#include<iostream>
#include<limits>
#include<algorithm>

constexpr int ABCD = 2;

int main()
{
	std::cout << std::numeric_limits<uint16_t>::max() << std::endl;
	//std::cout << MAX_UINT16 << std::endl; ���� �ڵ�� ��ü�ϱ�!
	
	//std::cout << MAX(10, 100) << std::endl;
	std::cout << std::max(10, 100) << std::endl;

//#ifdef ABCD
//	std::cout << "1: yes\n";
//#else
//	std::cout << "1: no\n"; //�ǹ� ����
//#endif
//
//#ifndef ABCD
//	std::cout << "2: no1\n"; //�ǹ� ����
//#elif ABCD == 2
//	std::cout << "2: yes\n";
//#else
//	std::cout << "2: no2\n"; //�ǹ� ����
//#endif
	if constexpr (ABCD)
		std::cout << "1. yes\n";
	else
		std::cout << "1. no\n";

	//pre define macro �� ����� ���� �������� �ִ�.
	std::cout << __FILE__ << std::endl;
	std::cout << __DATE__ << std::endl;
	std::cout << __TIME__ << std::endl;


}