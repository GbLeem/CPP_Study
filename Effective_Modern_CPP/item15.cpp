//ITEM 15 : Use constexpr whenever possible


//constexpr 변수 : 컴파일러 시점 상수임을 보장
#include<iostream>

int sz;

constexpr auto arraySize1 = sz;//sz 값이 컴파일 도중에 알려지지 않는다.
std::array<int, sz> data1; //위와 같은 문제 발생
constexpr auto arraySize2 = 10; //ok
std::array<int, arraySize2>data2; //ok

const auto arraySize = sz;//ok : const와 constexpr이랑 다름
//모든 constexpr객체는 const이지만 반대는 해당하지 않는다.
//컴파일 시점 상수를 원한다면 constexpr 쓰는것이 맞다.


//constexpr 함수
constexpr int pow(int base, int exp) noexcept //base와 exp가 컴파일 시점에 상수 일때만 결과가 constexpr이다.
{
	//return (exp == 0 ? 1 : base * pow(base, exp - 1)); c++11 버전
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
//실행시점에 수행하던 일을 컴파일 시점으로 당길 수 있다.
//사용자의 소프트웨어가 빨라진다.