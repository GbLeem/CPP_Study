//				<stack unwinding>

//�׸� ����

//stack unwinding : throw�� �Ǿ��� �� try catch�� ���ö� ���� stack frame�� pop ��Ű�� ����
// main()�� pop �ɶ� ���� try catch��  ������, std::terminate() ȣ��ȴ�.
// -> �Ϲ����� path�ʹ� �ٸ� path�� ����
//performance�� ����
//����� �۵��ϴ� ��� : overhead x
//throw�� ȣ��� �� : overhead �߻� -> ��Ȳ�� ���� overhead�� ������ �ٸ���.(for ���ִ� ��� overhead ũ��)

//tip) RAII ���Ѽ� �����
#include<iostream>
#include<exception>

int divide(int a, int b)
{
	if (b == 0)
	{
		throw std::runtime_error("divide by 0");
	}
	return a / b;
}

void f()
{
	std::cout << divide(10, 0) << std::endl;
}

int main()
{
	try
	{
		f();
	}
	catch (const std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	}
}  