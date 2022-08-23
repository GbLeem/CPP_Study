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
	std::cout << sizeof(long) << std::endl; //4����Ʈ
	std::cout << sizeof(ST) << std::endl; //10 ����Ʈ �ƴϰ� 12 ����Ʈ
										  //-> �޸� �е�

	std::cout << sizeof(Cat) << std::endl; //8byte
										   //�Լ��� ���� ũ�� ���� x

	Cat cat1;
	Cat cat2;
	Cat* catptr = &cat1;
	std::cout << sizeof(catptr) << std::endl; //8byte

	return 0;
}