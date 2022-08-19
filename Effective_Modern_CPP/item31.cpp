//ITEM 31 : Avoid default capture modes

//default capture mode
//1. by-reference 
//2. by-value

//문제점
//1.참조가 대상을 잃는 문제
//2.self-contained하지 않는 문제
#include<iostream>
#include<vector>
#include<functional>
using FilterContainer = std::vector <std::function<bool(int)>>;

void addDivisorFilter()
{
	auto calc1 = computeSomValue1();
	auto calc2 = computeSomValue2();

	auto divisor = computeDivisor(calc1, calc2);
	using ContElemT = typename C::value_type;

	using std::begin;
	using std::end;

	if (std::all_of(begin(container), end(container), [&](const auto& value) {return value % divisor == 0; }))
	{
	}
	else
	{ 
	}
}

int main()
{
	FilterContainer filters;
	filters.emplace_back([=](int value) {return value % 5 == 0; });
}

//divisor가 클로저보다 먼저소멸되면 문제 발생