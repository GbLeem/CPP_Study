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
	Date d(Month::Jan(), 21, 2022); //month �� ��� �߸��� ���� �������� ��������! (day �� year�� �߸��� ���� �ֱ� ����)
}