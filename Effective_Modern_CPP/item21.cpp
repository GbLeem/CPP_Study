//ITEM 21 : Prefer std::make_unique and std::make_shared to direct use of new

#include<iostream>

//make_unique의 구현
template<typename T,typename... Ts>
std::unique_ptr<T> make_unique(Ts&&...params)
{
	return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
}


//make 함aaa용
class Widget {};

auto upw1(std::make_unique<Widget>());   //make 사용
std::unique_ptr<Widget>upw2(new Widget); //new 사용

auto spw1(std::make_shared<Widget>());   //make 사용
std::shared_ptr<Widget>spw2(new Widget); //new 사용 -> new 사용의 경우 Widget이 두번반복.. bad

//make는 예외 안정성을 가짐
void processWidget(std::shared_ptr<Widget> spw, int priority);

int computerPriority();
processWidget(std::shared_ptr<Widget>(new Widget), computerPriority()); //자원 누수 위험

processWidget(std::make_shared<Widget>(), computerPriority()); //자원 누수 x


//make 단점1 : 커스텀 삭제자를 지정할수 있는 것이 없다.
//make 단점2 : 괄호와 중괄호의 문제 -> make는 초기화 내부적으로 () 사용하도록 되어있다.


void processWidget(std::shared_ptr<Widget>spw, int priority);
void cusDel(Widget* ptr); //커스텀 삭제자

processWidget(std::shared_ptr<Widget>(new Widget, cusDel), computerPriority()); //자원 누수 위험

std::shared_ptr<Widget>spw(new Widget, cusDel);
processWidget(spw, computerPriority()); //예외로 부터 안전하기는 함

processWidget(std::move(spw), computerPriority());//good