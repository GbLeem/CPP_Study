#include<iostream>
using namespace std;

//1
//int main()
//{
//	int num;
//	int res = 0;
//	for (int i = 0; i < 5; ++i)
//	{
//		cout << i+1 << " 번째 정수 입력: ";
//		cin >> num;
//		res += num;
//	}
//	cout << "합계: " << res << endl;
//}


//2
//int main()
//{
//	char name[20];
//	char phone[20];
//	cout << "이름: ";
//	cin >> name;
//	cout << "전화번호: ";
//	cin >> phone;
//
//	cout << name << endl;
//	cout << phone << endl;;
//}


//3
//int main()
//{
//	int num;
//	cout << "원하는 단 입력: ";
//	cin >> num;
//	for (int i = 0; i < 9; ++i)
//	{
//		cout << num << " * " << i + 1 << " = ";
//		cout << num * (i + 1) << endl;
//	}
//}


//4
//int main()
//{
//	int cell = 0;
//	while (1)
//	{
//		cout << "판매 금액을 만원 단위로 입력(-1 : 끝내기) : ";
//		cin >> cell;
//		if (cell == -1)
//		{
//			cout << "프로그램 종료" << endl;
//			break;
//		}
//		cout << "이번달 급여 : " << float(50 + cell * 0.12) << endl;
//	}
//}