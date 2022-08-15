//**어려우
//ITEM 17 : Understand special member function generation

class Widget
{
public:
	Widget(Widget&& rhs); //이동 생성자
	Widget operator=(Widget&& rhs); //이동 배정 연산자


};

//기본 행동 사용 C++11

class Widget
{
public:
	~Widget();//기본 소멸자

	Widget(const Widget&) = default; //기본 복사 생성자 기본 행동
	Widget& operator=(const Widget&) = default; //기본 복사 배정 기본 행동
};


//컴파일러가 스스로 만들어주는 멤버 함수가 특수 멤버 함수이다.
//ex) 기본 생성자, 소멸자, 복사 연산, 이동 연산

//이동 연산은 이동 연산이나, 복사 연산, 소멸자가 명시적으로 선언되어 있지 않은 클래스에 
//대해서만 자동 생성된다.

//복사 생성자는 복사 생성자가 명시적으로 선언되어 있지 않는 클래스에서만 자동 작성되며
//이동 연산이 하나라도 있으면 삭제된다.
//복사 배정 연산자는 복사 배정 연산자가 명시적으로 선언되어있지 않은 클래스에 대해서만
//자동으로 작성되며, 이동 연산이 하나라도 선언되어 있으면 삭제된다.
//소멸자가 명시적으로 선언된 클래스에서 복사 연산들이 자동으로 작성되는 기능은 권장하지 않는다.

//멤버 함수 탬플릿 때문에 특수 멤버 함수의 자동 작성이 금지되는 경우는 없다.