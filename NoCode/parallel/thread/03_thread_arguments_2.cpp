#include<iostream>
#include<thread>
#include<string>

//return 값을 핸들링 하기 
//std::async or reference arguemnt를 통해 받기

int fn(int & ret) //reference값을 안전하게 받으려면 future와 promise사용
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
	//<eturn value 핸들링 예시 1, 2>
	//int num = 0;
	////std::thread t1(fn, std::ref(num)); -> reference argument로 받기
	//std::thread t1([&num]() //trick 사용하는 것 -> lambda function으로 받기
	//	{
	//		num = fn2();
	//	});
	//t1.join();

	//std::cout << "retVal" << num << std::endl;


	//<예외 던져질 때 예시>
	// exception이 다른 thread에서 던져진 것을 main thread에서 잡을 방법은 없다 -> terminate 호출
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