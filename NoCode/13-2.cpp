
//���� ����
//static int a = 100; //�ٸ� ���Ͽ��� ã�� ���ϰ� �ϱ�

//�Լ� ����
#include<iostream>

static void bar()
{
	std::cout << "bar" << std::endl;
}
void foo()
{
	std::cout << "foo" << std::endl;
	bar();
}
