//item 5 : Prefer auto to explicit type declarations
#include<iostream>
#include<functional>

template<typename It>
void dwim(It b, It e)
{
	for (; b != e; ++b)
	{
		//typename std::iterator_traits<It>::value_type currValue = *b;
		auto currValue = *b;
		//...
	}
}

//----------------------------
//std::function : 함수 포인터의 개념을 일반화 한것
//함수 포인터와 달리 호출가능한 객체라면 어떤 것도 가리킬 수 있다

class Widget {};
bool f(const std::unique_ptr<Widget>& p1, const std::unique_ptr<Widget>& p2); //기존 함수

std::function<bool(const std::unique_ptr<Widget>&, const std::unique_ptr<Widget>&)> func;

//std::function은 auto보다 느리다 / 메모리 사용 크다

//----------------------------
#include<vector>
std::vector<int>v;

//unsigned sz = v.size(); bad(원래 반환 타입과 정확히 맞지 않음)
auto sz = v.size(); //good