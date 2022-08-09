//item3 : Understand decltype

#include<iostream>

template<typename Container, typename Index>
decltype(auto) 
autoAndAccess(Container&& c, Index i)
{
	authenticateUser();
	return std::forward<Container>(c)[i];
}

//--------------------------------------------
decltype(auto) f1()
{
	int x = 0;

	return x; //decltype(x) is int
}

decltype(auto) f2()
{
	int x = 0;

	return (x); //decltype((x)) is int&
}