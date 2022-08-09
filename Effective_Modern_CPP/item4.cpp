//Item4 : Know how to view deduced type

//template<typename T>
//class TD;
//
//const int theAnswer = 42;
//auto x = theAnswer; //x : int
//auto y = &theAnswer;//y : const int*
//
//TD<decltype(x)> xType;
//TD<decltype(y)> yType;

//------------------------------------
#include<vector>
#include<iostream>
class Widget
{

};

template <typename T>
void f(const T& param);

std::vector<Widget> createVec();

const auto vw = createVec();

int main()
{
	if (!vw.empty()) 
	{
		f(&vw[0]);
	}
}

template<typename T>
void f(const T& param)
{
	using std::cout;
	cout << "T = " << typeid(T).name() << '\n';
	cout << "param = " << typeid(param).name<< '\n';
}
