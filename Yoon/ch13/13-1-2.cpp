#include<iostream>
#include<cstring>
using namespace std;

//���� 1.
//class Point
//{
//private:
//	int xpos, ypos;
//public:
//	Point(int x = 0, int y = 0)
//		:xpos(x)
//		, ypos(y)
//	{
//
//	}
//	void showPosition() const
//	{
//		cout << "[" << xpos << ", " << ypos << "]" << endl;
//	}
//};
//
//template<typename T>
//void swapData(T& swap1, T& swap2)
//{
//	T temp;
//	temp = swap1;
//	swap1 = swap2;
//	swap2 = temp;
//}
//
//int main()
//{
//	Point pos1{ 1,2 };
//	Point pos2{ 3,4 };
//	swapData(pos1, pos2);
//	pos1.showPosition();
//	pos2.showPosition();
//	return 0;
//}


//���� 2.
//template<typename T>
//T sumArray(T arr[], int len)
//{
//	T sum = 0;
//	for (int i = 0; i < len; i++)
//		sum += arr[i];
//	return sum;
//}
//
//int main()
//{
//	double arr1[3] = { 1.1,2.2,3.3 };
//
//	cout << sumArray(arr1, 3);
//}


//============================================
//�Լ� ���ø��� Ư��ȭ -> Ư�� Ÿ�Կ� ���ؼ��� �츮�� ���ص� ������� �����ϰ� �����
template<typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template<>
char* Max(char* a, char* b)
{
	cout << "char* Max<char*>(char*a, char*b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template<>
const char* Max(const char* a, const char* b)
{
	cout << "const char* Max<const char*>(const char*a, const char*b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main()
{
	cout << Max(11, 22) << endl;;
	cout << Max('T', 'Q') << endl;
	cout << Max("simple", "best") << endl;

	char str1[] = "good";
	char str2[] = "nicenice";
	cout << Max(str1, str2) << endl;
}