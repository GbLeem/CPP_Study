//			<Extern, Static>

//linking process�� ����
//extern : �ٱ��ʿ��� ��ũ ã��
//static : ���ʿ��� ��ũ ã��

#include<iostream>

//int a = 0;

extern void foo(); // �Լ��� �⺻������ extern Ű���� �پ��ִ�.
				   // extern �Ƚᵵ �� ����ȴ�.
int main()
{
	foo();
	//bar(); static �̶� ��� �Ұ���
	//std::cout << a << std::endl;
	return 0;
}

//Ŭ������ �Լ��� �ش� Ŭ������ ������Ʈ�� ������ ���� �Լ��� ���
//private �Լ��� ������ ���� static�� ���� free function���� �����
//���� ����. 


//extern "C"
//function overloading �� �Ҷ� name mangling ���� ����
//C���� overloading���� ������ extern "C"�� �����ϸ�
//name mangling �����ش�. -> C interface ó��