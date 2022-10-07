//					<Safety Unwinding>

//exception safety guarantee를 지켜서 resource leak을 막자

//<exception safety guarantee>
//1.basic : resource leak x, state change o
//2.strong : resource leak x, state change x
//3. no-throw : exception이 던져지지 않는 함수
//<-> no exception safety

//참고)
//소멸자, swap, move, default constructor는 예외 던지기 하면 안된다!! -> noexcept 붙여주기

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
	std::unique_ptr<Cat> cp = std::make_unique<Cat>(); //exception safety를 위해 RAII
	divide(10, 0);
	//delete cp;
}

void f2() //basic : global 변수가 증가하는 state change가 발생(resource leak은 없다)
{
	g = 1;
	divide(10, 0);
}

void f3() //strong : global 변수 그대로 -> exception이 던져질 수 있는 함수는 항상 함수 앞에 배치해야한다.
		  //						   -> 만약 함수의 값을 쓸 일이 있다면, local 변수에 담아서 쓰기
{
	divide(10, 0);
	int a = divide(10, 0); //local 변수에 담아서 쓰기
	g = 1;
}

void f4() //no-throw -> 해당 함수에서 예외가 던져저서 stack unwinding이 진행되는 과정을 막음
		  // try catch를 통해 자신보다 상위 단계로 예외가 던져지는 것을 방지
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