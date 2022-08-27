//				<Preprocessor>

// #include, #define, #ifdef, #pragma once ...

//preprocessor 예시
//1. conditionally
//2. replace


//#define MAX_UINT16 65535 //modern c++ 에서는 #define으로 정의하는것 bad
//#define MAX(a,b) (((a)>(b))?(a):(b)) STL 쓰는것이 better
//#define ABCD 2 constexpr 쓰기

#include<iostream>
#include<limits>
#include<algorithm>

constexpr int ABCD = 2;

int main()
{
	std::cout << std::numeric_limits<uint16_t>::max() << std::endl;
	//std::cout << MAX_UINT16 << std::endl; 위의 코드로 대체하기!
	
	//std::cout << MAX(10, 100) << std::endl;
	std::cout << std::max(10, 100) << std::endl;

//#ifdef ABCD
//	std::cout << "1: yes\n";
//#else
//	std::cout << "1: no\n"; //의미 없음
//#endif
//
//#ifndef ABCD
//	std::cout << "2: no1\n"; //의미 없음
//#elif ABCD == 2
//	std::cout << "2: yes\n";
//#else
//	std::cout << "2: no2\n"; //의미 없음
//#endif
	if constexpr (ABCD)
		std::cout << "1. yes\n";
	else
		std::cout << "1. no\n";

	//pre define macro 는 사용할 때가 있을수도 있다.
	std::cout << __FILE__ << std::endl;
	std::cout << __DATE__ << std::endl;
	std::cout << __TIME__ << std::endl;


}