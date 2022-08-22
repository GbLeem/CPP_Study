#include<future>
#include<iostream>
#include<thread>

void add1(std::promise<int>prms, int n) //직관적이지 않다...
{
	prms.set_value(n + 1);
}

int Newadd1(int n) //async를 통해 직관적인 코드로
{
	return n + 1;
}

int main()
{
	int num = 42;

	//std::promise<int> prms;
	//std::future<int> fut = prms.get_future();
	//std::jthread t(add1, std::move(prms), num);

	std::future<int>fut = std::async(Newadd1, num); //async를 사용
	int ret = fut.get();
	std::cout << "ret: " << ret << std::endl;
}


//async policy : argument로 들어온 함수같은 경우 새로운 스레드를 만들어서 실행
//새로운 스레드를 통해 얻어진 결과값은 main 스레드에서 get() 함수로 얻어온다.

//deferred policy : 새로운 스레드생성 x, 기존 스레드에서 get()이 사용될 때 계산한다. -> lazy evaluation


//								<async 주의점>
//std::async는 값이 비싼 연산
//std::future<int>fut = std::async(std::launch::async,Newadd1, num); //launch policy 사용 권장

//각 컴파일러 마다 다르게 작동 ex) msvc는 thread pool 이용..

//future 의 소멸자를 주의하자 -> block이 되는 조건이 있다.


//						<packaged_task>
// 사용자가 원하는 스레드에 task를 지정할 수 있다.