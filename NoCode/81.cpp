//				<type punning>


//� Ÿ���� ��Ÿ���� �޸� ������ �ٸ� Ÿ������ �б�
//ex) float�� ����  unsigned int�� �д� ���� ����

#include<iostream>
#include<bit>
#include<cstdint>
#include<cstring>

bool isNeg(float x)
{
	unsigned int temp;
	std::memcpy(&temp, &x, sizeof(x)); //���� memcpy�� ���ϰ� optimization���ش�.
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