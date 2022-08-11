//1.
int main()
{
	int val1 = 10;
	int val2 = 20;
	int val3 = 30;
	const int num = 10; //값이 변할 수 없는 상수 num
	const int* ptr1 = &val1; //val1의 값 변경 불가
	int* const ptr2 = &val2; //ptr2가 가리키는 값 변경 불가
	const int* const ptr3 = &val3;//ptr3가 가리키는 값 변경 불가, val3값 변경 x

	ptr1 = ptr2;
	//ptr2 = ptr1; 오류
	//*ptr1 = 20; 오류
	*ptr2 = 10;
}

//2.
//메모리 영역
//데이터 : 전역변수
//힙 : 동적으로 할당
//스택 : 지역변수 매개변수

//3.
void swap(int a, int b)//call by value
{
	int temp;
	temp = b;
	b = a;
	a = temp;
}

void swap(int* a, int* b) //call by reference
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}