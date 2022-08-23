//���� �������� �����ε�

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

	Point& operator++() //++pos ����
		//** ++(++pos) -> Ok! **
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}

	const Point operator++(int)//pos++ ���� 
		//const ��ȯ���� ���� : operator++�Լ��� ��ȯ���� ���� �����Ǵ� �ӽ� ��ü�� const ��ü�λ���

		//** (pos++)++ -> No! **
	{
		const Point temp(xpos, ypos); //�Լ� ������ temp�� �� ������ ����
		xpos += 1;
		ypos += 1;
		return temp;
	}


	Point& operator-() //���� 1
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
