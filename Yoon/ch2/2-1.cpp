#include<iostream>
//1.
//int plusInt(int& num)
//{
//	return num += 1;
//}
//
//int reverseInt(int& num)
//{
//	return -num;
//}
//
//int main()
//{
//	int num = 10;
//	std::cout << plusInt(num) << std::endl;
//	std::cout << reverseInt(num) << std::endl;
//}


//2.
//referenct 연산자는 변수에만 적용되기 때문


//3.
//void SwapPointer(const int* (&ptr1), const int* (&ptr2))
//{
//	const int* temp = ptr1;
//	ptr1 = ptr2;
//	ptr2 = temp;
//}
//
//int main()
//{
//	int num1 = 5;
//	const int* ptr1 = &num1;
//	int num2 = 10;
//	const int* ptr2 = &num2;
//
//	std::cout << ptr1 << ' ' << ptr2 << std::endl;
//	SwapPointer(ptr1, ptr2);
//	std::cout << ptr1 << ' ' << ptr2 << std::endl;
//}


//----------------------------------
//Reference 반환타입 함수
//지역변수를 참조형으로 반환하면 안된다..

int& RefReturn(int& ref)
{
	ref++;
	return ref;
}

int main()
{
	int num1 = 1;
	//int& num2 = RefReturn(num1); -> int num1 = 1, int& ref = num1, int& num2 = ref
	int num2 = RefReturn(num1);

	num1++;
	num2 += 100;
	std::cout << "num1: " << num1 << std::endl;
	std::cout << "num2: " << num2 << std::endl;
}