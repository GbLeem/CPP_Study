//Ŭ���� ���ø�
#include<iostream>
using namespace std;

//template<typename T>
//class Widget
//{
//public:
//	T getInt();
//private:
//	T x;
//};
//
//template<typename T> //�Լ� �ܺο� ���� �Ϸ��� template �ٿ��־�� ��
//T Widget<T>::getInt()
//{
//	return x;
//}


//======================================
//���� 1.
template<typename T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:posptr(ptr)
	{

	}
	T& operator*()const
	{
		return *posptr;
	}
	T* operator->()const
	{
		return posptr;
	}
	~SmartPtr()
	{
		delete posptr;
	}
private:
	T* posptr;
};

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x)
		, ypos(y)
	{

	}
	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void showPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

int main()
{
	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->showPosition();
	sptr2->showPosition();
}