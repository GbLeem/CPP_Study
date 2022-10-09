#include<iostream>
#include<thread>
#include<vector>

//std::thread 사용할 때 함수를 같이 넘겨주어야 의미있는 thread가 생성된다.
//copy 불가능, move 가능

void fn()
{
	std::cout << "fn: " << std::this_thread::get_id() <<std::endl;
}

//constructor 예시
//int main()
//{
//	std::thread t1(fn);
//	//std::thread t2{ t1 }; copy constructor -> 컴파일 에러(정의에서 삭제되어있기 때문에)
//	std::thread t2{ std::move(t1) }; //move constructor 사용해야함
//	t2.join();
//}

//destructor 예시
//int main()
//{
//	std::thread t1(fn);
//	t1.join();
//	std::cout << "joinable: " << t1.joinable() << std::endl; // joinable: 1출력
//	//만약 t1을 join하지 않았다면, terminate() 호출되어서 종료된다.
//}


//thread 의 join() 함수
//thread의 detach() 함수
void threadCaller()
{
	std::thread t1(fn);
	t1.detach(); //실제 상황에서는 쓰지말자 -> main thread와 연결을 끊은 이후 다시 main thread와 연결하기가 어려움
				 //-> global scope를 이용하는 것이 좋다.
}

//int main()
//{
//	threadCaller();
//	std::this_thread::sleep_for(std::chrono::seconds(3));
//}


//heap 공간에서 thread 사용
int main()
{
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; ++i)
	{
		threads.emplace_back(std::thread(fn));
	}
	for (auto& thread : threads)
	{
		thread.join();
	}
}