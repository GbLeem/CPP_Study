//그 이외의 연산자 오버로딩

//new와 delete의 오버로딩

#include<iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x = 0,int y=0)
		:xpos(x)
		,ypos(y)
	{}
	friend ostream& operator<<(ostream& os, const Point& ref);

	static void* operator new(size_t size)
	{
		cout << "operator new : " << size << endl;
		void* adr = new char[size];
		return adr;
	}
	static void* operator new[](size_t size)
	{
		cout << "operator new[] : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	static void operator delete(void* adr)
	{
		cout << "operator delete ()" << endl;
		delete[]adr;
	}
	static void operator delete[](void* adr)
	{
		cout << "operator delete[] ()" << endl;
		delete[]adr;
	}
};

ostream& operator<<(ostream& os, const Point& ref)
{
	os << '[' << ref.xpos << ", " << ref.ypos << "]" << endl;
	return os;
}

int main()
{
	Point* ptr = new Point(3, 4);
	Point* arr = new Point[5];
	//cout << *ptr;
	delete ptr;
	delete[]arr;
	return 0;
}
