#include<iostream>
#include<thread>
#include<string>

//return ���� �ڵ鸵 �ϱ� 
//std::async or reference arguemnt�� ���� �ޱ�

int fn(int & ret) //reference���� �����ϰ� �������� future�� promise���
{
	ret = 3;
	return 3;
}

int fn2()
{
	return 3;

}

int fn3()
{
	throw std::runtime_error("error");
}
int main()
{
	//<eturn value �ڵ鸵 ���� 1, 2>
	//int num = 0;
	////std::thread t1(fn, std::ref(num)); -> reference argument�� �ޱ�
	//std::thread t1([&num]() //trick ����ϴ� �� -> lambda function���� �ޱ�
	//	{
	//		num = fn2();
	//	});
	//t1.join();

	//std::cout << "retVal" << num << std::endl;


	//<���� ������ �� ����>
	// exception�� �ٸ� thread���� ������ ���� main thread���� ���� ����� ���� -> terminate ȣ��
	try 
	{
		std::thread t1(fn3);
		t1.join();
	}
	catch (...)
	{
		std::cout << "catched" << std::endl;
	}
}