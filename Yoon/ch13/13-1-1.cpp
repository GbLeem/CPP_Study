//���ø��� ���� ���ؿ� �Լ� ���ø�

#include<iostream>
using namespace std;

template<typename T> 
T Add(T a, T b)  //�Լ� ���ø�
{
	return a + b;
}
//������ �ϴ½ð��� ������ ������ �ִ�.

template<class T1, class T2>
void showData(double num)
{
	cout << (T1)num << ", " << (T2)num << endl;
}

int main()
{
	cout << Add<int>(1, 2) << endl; //���ø� �Լ��� ���� ��� �� ���
	cout << Add(1.2, 2.2) << endl;

	showData<char, int>(65);
	showData<short, double>(65.1);
}

