//ITEM 19 : Use std::shared_ptr for shared-ownership resource management

//shared_ptr은 raw 포인터의 크기의 두배이다.
//참조 횟수를 담을 메모리를 반드시 동적으로 할당해야 한다.
//참조 횟우의 증가와 감소가 atomic 연산이어야 한다.


//unique_ptr과 shared_ptr의 삭제자 
#include<iostream>

class Widget {};

auto logginDel = [](Widget* pw)
{
	makeLogEntry(pw);
	delete pw;
};

std::unique_ptr<Widget, decltype(logginDel)> upw(new Widget, logginDel);//포인터 형식의 일부

std::shared_ptr<Widget> spw(new Widget, logginDel); // 포인터 형식의 일부 아님


//shared_ptr 생성자에 raw포인터 넘기지 말기 -> make_shared사용
//shared_ptr생성자를 raw포인터로 생성할 수 밖에 없는 경우 new의 결과를 직접 전달하기

//<bad code>
auto pw = new Widget;

std::shared_ptr<Widget> spw1(pw, logginDel);

std::shared_ptr<Widget> spw2(pw, logginDel);

//<better>
std::shared_ptr<Widget> Nspw1(new Widget, logginDel);

std::shared_ptr<Widget> Nspw2(Nspw1);