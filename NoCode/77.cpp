//				<enum class>

#include<iostream>
#include<string>

#define RED 1
#define BLUE 2 //��ũ�ε� ���׸� ������ų �� �ִ�.

enum class Color { red, blue, yellow };

//void buy(std::string color)
//{
//	if (color == "red")
//	{
//		//...
//	}
//	else if (color == "blue")
//	{
//		//...
//	}
//}

void buy(Color color) //better
{
	if (color == Color::red)
	{

	}
	else if (color == Color::blue)
	{

	}
}

int main()
{
	//buy("redd"); //��Ÿ�� ġ�ų� �ص� �������� �ȴ�.. -> ��ũ�η� �غ�?
	return 0;
}