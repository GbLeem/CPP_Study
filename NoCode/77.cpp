//				<enum class>

#include<iostream>
#include<string>

#define RED 1
#define BLUE 2 //매크로도 버그를 생성시킬 수 있다.

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
	//buy("redd"); //오타를 치거나 해도 컴파일이 된다.. -> 매크로로 극복?
	return 0;
}