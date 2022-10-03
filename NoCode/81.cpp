//				<type punning>


//어떤 타입을 나타내는 메모리 공간을 다른 타입으로 읽기
//ex) float로 쓰고  unsigned int로 읽는 등의 동작

#include<iostream>
#include<bit>
#include<cstdint>
#include<cstring>

bool isNeg(float x)
{
	unsigned int temp;
	std::memcpy(&temp, &x, sizeof(x)); //실제 memcpy는 안하고 optimization해준다.
	return temp & 0x80000000;
}

//bit_cast : C++20
bool isNeg2(float x)
{
	return std::_Bit_cast<uint32_t>(x) & 0x80000000;
}

int main()
{
	std::cout << isNeg2(-1.0f) << std::endl; //1
	std::cout << isNeg2(1.0f) << std::endl; //0
}