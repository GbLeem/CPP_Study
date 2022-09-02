//¹®Á¦ 2.
#include<iostream>
using namespace std;

class BoundCheck2DIntArray
{
private:
	int *arr;
	int len1;
	int len2;

public:
	BoundCheck2DIntArray(int l1, int l2)
		:len1(l1)
		,len2(l2)
	{
		arr = new int[l1 + l2];
	}
	int& operator[](const int& ref)
	{
		delete arr;
	}
};

int main()
{

}
