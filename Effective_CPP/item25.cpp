#include<iostream>
#include<vector>

class WidgetImpl
{
public:
	//....

private:
	int a, b, c;
	std::vector<double>v;
};

class Widget
{
public:
	Widget(const Widget& rhs);

	Widget& operator=(const Widget& rhs)
	{
		*pImpl = *(rhs.pImpl);
	}
	
	void swap(Widget& other) //멤버함수
	{
		using std::swap;// std::swap을 가져오기

		swap(pImpl, other.pImpl);
	}

private:
	WidgetImpl* pImpl;
};

namespace std
{
	template<>
	void swap<Widget>(Widget& a, Widget& b)
	{
		//swap(a.pImpl, b.pImpl);
		a.swap(b);
	}
}
