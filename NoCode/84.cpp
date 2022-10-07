//					<Safety Unwinding>

//exception safety guarantee�� ���Ѽ� resource leak�� ����

//<exception safety guarantee>
//1.basic : resource leak x, state change o
//2.strong : resource leak x, state change x
//3. no-throw : exception�� �������� �ʴ� �Լ�
//<-> no exception safety

//����)
//�Ҹ���, swap, move, default constructor�� ���� ������ �ϸ� �ȵȴ�!! -> noexcept �ٿ��ֱ�

#include<iostream>
#include<exception>

int g = 0;

class Cat
{

};

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
	//Cat* cp = new Cat();
	std::unique_ptr<Cat> cp = std::make_unique<Cat>(); //exception safety�� ���� RAII
	divide(10, 0);
	//delete cp;
}

void f2() //basic : global ������ �����ϴ� state change�� �߻�(resource leak�� ����)
{
	g = 1;
	divide(10, 0);
}

void f3() //strong : global ���� �״�� -> exception�� ������ �� �ִ� �Լ��� �׻� �Լ� �տ� ��ġ�ؾ��Ѵ�.
		  //						   -> ���� �Լ��� ���� �� ���� �ִٸ�, local ������ ��Ƽ� ����
{
	divide(10, 0);
	int a = divide(10, 0); //local ������ ��Ƽ� ����
	g = 1;
}

void f4() //no-throw -> �ش� �Լ����� ���ܰ� �������� stack unwinding�� ����Ǵ� ������ ����
		  // try catch�� ���� �ڽź��� ���� �ܰ�� ���ܰ� �������� ���� ����
{
	try
	{
		int a = divide(10, 0);
		g = a;
	}
	catch(const std::exception & e)
	{ }
}

int main()
{
	std::cout << "g: " << g << std::endl; //0 
	try
	{
		//f2();
		//f3();
		f4();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "g: " << g << std::endl; //1, 0, 0

	return 0;
}