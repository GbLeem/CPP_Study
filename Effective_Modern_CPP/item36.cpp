//ITEM 36 : Specify std::launch::async if asynchronicity is essential

//1. std::launch::async : f는 비동기적으로(다른 스레드에서) 실행
//2. std::launch::deferred :  f는 get이나 wait이 호출될 때 동기적으로 실행 가능

#include<future>
#include<iostream>
#include<thread>

using namespace std::literals;

void f()
{
	std::this_thread::sleep_for(1s);
}

int maib()
{
	auto fut = std::async(f);

	if (fut.wait_for(0s) == std::future_status::deferred)//지연되었을때
	{

	}
	else //지연되지 않았을 때
	{
		while (fut.wait_for(100ms) != std::future_status::ready)
		{

		}
	}
}

//기본 lauch policy와 std::async를 사용하는 것은 조건이 필요하다.
//강제로 비동기화 시키기 위해서는 std::launch::async를 사용하면 된다.
