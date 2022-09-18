//				<template type Deduction>


//auto 키워드로 deduction 실행


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
	//printIntRRef(a);


	int a = 1;
	//printVar2<int>(a); 컴파일 오류
	printVar2(a); //deduction?

	std::string str = "good";
	printVar2(str);
	printVar2(std::move(str));
	return 0;
}