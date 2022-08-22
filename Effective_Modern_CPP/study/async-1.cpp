//ó���� �����ɸ��� �Լ��� �ٸ� thread���� ó����Ű�� ���� thread�� ��� ���� �޾Ƽ� ó���ϱ⸦ ���Ѵ�.
//�̸� ���ؼ��� ó���ؾ� �� �ٸ� ���ǵ��� ���Ƽ� �����ϴ�.(thread, shared memory, condition variable ���)


//���� �ذ��ϱ� ���� task ��� ó���� �Ѵ�.

//											 <�񵿱� �Լ�>
#include<future>
#include<iostream>

//int fn()
//{
//	std::cout << "async fn" << std::endl;
//	return 42;
//}

//int main()
//{
//	std::future<int> fut = std::async(std::launch::async, fn); //async�� return ���� std::future
//	const int num = fut.get();
//
//	std::cout << "return num" << num << std::endl;
//}


//											<future�� promise>

//              channel
//future       <----------->     promise	
//main-thread
//

#include<future>
#include<iostream>

using namespace std::chrono_literals;
void fn(std::promise<int>prm)
{
	std::this_thread::sleep_for(2s); //2�ʵ��� fn thread�� ������Ŵ -> main thread�� ��ٷȴٰ� 42��� ���� ������ �����´�.
	
	try
	{
		throw std::runtime_error("error");
	}
	catch (...)
	{
		prm.set_exception(std::current_exception());// set_value�� ���� ��� x
	}
	//prm.set_value(42); 

	//set_exception
	//set_value_at_thread_exit �ش� �����忡�� ���� �ϴٰ� ���� �� ���� main thread�� ����
}

int main()
{
	std::promise<int>prms;
	std::future<int> fut = prms.get_future();

	std::thread t(fn, std::move(prms));//�ٸ� thread���� std::move�� ���� ���簡 �ȵǴ� prms�� �̵�������

	try
	{
		const int num = fut.get();
		std::cout << "num: " << num << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	//while (fut.wait_for(0.2s)!=std::future_status::ready) //main thread���� Ŀ�´����̼� ü�ο� ���� ������ ������ �ٸ� ������
	//{
	//	std::cout << "doing other work" << std::endl;
	//}
	//const int num = fut.get();
	//std::cout << "num: " << num << std::endl;
	t.join();
}


//											<Shared_future>
//future �� ���̴� ������ promise���� ���� ���� copy�� �ʿ��� �� ����� �� �ִ�.


