//Item 8 : Prefer nullptr to 0 and NULL

//void f(int);
//void f(bool);
//void f(void*);
//
//f(0);
//f(NULL);
//f(nullptr);//f(void*) 호출
////두 경우 모두 보통 f(int)를 호출한다.
////nullptr은 모든 형식의 포인터이다.
//
////auto 변수사용시 비교 구문에서 0을 쓰면 애매하지만 nullptr을쓰면 무엇이 반환값인지 확실해진다
//
//auto result = find(/*...*/);
//if (result == 0) //0은 정수인지 포인터인지 애매
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

	auto result1 = lockAndCall(f1, f1m, 0); //오류
	auto result2 = lockAndCall(f2, f2m, NULL); //오류
	auto result3 = lockAndCall(f3, f3m, nullptr); //ok
}