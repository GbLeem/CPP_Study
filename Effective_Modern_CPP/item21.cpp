//ITEM 21 : Prefer std::make_unique and std::make_shared to direct use of new

#include<iostream>

//make_unique�� ����
template<typename T,typename... Ts>
std::unique_ptr<T> make_unique(Ts&&...params)
{
	return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
}


//make �Լ� ��� vs new ���
class Widget {};

auto upw1(std::make_unique<Widget>());   //make ���
std::unique_ptr<Widget>upw2(new Widget); //new ���

auto spw1(std::make_shared<Widget>());   //make ���
std::shared_ptr<Widget>spw2(new Widget); //new ��� -> new ����� ��� Widget�� �ι��ݺ�.. bad

//make�� ���� �������� ����
