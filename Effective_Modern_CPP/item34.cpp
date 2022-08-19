//ITEM 34 : Prefer lambdas to std::bind

//c++11에서는 거의 lambda가 std::bind보다 좋다.
//c++14에서는 100% lambda가 좋다.
#include<functional>
#include<iostream>

//std::bind 사용 예시
//1. move capature : c++11 lambda에는 move capture 없기 때문에

//2. polymorphic function object

class PolyWidget
{
public:
	template<typename T>
	void operator() (const T& param)const;
};

int main()
{
	PolyWidget pw;
	auto boundPW = std::bind(pw, std::placeholders::_1);

	//auto boundPW = [pw](const auto& param) //c++14 람다
	//{
	//	pw(param);
	//};

	boundPW(1930);
	boundPW(nullptr);
	boundPW("Hello");
}