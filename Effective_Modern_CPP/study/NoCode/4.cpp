//			<Stack Frame>

#include<iostream>

//void foo()
//{
//	int a;
//	int b;
//}
//
//void bar()
//{
//	Cat cat;
//	Dog dog;
//}
//
//int main()
//{
//	int a;
//	double b;
//
//	foo();
//	bar();
//
//	return 0;
//}

//�޸� ������ ���� ������ ���̴� ���� �ƴ϶� stack frame������
//function call�� ���� ���̰� �����ȴ�.

//�޸𸮰� ���̴� �߰��� argument�� return address ���� ���̻��̿� ����.


class Cat
{
public:
	Cat()
	{
		m_age = 1;
	}
	~Cat();
	void AddAge(int arg)
	{
		m_age += arg;
	}
private:
	int m_age;
};

int main()
{
	Cat cat;
	cat.AddAge(10);

	return 0;
}


//�� ó������(������)
//1. main ���� (4byte)
//2. Cat�� ������->������ �����鼭 ����
//3. AddAge() ���� -> return instructor address / argument /this 
				// �� ������ stack frame 
				// this : member variable�� �ٷ�� ���� �ּ�
//4. AddAge() �����鼭 ����
//5. Cat �Ҹ��� ����-> ����
//6. main ����

