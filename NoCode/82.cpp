//				<exception>

//c에는 exception이 없다 -> return 이나 &arg로 해결
//c++에는 std::optional, std::variant, std::tuple/pair 등으로 해결 + exception
//std::exception을 parent로 다양한 종류의 예외처리가 존재

//try
//catch
//throw

#include<iostream>
#include<exception>

int divide(int a, int b)
{
	if (b == 0)
	{
		//throw std::exception(); //r value로 던지기
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
	catch (const std::exception& e) //reference로 받기
	{
		std::cout << e.what() << std::endl;
		std::cout << "exception catched" << std::endl;
	}
}