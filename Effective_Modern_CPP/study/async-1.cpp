//처리가 오래걸리는 함수를 다른 thread에서 처리시키고 원래 thread는 결과 값만 받아서 처리하기를 원한다.
//이를 위해서는 처리해야 할 다른 조건들이 많아서 복잡하다.(thread, shared memory, condition variable 등등)


//쉽게 해결하기 위해 task 기반 처리를 한다.

//											 <비동기 함수>
#include<future>
#include<iostream>

//int fn()
//{
//	std::cout << "async fn" << std::endl;
//	return 42;
//}

//int main()
//{
//	std::future<int> fut = std::async(std::launch::async, fn); //async의 return 값은 std::future
//	const int num = fut.get();
//
//	std::cout << "return num" << num << std::endl;
//}


//											<future와 promise>

//              channel
//future       <----------->     promise	
//main-thread
//

#include<future>
#include<iostream>

using namespace std::chrono_literals;
void fn(std::promise<int>prm)
{
	std::this_thread::sleep_for(2s); //2초동안 fn thread를 지연시킴 -> main thread는 기다렸다가 42라는 값이 들어오면 가져온다.
	
	try
	{
		throw std::runtime_error("error");
	}
	catch (...)
	{
		prm.set_exception(std::current_exception());// set_value랑 같이 사용 x
	}
	//prm.set_value(42); 

	//set_exception
	//set_value_at_thread_exit 해당 스레드에서 일을 하다가 끝날 때 값을 main thread로 전달
}

int main()
{
	std::promise<int>prms;
	std::future<int> fut = prms.get_future();

	std::thread t(fn, std::move(prms));//다른 thread생성 std::move를 통해 복사가 안되는 prms를 이동시켜줌

	try
	{
		const int num = fut.get();
		std::cout << "num: " << num << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	//while (fut.wait_for(0.2s)!=std::future_status::ready) //main thread에서 커뮤니케이션 체널에 값이 들어오기 전까지 다른 일을함
	//{
	//	std::cout << "doing other work" << std::endl;
	//}
	//const int num = fut.get();
	//std::cout << "num: " << num << std::endl;
	t.join();
}


//											<Shared_future>
//future 가 쓰이는 곳에서 promise에서 나온 값의 copy가 필요할 때 사용할 수 있다.


