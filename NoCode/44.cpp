//				<template type Deduction>
// ��ƴ� �ٽ� ����


//auto Ű����� deduction ����
//template�� deduction�� ���������� r-value reference �� ��� ������ �߻��� ������ �ִ�.

#include<iostream>
#include<string>
template<typename T>
void printVar(T a)
{
	std::cout << typeid(a).name() << std::endl;
	std::cout << a << std::endl;
}

// &&�� ���� ���� �Լ�1
void printIntLRef(int &a)
{
	std::cout << a << std::endl;
}
// &&�� ���� ���� �Լ�2
void printIntRRef(int && a)
{
	std::cout << a << std::endl;
}

//&&�� ���� ���� ���ø�
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
	//deduction ����
	//auto a = 1;
	//std::cout << typeid(a).name() << std::endl;
	//auto b = 1.1;
	//std::cout << typeid(b).name() << std::endl;
	//auto c = "ABC";
	//std::cout << typeid(c).name() << std::endl;


	//template deduction ����
	//int a = 1;  
	//printVar<int>(a);
	//printVar(a); //deduction -> �˾Ƽ� ã����

	//&& ����
	//int a = 1;
	//printIntLRef(a);
	//printIntRRef(a); ������ ����


	int a = 1;
	//printVar2<int>(a); ������ ����
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