//Ä¸½¶È­

//¹®Á¦1
#include<iostream>
using namespace std;

class Circle
{
private:
	int centerX, centerY;
	int radius;

public:
	void Init(int x, int y,int r)
	{
		centerX = x;
		centerY = y;
		radius = r;
	}
	void ShowCircleInfo() const
	{
		cout << "[" << centerX << ", " << centerY << "]" << endl;
		cout << "R : " << radius << endl;
	}
	int GetR() const
	{
		return radius;
	}
	int GetX() const
	{
		return centerX;
	}
	int GetY() const
	{
		return centerY;
	}
};

class Ring
{
private:
	Circle c1, c2;

public:
	void Init(int x1, int y1, int r1, int x2, int y2, int r2)
	{
		c1.Init(x1, y1, r1);
		c2.Init(x2, y2, r2);
	}
	void ShowRingInfo() const
	{
		if (c1.GetR() > c2.GetR())
		{
			cout << "Outter Circle Ring" << endl;
			c1.ShowCircleInfo();
			cout << "Inner Circle Ring" << endl;
			c2.ShowCircleInfo();
		}
		else
		{
			cout << "Outter Circle Ring" << endl;
			c2.ShowCircleInfo();
			cout << "Inner Circle Ring" << endl;
			c1.ShowCircleInfo();
		}	
	}
};

int main()
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}