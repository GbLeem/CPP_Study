#include<iostream>
#include<vector>

class Window
{
public:
	virtual void blink()
	{
		//아무 동작 안하기
	}
};

class SpecialWindow :public Window
{
public:
	virtual void blink()
	{
		//... blink함수의 동작
	}
};

//안좋은 예시 -> dynamic_cast는 성능상 저하가 심함
//typedef std::vector<std::tr1::shared_ptr<Window>>VPW;
//VPW winPtrs;
//
//int main()
//{
//	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter)
//	{
//		if (SpecialWindow* psw = dynamic_cast<SpecialWindow*>(iter->get()))
//			psw->blink();
//
//	}
//}

typedef std::vector<std::tr1::shared_ptr<Window>>VPW;
VPW winPtrs; //Window에서 파생된 모든 타입의 객체(에 대한 포인터)를 가지는 컨테이너

int main()
{
	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter)
	{
		(*iter)->blink();
	}
}
