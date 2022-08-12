#include<iostream>

int main()
{
	const int num = 12;
	const int* ptr = &num;
	const int* (&ref) = ptr;

	std::cout << "by ptr : " << *ptr << std::endl;
	std::cout << "by ref : " << *ref << std::endl;
}