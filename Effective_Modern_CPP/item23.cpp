//ITEM 23 : Understand std::move and std::forward

#include<iostream>
#include<chrono>
//std::move의 구현

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

//std::move 주의점
//1. 이동을 지원할 객체는 const로 선언하지 말자->const 객체에 대한 이동 요청은 복사 연산으로 변환된다.
//2. std::move는 실제로 이동하지 않는다. 단지 std::move를 적용한 결과가 rvalue라는 것만 확실하다.

//std::forward -> std::move와 비슷하지만 특정 조건에서만 rvalue를 캐스팅한다.
class Widget{};

void process(const Widget& lvalArg); //lvalue 처리
void process(Widget&& rvalArg); //rvalue 처리

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

//std::forward는 move의 역할까지 다 할 수 있다.. 그러나 캐스팅을 억지로 써야하는 경우 발생..bad