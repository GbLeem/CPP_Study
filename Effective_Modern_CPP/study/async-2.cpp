#include<future>
#include<iostream>
#include<thread>

void add1(std::promise<int>prms, int n) //���������� �ʴ�...
{
	prms.set_value(n + 1);
}

int Newadd1(int n) //async�� ���� �������� �ڵ��
{
	return n + 1;
}

int main()
{
	int num = 42;

	//std::promise<int> prms;
	//std::future<int> fut = prms.get_future();
	//std::jthread t(add1, std::move(prms), num);

	std::future<int>fut = std::async(Newadd1, num); //async�� ���
	int ret = fut.get();
	std::cout << "ret: " << ret << std::endl;
}


//async policy : argument�� ���� �Լ����� ��� ���ο� �����带 ���� ����
//���ο� �����带 ���� ����� ������� main �����忡�� get() �Լ��� ���´�.

//deferred policy : ���ο� ��������� x, ���� �����忡�� get()�� ���� �� ����Ѵ�. -> lazy evaluation


//								<async ������>
//std::async�� ���� ��� ����
//std::future<int>fut = std::async(std::launch::async,Newadd1, num); //launch policy ��� ����

//�� �����Ϸ� ���� �ٸ��� �۵� ex) msvc�� thread pool �̿�..

//future �� �Ҹ��ڸ� �������� -> block�� �Ǵ� ������ �ִ�.


//						<packaged_task>
// ����ڰ� ���ϴ� �����忡 task�� ������ �� �ִ�.