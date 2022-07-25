#include<iostream>

class Window //기본 클래스
{
public:
	virtual void onResize()
	{

	}
};

class SpecialWindow :public Window //파생 클래스
{
public:
	virtual void onResize()
	{
		//static_cast<Window>(*this).onResize(); //복사된 임시 객체가 onResize() 를 호출함 -> 원하는 결과가 아니다
		Window::onResize();
	}
};