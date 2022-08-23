//ITEM 42 

#include<vector>
#include<string>
#include<iostream>
#include<list>
int main()
{
	std::vector <std::string> vs;
	vs.push_back("abc"); 
	//-> vs.push_back(std::string("abc")); 으로 취급
	//-> 해당 값이 원래 push_back의 인수와 달라 임시객체 생성과 소멸 과정이 생긴다.

	//생성 삽입 함수
	vs.emplace_back("abc");// std::vector 안에서 std::string을 생성한다.(임시객체 관여x)

	//일반 삽입 함수가 생성 삽입보다 빠른 경우도 존재한다.

	//     <생성 삽입이 더 효율적인 조건들>
	//1. 추가할 값이 컨테이너에 배정되는 것이 아니라 컨테이너 안에서 생성된다.
	//2. 추가할 인수형식이 컨테이너가 담는 형식과 다르다.
	//3. 컨테이너가 기존 값과의 중복 때문에 새 값을 거부할 우려가 별로 없다.
}


class Widget{};
std::list < std::shared_ptr<Widget>>ptrs;
void killWidget(Widget* pWidget);

int main()
{
	ptrs.push_back(std::shared_ptr<Widget>(new Widget, killWidget));
	ptrs.emplace_back(new Widget, killWidget); //자원 누수 가능성.. 
	//new Widget을 emplace_back이나 push_back에 직접 넣는것 좋지 않다.

	//위 방식보다 better
	std::shared_ptr<Widget>spw(new Widget, killWidget); //관리 객체 생성

	ptrs.push_back(std::move(spw)); //rval로 전달
	ptrs.emplace_back(std::move(spw));
}




