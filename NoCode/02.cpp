//				<Variale Types1>

#include<iostream>
#include<cstdint>
#include<array>

int main()
{
	static_assert(sizeof(int) == 4, "int is 4 bytes");
	//static_assert() -> int가 4바이트 인것 감지

	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(int8_t) << std::endl; // 비트 단위 인티저
	std::cout << sizeof(uint32_t) << std::endl;


	int a[10]; //c style array
	std::cout << sizeof(a) << std::endl;

	std::array<int, 5> ia; //c++ style array -> better
	std::cout << sizeof(ia) << std::endl;


	//포인터 변수의 경우 64비트 기준 64비트 크기를 차지한다.
	uint32_t i32 = 0;
	uint32_t* uint32Ptr = &i32;

	uint64_t ui8;
	uint64_t* ui64Ptr = &ui8;

	std::cout << sizeof(uint32Ptr) << std::endl;
	std::cout << sizeof(ui64Ptr) << std::endl;
}