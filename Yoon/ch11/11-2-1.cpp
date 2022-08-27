//배열의 인덱스 연산자 오버로딩

#include<iostream>
#include<cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) {};
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {};
	//복사 생성자와 대입 연산자를 private 로 비어있는 상태로 선언해서 복사,대입을 막기!!

public:
	BoundCheckIntArray(int len)
		:arrlen(len)
	{
		arr = new int[len];
	}

	int& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int operator[](int idx) const //const를 통한 오버로딩
	{ 
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	int GetArrLen() const
	{
		return arrlen;
	}

	~BoundCheckIntArray()
	{
		delete[]arr;
	}
};

void ShowAllData(const BoundCheckIntArray& ref)
{
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; ++idx)
		cout << ref[idx] << endl; //const로 변수가 선언되어 있어서 [] 연산자를 통한 연산은 const가 아니므로 불가능
								  //-> [] 연산자를 const로 오버로딩하기
}

int main()
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; ++i)
		arr[i] = (i + 1) * 11;
	/*for (int i = 0; i < 6; ++i)
		cout << arr[i] << endl;*/

	ShowAllData(arr);
	return 0;
}