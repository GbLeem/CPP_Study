//Item 8 : Prefer nullptr to 0 and NULL

//void f(int);
//void f(bool);
//void f(void*);
//
//f(0);
//f(NULL);
//f(nullptr);//f(void*) ȣ��
////�� ��� ��� ���� f(int)�� ȣ���Ѵ�.
////nullptr�� ��� ������ �������̴�.
//
////auto �������� �� �������� 0�� ���� �ָ������� nullptr������ ������ ��ȯ������ Ȯ��������
//
//auto result = find(/*...*/);
//if (result == 0) //0�� �������� ���������� �ָ�
//{
//	//...
//}
//
//if (result == nullptr) //better
//{
//	//...
//}

//---------------------------
#include <mutex>
#include<iostream>
class Widget {};
template<typename FuncType, typename MuxType, typename Ptrtype>
decltype(auto) lockAndCall(FuncType func, MuxType mutex, Ptrtype ptr)
//->decltype(func(ptr))
{
	using MuxGuard = std::lock_guard<MuxType>;

	MuxGuard g(mutex);
	return func(ptr);
}

int main()
{
	int f1(std::shared_ptr<Widget> spw);
	double f2(std::unique_ptr<Widget> upw);
	bool f3(Widget * pw);

	std::mutex f1m, f2m, f3m;

	auto result1 = lockAndCall(f1, f1m, 0); //����
	auto result2 = lockAndCall(f2, f2m, NULL); //����
	auto result3 = lockAndCall(f3, f3m, nullptr); //ok
}