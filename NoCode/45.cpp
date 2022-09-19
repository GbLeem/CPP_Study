//				<Instantiation>


//type instantiation�� implicit �� Ư¡�� �̿��� ��� 3����
//multiple type parameter -> std::find
//non type parameter -> std::array
//parameter pack

//type instantiation�� implicit�ϱ⶧���� �Ʒ� ó�� �����Ѵ�.
//template build 
//-> template�� ���鶧�� ��� ����� ���Ǹ� ��� ���Ͽ� ������ �Ѵ�.
//-> ������Ͽ��� ���ǰ� �ϱ� �ȴٸ� type explicit instantiation ���ָ�ȴ�.

#include<iostream>

//multiple type parameter -> �ΰ� �̻��� typename
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

//non type parameter-> typename �̿��� �Ϲ� Ÿ�� �Բ� ����
template<typename T, std::size_t N>
T foo2(T a)
{
	return N * a;
}

//parameter pack -> ������ ���� ����
template<typename ...T>
void foo3(T && ... args)
{
	(std::cout << ... << args) << std::endl;
}

//���ø��� definition �ڵ常 �ְ�, ���� ���ø� �Լ�, Ŭ������ �ҷ����� initiation�� �ȴ�. 
int main()
{
	//non type ����
	std::cout << foo2<double, 4>(2.0) << std::endl;
	

	//parameter pack ����
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
	//std::cout << foo<double>(1.0) << std::endl; ������ ����! -> type explicit instanciation �������ϱ�
	return 0;
}
