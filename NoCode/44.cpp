//				<template type Deduction>
// 어렵다 다시 들어보자


//auto 키워드로 deduction 실행
//template도 deduction이 가능하지만 r-value reference 인 경우 문제가 발생할 여지가 있다.

#include<iostream>
#include<string>
template<typename T>
void printVar(T a)
{
	std::cout << typeid(a).name() << std::endl;
	std::cout << a << std::endl;
}

// &&에 대한 예시 함수1
void printIntLRef(int &a)
{
	std::cout << a << std::endl;
}
// &&에 대한 예시 함수2
void printIntRRef(int && a)
{
	std::cout << a << std::endl;
}

//&&에 대한 내용 템플릿
template<typename T>
void printVar2(T &&a) //forward reference(= universal reference)
{
	std::cout << typeid(a).name() << std::endl;
	std::cout << a << std::endl;
}

template<typename T>
void printVar3(T&& a) 
{
	std::string localVar{ std::move(a) };
}

template<typename T>
void printVar4(T&& a)
{
	std::string localVar{ std::forward<T>(a) };
	std::cout << localVar << std::endl;
}

int main()
{
	//deduction 예시
	//auto a = 1;
	//std::cout << typeid(a).name() << std::endl;
	//auto b = 1.1;
	//std::cout << typeid(b).name() << std::endl;
	//auto c = "ABC";
	//std::cout << typeid(c).name() << std::endl;


	//template deduction 예시
	//int a = 1;  
	//printVar<int>(a);
	//printVar(a); //deduction -> 알아서 찾아줌

	//&& 예시
	//int a = 1;
	//printIntLRef(a);
	//printIntRRef(a); 컴파일 오류


	int a = 1;
	//printVar2<int>(a); 컴파일 오류
	printVar2(a); //deduction?


	std::string str = "good";
	printVar2(str);
	printVar2(std::move(str));

	std::string str2 = "good";
	printVar3(str2);
	printVar3(std::move(str2));

	std::string str3 = "good";
	printVar4(str3);
	printVar4(std::move(str3));

	return 0;
}