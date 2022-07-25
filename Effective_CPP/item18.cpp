#include<iostream>

class Date
{
public:
	Date(const Month& m, const int d, const int y)
	{
	}
};

class Month
{
public:
	static Month Jan() { return Month(1); }
	static Month Feb() { return Month(2); }
	static Month May() { return Month(3); }
	static Month Mar() { return Month(4); }
private:
	explicit Month(int m);
};

int main()
{
	Date d(Month::Jan(), 21, 2022); //month 의 경우 잘못된 값을 넣을일이 없어진다! (day 나 year은 잘못된 값을 넣기 쉽다)
}