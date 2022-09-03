//				<Variale Types2>
#include<iostream>

struct ST
{
	long a; //4 byte
	int b;  //4 byte
	short c;//2 byte
};

class Cat
{
public:
	void printCat();

private:
	int age;	//4byte
	float weight;//4byte
};
int main()
{
	std::cout << sizeof(long) << std::endl; //4바이트
	std::cout << sizeof(ST) << std::endl; //10 바이트 아니고 12 바이트
										  //-> 메모리 패딩

	std::cout << sizeof(Cat) << std::endl; //8byte
										   //함수는 따로 크기 차지 x

	Cat cat1;
	Cat cat2;
	Cat* catptr = &cat1;
	std::cout << sizeof(catptr) << std::endl; //8byte

	return 0;
}