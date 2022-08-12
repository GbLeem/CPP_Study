//1.
//#include<iostream>
//
//class Calculator
//{
//private:
//	double res;
//	int countA;
//	int countMi;
//	int countD;
//	int countM;
//
//
//public:
//	void Init()
//	{
//		res = 0;
//		countA = 0;
//		countM = 0;
//		countD = 0;
//		countMi = 0;
//	}
//
//	double Add(double a, double b)
//	{
//		res = a + b;
//		countA++;
//		return res;
//	}
//	double Div(double a, double b)
//	{
//		res = a / b;
//		countD++;
//		return res;
//	}
//	double Min(double a, double b)
//	{
//		res = a - b;
//		countMi++;
//		return res;
//	}
//	
//	double Mul(double a, double b)
//	{
//		res = a * b;
//		countM++;
//		return res;
//	}
//
//	void ShowOpCount()
//	{
//		std::cout << "µ¡¼À : " << countA << ' ';
//		std::cout << "»¬¼À : " << countMi << ' ';
//		std::cout << "°ö¼À : " << countM << ' ';
//		std::cout << "³ª´°¼À : " << countD << std::endl;
//	}
//};
//
//int main()
//{
//	Calculator cal;
//	cal.Init();
//	std::cout << cal.Add(3.2, 2.4) << std::endl;
//	std::cout << cal.Div(3.5, 1.7) << std::endl;
//	std::cout << cal.Min(2.2, 1.5) << std::endl;
//	std::cout << cal.Div(4.9, 1.2) << std::endl;
//	cal.ShowOpCount();
//	return 0;
//}


//2.
#include<iostream>

class Printer
{
private:
	const char* str;
public:
	void SetString(const char* ch)
	{
		str = ch;
	}

	void ShowString()
	{
		std::cout << str << std::endl;
	}
};

int main()
{
	Printer pnt;
	pnt.SetString("Hello World");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();

	return 0;
}