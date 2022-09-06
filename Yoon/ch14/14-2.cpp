//클래스 템플릿의 특수화


//특정 자료형에 대해서 구분이 되는 행동을 하기 위해서!!

#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class Point
{
public:
	Point(T x = 0, T y = 0)
		:xpos(x)
		, ypos(y)
	{
	}

	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
private:
	T xpos, ypos;
};

template<typename T>
class SimpleDataWrapper
{
public:
	SimpleDataWrapper(T data)
		:mdata(data)
	{

	}
	void ShowDataInfo()const
	{
		cout << "data : " << mdata << endl;
	}
private:
	T mdata;
};

template<>
class SimpleDataWrapper<char*>
{
public:
	SimpleDataWrapper(const char* data)
	{
		mdata = new char[strlen(data) + 1];
		strcpy_s(mdata, strlen(data) + 1, data);
	}

	void ShowDataInfo()const
	{
		cout << "String : " << mdata << endl;
		cout << "Length : " << strlen(mdata) << endl;
	}
	~SimpleDataWrapper()
	{
		delete[]mdata;
	}
private:
	char* mdata;
};

template<>
class SimpleDataWrapper<Point<int>>
{
public:
	SimpleDataWrapper(int x, int y)
		:mdata(x,y)
	{
		
	}
	void ShowDataInfo() const
	{
		mdata.ShowPosition();
	}
private:
	Point<int> mdata;
};

int main()
{
	SimpleDataWrapper<int> iwrap{ 170 };
	iwrap.ShowDataInfo();
	SimpleDataWrapper<char*> swrap{ "Class Template Specialization" };
	swrap.ShowDataInfo();
	SimpleDataWrapper<Point<int>> poswrap{ 3,6 };
	poswrap.ShowDataInfo();

	return 0;
}