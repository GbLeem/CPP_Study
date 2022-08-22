//ITEM 36 : Specify std::launch::async if asynchronicity is essential

//1. std::launch::async : f�� �񵿱�������(�ٸ� �����忡��) ����
//2. std::launch::deferred :  f�� get�̳� wait�� ȣ��� �� ���������� ���� ����

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

	if (fut.wait_for(0s) == std::future_status::deferred)//�����Ǿ�����
	{

	}
	else //�������� �ʾ��� ��
	{
		while (fut.wait_for(100ms) != std::future_status::ready)
		{

		}
	}
}

//�⺻ lauch policy�� std::async�� ����ϴ� ���� ������ �ʿ��ϴ�.
//������ �񵿱�ȭ ��Ű�� ���ؼ��� std::launch::async�� ����ϸ� �ȴ�.
