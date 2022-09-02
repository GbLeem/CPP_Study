//		<Pointer vs Reference>

#include<vector>

void fooV(int a) //pass by value
{
	int b = a + 1;
};

void fooP(int* ap) //pass by pointer
{
	int b = *ap + 1;
	*ap = 100;
};

void fooR(const int& ar) //pass by reference
//ar값 변경 안하므로 const 쓰자
{
	int b = ar + 1;
}

int main()
{
	int a = 0;
	fooV(a);
	fooP(&a);
	fooR(a);
	//pointer가 무조건 필요한 경우가 아니라면 reference쓰기

	std::vector<int> v;
	int a1 = 1;
	int a2 = 2;

	v.push_back(a1); 
	v.push_back(a2);
	//매개변수 종류 :
	//1. (const T& value) -> lvalue ref
	//2. (T&& value) -> rvalue ref

	return 0;
}