#include<iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x)
		, ypos(y)
	{

	}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << "]" << endl;
	}

	Point& operator+=(const Point& temp) //���� 2
	{
		xpos = xpos + temp.xpos;
		ypos = ypos + temp.ypos;

		return *this;
	}

	Point& operator-=(const Point& temp)
	{
		xpos = xpos - temp.xpos;
		ypos = ypos - temp.ypos;

		return *this;
	}

	friend Point operator+(const Point& pos1, const Point& pos2);

	friend Point operator-(const Point& pos1, const Point& pos2); //���� 1

	friend bool operator==(const Point& pos1, const Point& pos2); //���� 3
	friend bool operator!=(const Point& pos1, const Point& pos2);
};

Point operator+(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}
Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos2.ypos - pos2.ypos);
	return pos;
}

bool operator==(const Point& pos1, const Point& pos2)
{
	if (pos1.xpos == pos2.xpos)
	{
		if (pos1.ypos == pos2.ypos)
		{
			return true;
		}
	}

	return false;
}

bool operator!=(const Point& pos1, const Point& pos2)
{
	if (pos1 == pos2)
		return false;
	return true;
}

int main()
{
	Point p1(10, 20);
	Point p2(10, 20);

	//p1 += p2;

	p1.ShowPosition();

	if (p1 != p2)
	{
		cout << "diffent" << endl;
	}
	else
		cout << "same" << endl;
}

//����Լ� �������"��" �����ε��� ������ ������
// = , () , [] , ->

//������ �����ε� ���Ŀ��� �켱������ ���ռ��� ���� �׷����̴�.

