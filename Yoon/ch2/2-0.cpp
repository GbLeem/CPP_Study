//1.
int main()
{
	int val1 = 10;
	int val2 = 20;
	int val3 = 30;
	const int num = 10; //���� ���� �� ���� ��� num
	const int* ptr1 = &val1; //val1�� �� ���� �Ұ�
	int* const ptr2 = &val2; //ptr2�� ����Ű�� �� ���� �Ұ�
	const int* const ptr3 = &val3;//ptr3�� ����Ű�� �� ���� �Ұ�, val3�� ���� x

	ptr1 = ptr2;
	//ptr2 = ptr1; ����
	//*ptr1 = 20; ����
	*ptr2 = 10;
}

//2.
//�޸� ����
//������ : ��������
//�� : �������� �Ҵ�
//���� : �������� �Ű�����

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