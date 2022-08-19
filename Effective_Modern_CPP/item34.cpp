//ITEM 34 : Prefer lambdas to std::bind

//c++11������ ���� lambda�� std::bind���� ����.
//c++14������ 100% lambda�� ����.
#include<functional>
#include<iostream>

//std::bind ��� ����
//1. move capature : c++11 lambda���� move capture ���� ������

//2. polymorphic function object

class PolyWidget
{
public:
	template<typename T>
	void operator() (const T& param)const;
};

int main()
{
	PolyWidget pw;
	auto boundPW = std::bind(pw, std::placeholders::_1);

	//auto boundPW = [pw](const auto& param) //c++14 ����
	//{
	//	pw(param);
	//};

	boundPW(1930);
	boundPW(nullptr);
	boundPW("Hello");
}