//item 5 : Prefer auto to explicit type declarations
#include<iostream>
#include<functional>

template<typename It>
void dwim(It b, It e)
{
	for (; b != e; ++b)
	{
		//typename std::iterator_traits<It>::value_type currValue = *b;
		auto currValue = *b;
		//...
	}
}

//----------------------------
//std::function : �Լ� �������� ������ �Ϲ�ȭ �Ѱ�
//�Լ� �����Ϳ� �޸� ȣ�Ⱑ���� ��ü��� � �͵� ����ų �� �ִ�

class Widget {};
bool f(const std::unique_ptr<Widget>& p1, const std::unique_ptr<Widget>& p2); //���� �Լ�

std::function<bool(const std::unique_ptr<Widget>&, const std::unique_ptr<Widget>&)> func;

//std::function�� auto���� ������ / �޸� ��� ũ��

//----------------------------
#include<vector>
std::vector<int>v;

//unsigned sz = v.size(); bad(���� ��ȯ Ÿ�԰� ��Ȯ�� ���� ����)
auto sz = v.size(); //good