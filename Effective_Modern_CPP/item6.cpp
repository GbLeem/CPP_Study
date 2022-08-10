//Item 6 : Use the exlpicitly typed initializer idiom when auto deduces undesired types

//invisible proxy class는 auto와 어울리지 않는다.
//auto는 유용하기 때문에 invisible proxy class를 거르는 방법을 찾아보자
//-> 클라이언트가 호출하도록 만들어진 어떤 함수가 돌려주며, 해당 함수의 서명을 통해 확인 가능하다.

//auto를 다른 형식으로 deducing 시켜야 한다.
#include<vector>
class Widget{};

std::vector<bool> features(const Widget& w);

int main()
{
	Widget w;
	//bool highPriority = features(w)[5]; 문제 없음
	//auto highPriority = features(w)[5]; 문제 발생
	auto highPriority = static_cast<bool>(features(w)[5]); //강제 캐스팅으로 문제 해결
	processWidget(w, highPriority);
}