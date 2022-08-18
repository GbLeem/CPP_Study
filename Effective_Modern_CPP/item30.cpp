//ITEM 30 : Familiarize yourself with perfect forwarding failure cases

//완벽 전달 
//1. 함수가 자신의 인수들을 다른 함수에 전달하는 것
//2. 전달받는 함수가 전달하는 함수가 받았던 것과 동일한 객체들을 받게 하는 것
// 객체들의 주요 특징(형식, lval or rval, const or volatile여부)을 모두 전달하는 것

#include<iostream>

template<typename T>
void fwd(T&& param)
{
	f(std::forward<T>(param));
}

template<typename... Ts>
void fwd(Ts&&... param) //가변 인수 템플릿 -> ex) emplace 함수 종류 / make_unique, make_shared ...
{
	f(std::forward<T>(params)...);
}

f(/**/);
fwd(/**/); //두 호출의 하는 일이 같아야 완벽전달이 된 것이다.

//완벽전달 실패 경우
//1. 중괄호 초기치
//2. 널 포인터를 뜻하는 0 과 NULL
//3. 선언만 된 정수 static, const, constexpr 멤버
//4. overload된 함수 이름과 템플릿 이름
//5. bitfield