//ITEM 25 : Use std::move on rvalue references, std::forward on universal references


//rvalue ref를 다른 함수로 전달할때에는 std::move를 사용해야 한다.
//universal ref 를 다른 함수로 전달 할때에는 std::forward를 사용하야 한다.(조건부)

//return by value 함수가 rvalue reference나 universal reference를 return 할때 std::move나 std::forward 적용
#include<iostream>

Matrix operator+(Matrix&& lhs, const Matrix& rhs) //return by value
{
	lhs += rhs;
	return std::move(lhs); //lhs를 return 값으로 이동
}
//효율 향상


//반환값 최적화의 대상이 될 수 있는 local 객체에는 절대 std::move나 std::forward 적용하지 않는다.
Widget makeWidget(void)
{
	Widget w;
	//...
	return w;
}

Widget makeWidget(void)
{
	Widget w;
	//...
	return std::move(w); //위의 코드를 최적화 한것 x
}

Widget makeWidget(Widget w)
{
	//...
	return std::move(w); //local 객체를 값으로 반환하는 경우..
						 //여전히 최적화 x
}