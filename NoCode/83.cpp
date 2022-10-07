//				<stack unwinding>

//그림 참조

//stack unwinding : throw가 되었을 때 try catch가 나올때 까지 stack frame을 pop 시키는 과정
// main()이 pop 될때 까지 try catch가  없으면, std::terminate() 호출된다.
// -> 일반적인 path와는 다른 path로 실행
//performance의 관점
//제대로 작동하는 방식 : overhead x
//throw가 호출될 때 : overhead 발생 -> 상황에 따라 overhead의 정도가 다르다.(for 문있는 경우 overhead 크다)

//tip) RAII 지켜서 만들기
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