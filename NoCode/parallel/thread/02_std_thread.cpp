#include<iostream>
#include<thread>
#include<vector>

//std::thread ����� �� �Լ��� ���� �Ѱ��־�� �ǹ��ִ� thread�� �����ȴ�.
//copy �Ұ���, move ����

void fn()
{
	std::cout << "fn: " << std::this_thread::get_id() <<std::endl;
}

//constructor ����
//int main()
//{
//	std::thread t1(fn);
//	//std::thread t2{ t1 }; copy constructor -> ������ ����(���ǿ��� �����Ǿ��ֱ� ������)
//	std::thread t2{ std::move(t1) }; //move constructor ����ؾ���
//	t2.join();
//}

//destructor ����
//int main()
//{
//	std::thread t1(fn);
//	t1.join();
//	std::cout << "joinable: " << t1.joinable() << std::endl; // joinable: 1���
//	//���� t1�� join���� �ʾҴٸ�, terminate() ȣ��Ǿ ����ȴ�.
//}


//thread �� join() �Լ�
//thread�� detach() �Լ�
void threadCaller()
{
	std::thread t1(fn);
	t1.detach(); //���� ��Ȳ������ �������� -> main thread�� ������ ���� ���� �ٽ� main thread�� �����ϱⰡ �����
				 //-> global scope�� �̿��ϴ� ���� ����.
}

//int main()
//{
//	threadCaller();
//	std::this_thread::sleep_for(std::chrono::seconds(3));
//}


//heap �������� thread ���
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