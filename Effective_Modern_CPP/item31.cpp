//ITEM 31 : Avoid default capture modes

//default capture mode
//1. by-reference 
//2. by-value

//������
//1.������ ����� �Ҵ� ����
//2.self-contained���� �ʴ� ����
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

//divisor�� Ŭ�������� �����Ҹ�Ǹ� ���� �߻�