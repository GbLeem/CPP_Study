//				<exception>

//c���� exception�� ���� -> return �̳� &arg�� �ذ�
//c++���� std::optional, std::variant, std::tuple/pair ������ �ذ� + exception
//std::exception�� parent�� �پ��� ������ ����ó���� ����

//try
//catch
//throw

#include<iostream>
#include<exception>

int divide(int a, int b)
{
	if (b == 0)
	{
		//throw std::exception(); //r value�� ������
		throw std::runtime_error("divide by 0");
	}
	return a / b;
}

int main()
{
	try
	{
		std::cout << divide(10, 0) << std::endl;
	}
	catch (const std::exception& e) //reference�� �ޱ�
	{
		std::cout << e.what() << std::endl;
		std::cout << "exception catched" << std::endl;
	}
}