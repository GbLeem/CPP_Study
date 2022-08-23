//단항 연산자의 오버로딩

#include<iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0,int y=0)
		:xpos(x)
		,ypos(y)
	{}

	Point& operator++() //++pos 전위
		//** ++(++pos) -> Ok! **
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}

	const Point operator++(int)//pos++ 후위 
		//const 반환형의 이유 : operator++함수의 반환으로 인해 생성되는 임시 객체를 const 객체로생성

		//** (pos++)++ -> No! **
	{
		const Point temp(xpos, ypos); //함수 내에서 temp의 값 변경을 막음
		xpos += 1;
		ypos += 1;
		return temp;
	}


	Point& operator-() //문제 1
	{
		xpos = -xpos;
		ypos = -ypos;

		return *this;
	}

	friend Point& operator--(Point& ref);

	friend Point operator~(Point& ref);

	void show()
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

Point& operator--(Point& ref)
{
	ref.xpos += 1;
	ref.ypos += 1;

	return ref;
}

Point operator~(Point& ref)
{
	Point pos;
	pos.xpos = ref.ypos;
	pos.ypos = ref.xpos;

	return pos;
}

int main()
{
	Point p1(10, 20);
	Point p2(100, 200);

	p1 = -p2;
	p1.show();

	p1 = ~p2;
	p1.show();

	return 0;
}
