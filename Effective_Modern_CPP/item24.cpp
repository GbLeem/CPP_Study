//ITEM 24 : Distinguish universal references from rvalue references


#include<vector>
class Widget {};

void f(Widget&& param); //rvalue ref

Widget&& var1 = Widget();//rvalue ref

auto&& var2 = var1; //not rvalue ref -> universal ref

template<typename T>
void f(std::vector<T>&& param);//rvalue ref

template<typename T>
void f(T&& param); //not rvalue ref ->universal ref

//T&& 이동의 원본이 될 수 있는 객체를 지정한다.

//universal ref의 공통점은 type deduction이 일어난다는 것이다.

//정리
//함수 탬플릿의 매개변수 형식이 T&&이고 T가 deduction되거나 / 객체를 auto&&로 선언한다면 universal ref이다.
//rvalue로 초기화되는 universal ref는 rvalue ref이다. 반대는 lvalue ref