//ITEM 15 : Use constexpr whenever possible


//constexpr ���� : �����Ϸ� ���� ������� ����
#include<iostream>

int sz;

constexpr auto arraySize1 = sz;//sz ���� ������ ���߿� �˷����� �ʴ´�.
std::array<int, sz> data1; //���� ���� ���� �߻�
constexpr auto arraySize2 = 10; //ok
std::array<int, arraySize2>data2; //ok

const auto arraySize = sz;//ok : const�� constexpr�̶� �ٸ�
//��� constexpr��ü�� const������ �ݴ�� �ش����� �ʴ´�.
//������ ���� ����� ���Ѵٸ� constexpr ���°��� �´�.


//constexpr �Լ�
constexpr int pow(int base, int exp) noexcept //base�� exp�� ������ ������ ��� �϶��� ����� constexpr�̴�.
{
	//return (exp == 0 ? 1 : base * pow(base, exp - 1)); c++11 ����
	auto result = 1;
	for (int i = 0; i < exp; ++i)
		result *= base;

	return result;
}

//int main()
//{
//	constexpr auto numConds = 5;
//	std::array<int, pow(3, numConds)> results;
//}


class Point
{
public:
	constexpr Point(double xVal=0, double yVal=0)noexcept
		:x(xVal),y(yVal)
	{}
	constexpr double xValue() const noexcept
	{
		return x;
	}
	constexpr double yValue() const noexcept
	{
		return y;
	}
	void setX(double newX)noexcept
	{
		x = newX;
	}
	void setY(double newY)noexcept
	{
		y = newY;
	}

private:
	double x, y;
};

constexpr Point midPoint(const Point& p1, const Point& p2) noexcept
{
	return { (p1.xValue() + p2.xValue()) / 2, (p1.yValue() + p2.yValue()) / 2 };
}

int main()
{
	constexpr Point p1(9.4, 27.7);
	constexpr Point p2(28.8, 5.3);

	constexpr auto mid = midPoint(p1, p2);
}
//��������� �����ϴ� ���� ������ �������� ��� �� �ִ�.
//������� ����Ʈ��� ��������.