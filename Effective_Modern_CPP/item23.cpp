//ITEM 23 : Understand std::move and std::forward

#include<iostream>
#include<chrono>
//std::move�� ����

namespace std
{
	//c++11
	template<typename T>
	typename remove_reference<T>::type&& move(T&& param)
	{
		using ReturnType = typename remove_reference<T>::type&&;

		return static_cast<ReturnType>(param);
	}

	//c++14
	template<typename T>
	decltype(auto) move(T&& param)
	{
		using ReturnType = remove_reference_t<T>&&;

		return static_cast<ReturnType>(param);
	}
}

//std::move ������
//1. �̵��� ������ ��ü�� const�� �������� ����->const ��ü�� ���� �̵� ��û�� ���� �������� ��ȯ�ȴ�.
//2. std::move�� ������ �̵����� �ʴ´�. ���� std::move�� ������ ����� rvalue��� �͸� Ȯ���ϴ�.

//std::forward -> std::move�� ��������� Ư�� ���ǿ����� rvalue�� ĳ�����Ѵ�.
class Widget{};

void process(const Widget& lvalArg); //lvalue ó��
void process(Widget&& rvalArg); //rvalue ó��

template<typename T>
void logAndProcess(T&& param)
{
	auto now = std::chrono::system_clock::now();

	makeLogEntry("Calling 'process'", now);
	process(std::forward<T>(param));
}

int main()
{
	Widget w;
	logAndProcess(w);//lvalue
	logAndProcess(std::move(w));//rvalue
}

//std::forward�� move�� ���ұ��� �� �� �� �ִ�.. �׷��� ĳ������ ������ ����ϴ� ��� �߻�..bad