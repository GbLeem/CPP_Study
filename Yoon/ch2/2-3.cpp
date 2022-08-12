//malloc
//#define _CRT_SECURE_NO_WARNINGS
//
//#include<iostream>
//#include<string.h>
//#include<stdlib.h>
//using namespace std;
//
//char* MakeStrAdd(int len)
//{
//	//char* str = (char*)malloc(sizeof(char) * len);
//	char* str = new char[len];
//	return str;
//}
//
//int main()
//{
//	char* str = MakeStrAdd(20);
//	strcpy(str, "Hello World");
//	cout << str << endl;
//	//free(str);
//	delete[]str;
//	return 0;
//}

//힙에 할당된 변수 접근
//int* ptr = new int;
//int& ref = *ptr;
//ref = 20;
//cout << *ptr << endl; -> 결과 20


//1.***
#include<iostream>
typedef struct __Point
{
	int xPos;
	int yPos;
}Point;

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point* pt = new Point;
	pt->xPos = p1.xPos + p2.xPos;
	pt->yPos = p1.yPos + p2.yPos;

	return *pt;
}

int main()
{
	Point* pt1 = new Point;
	pt1->xPos = 10;
	pt1->yPos = 20;
	Point* pt2 = new Point;
	pt2->xPos = 100;
	pt2->yPos = 200;

	Point& pref = PntAdder(*pt1, *pt2);

	delete pt1;
	delete pt2;
	delete &pref;

	std::cout << pref.xPos << ' ' << pref.yPos << std::endl;
}