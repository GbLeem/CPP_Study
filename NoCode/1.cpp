//       <Variables in memory>

//stack memory
//ó�� �����Ǵ� ������ �޸� ������ ���� ���� (���� �ּҰ�)�� �����Ѵ�.
//������ �Ʒ��� ������ ���δ�.

#include<iostream>

int main()
{
	int a = 0;
	double b = 2.5;
	int c = 3;

	std::cout << "a : " << (long)&a << std::endl;
	std::cout << "b : " << (long)&b << std::endl;
	std::cout << "c : " << (long)&c << std::endl;
}