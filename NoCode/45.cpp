//				<Instantiation>


//type instantiation이 implicit 한 특징을 이용한 경우 3가지
//multiple type parameter -> std::find
//non type parameter -> std::array
//parameter pack

//type instantiation이 implicit하기때문에 아래 처럼 동작한다.
//template build 
//-> template를 만들때는 모든 선언과 정의를 헤더 파일에 만들어야 한다.
//-> 헤더파일에서 정의가 하기 싫다면 type explicit instantiation 해주면된다.

#include<iostream>

//multiple type parameter -> 두개 이상의 typename
template<typename IT, typename T>
IT foo1(IT first, IT last, const T& value)
{
	while (first != last)
	{
		if (*first == value)
		{
			return first;
		}
		first++;
	}
	return last;
}

//non type parameter-> typename 이외의 일반 타입 함께 쓰기
template<typename T, std::size_t N>
T foo2(T a)
{
	return N * a;
}

//parameter pack -> 갯수를 지정 안함
template<typename ...T>
void foo3(T && ... args)
{
	(std::cout << ... << args) << std::endl;
}

//템플릿은 definition 코드만 있고, 실제 템플릿 함수, 클래스가 불러질때 initiation이 된다. 
int main()
{
	//non type 예시
	std::cout << foo2<double, 4>(2.0) << std::endl;
	

	//parameter pack 예시
	foo3(1, 2, 3);
	foo3("ABC", "good");

	return 0;
}


//============ template build  ==================
//foo.h
template<typename T>
T foo(T a);

//foo.cpp
template<typename T>
T foo(T a)
{
	return a * 2;
}
template int foo<int>(int); //type explicit instantiation

//main.cpp
#include <iostream>
#include "foo.h"

int main()
{
	std::cout << foo<int>(1) << std::endl;
	//std::cout << foo<double>(1.0) << std::endl; 컴파일 에러! -> type explicit instanciation 안했으니까
	return 0;
}
