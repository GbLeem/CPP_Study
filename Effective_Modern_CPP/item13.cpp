//ITEM 13 : Prefer const_iterators to iterators

#include<vector>
typedef std::vector<int>::iterator IterT;
typedef std::vector<int>::const_iterator ConstIterT;

std::vector<int> values;

ConstIterT ci = std::find(static_cast<ConstIterT>(values.begin()),
						  static_cast<ConstIterT>(values.end()),
						  1983);
values.insert(static_cast<IterT>(ci), 1998);


//-----------------------------------------
//c++11 ���� cbegin�� cend���� const_iterator��ȯ
std::vector<int> values;
auto it = std::find(values.cbegin(), values.cend(), 1983);
values.insert(it, 1998);

//non-memeber cbegin�� ����
template<class C>
auto cbegin(const C& container)->decltype(std::begin(container))
{
	return std::begin(container);
}