//ITEM 22 : When using the Pimpl Idiom, define special member functions in the implementation file


//<Pimpl>
//1. 불완전 형식(incomplete type)을 가리키는 포인터를 하나의 멤버로 선언
//2. 원래의 클래스에서 사용하던 자료 멤버들을 담는 객체를 동적으로 할당, 해제하는 코드 추가

#include<iostream>

//Widget.h
class Widget
{
public:
	Widget();
	~Widget(); // std::unique_ptr<Widget::Impl>을 파괴하는 코드가 만들어지는 시점에 Widget::Impl이 완전한 형식이 
			   // 되도록 만들기

	Widget(Widget&& rhs);//이동 연산 지원(선언만 하고 정의 x)
	Widget& operator=(Widget&& rhs);

	Widget(const Widget& rhs);//복사 연산 지워
	Widget& operator=(const Widget& rhs);

private:
	struct Impl;
	std::unique_ptr<Impl> pImpl;
};

//Widget.cpp
#include "widget.h"
#include "gadget.h"
#include<string>
#include<vector>

struct Widget::Impl
{
	std::string name;
	std::vector<double> dat;
	Gadget g1, g2, g3;
};

Widget::Widget()
	:pImpl(std::make_unique<Impl>()) //스마트 포인터를 사용하므로 소멸자가 따로 필요 없어진다
{}

Widget::~Widget() = default;

Widget::Widget(Widget && rhs) = default; //이동 연산 정의
Widget& Widget::operator=(Widget&& rhs) = default;

Widget::Widget(const Widget& rhs)
	:pImpl(nullptr)
{
	if (rhs.pImpl)pImpl = std::make_unique<Impl>(*rhs.pImpl);
}

Widget& Widget::operator=(const Widget& rhs)
{
	if (!rhs.pImpl)
		pImpl.reset();
	else if (!pImpl)
		pImpl = std::make_unique<Impl>(*rhs.pImpl);
	else
		*pImpl = *rhs.pImpl;

	return *this;
}


//std::unique_ptr VS std::shared_ptr

//unique_ptr : 삭제자의 형식은 스마트 포인터 형식의 일부
//더 작은 실행시점의 코드 만들기 가능
//컴파일러가 작성한 소멸자나 이동연산이 쓰이는 시점에서 포인터가 가리키는 타입들이 완전한 형식이어야 한다.

//shared_ptr : 삭제자의 형식이 스마트 포인터 형식의 일부가 아니다.
//실행코드가 커지고 느려지지만 
//포인터가 가리키는 타입들의 형식 제한이 없어진다.
