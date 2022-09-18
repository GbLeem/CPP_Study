//				<template type Deduction>


//auto Ű����� deduction ����


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
	//printIntRRef(a);


	int a = 1;
	//printVar2<int>(a); ������ ����
	printVar2(a); //deduction?

	std::string str = "good";
	printVar2(str);
	printVar2(std::move(str));
	return 0;
}