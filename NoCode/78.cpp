//				<union>

//for memory saving
//�׸� ����

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
	std::cout << u.i << std::endl; //���� ������� ���� ���� -> undefined behavior!!
	std::cout << u.d << std::endl; //0.3

	//union �ȿ� string�̳� vector�� �ִ� ��� desructor�� ȣ���� ���� �ٸ� type�� �Ҵ����� ������ ������ �߻�
	//-> type tracking�� ���
	//-> std::variant (C++17)�� �����ϰ� ��� ���� 
	return 0;
}