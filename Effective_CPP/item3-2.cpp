#include<iostream>

int main()
{
	int num1 = 10;
	int num2 = 100;
	//-------------------------------------------
	int* p1 = &num1;		  // non-const pointer 
							  // non-const data
	//-------------------------------------------
	const int* p2 = &num1;    //non-const pointer
							  //const data
	//*p2 = 100; //�Ұ���
	p2 = &num2;  //����
	//-------------------------------------------
	int* const p3 = &num1;    //const pointer
							  //non-const data
	//p3 = &num2; //�Ұ���
	*p3 = 100;    //����
	//-------------------------------------------
}