//ITEM 28 : Understand reference collapsing

class Widget {};

template<typename T>
void func(T&& param);

int main()
{
	Widget widgetFactory(); //rval를 return 하는 함수
	Widget w;

	func(w); //func를 lval로 호출 T는 Widget&로 deduce
	func(widgetFactory()); //func를 rval로 호출 T를 Widget으로 deduce
}

//reference collapse
//참조에 대한 참조를 허용(템플릿 인스턴스화)
//두 참조중 적어도 하나가 lval 참조라면 결과는 lval 참조, 나머지는 rval 참조

//reference collapse 경우
//1. 템플릿의 인스턴스화
//2. auto 형식의 deduce
auto&& w1 = w; //w1 는 lval로 초기화
Widget& && w1 = w; //Widget& 형식으로 deduce -> 참조의 참조
Widget& w1 = w; //refernce collapse

auto&& w2 = widgetFactory(); //w2 rval로 초기화
Widget&& w2 = widgetFactory(); //Widget 형식으로 deduce


//3. typedef와 alias 선언
//4. decltype사용