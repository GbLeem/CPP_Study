//ITEM 21 : Prefer std::make_unique and std::make_shared to direct use of new

#include<iostream>

//make_unique의 구현
template<typename T,typename... Ts>
std::unique_ptr<T> make_unique(Ts&&...params)
{
	return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
}


//make 함수 사용 vs new 사용
class Widget {};

auto upw1(std::make_unique<Widget>());   //make 사용
std::unique_ptr<Widget>upw2(new Widget); //new 사용

auto spw1(std::make_shared<Widget>());   //make 사용
std::shared_ptr<Widget>spw2(new Widget); //new 사용 -> new 사용의 경우 Widget이 두번반복.. bad

//make는 예외 안정성을 가짐
