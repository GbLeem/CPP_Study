//�迭�� �ε��� ������ �����ε�

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
	//���� �����ڿ� ���� �����ڸ� private �� ����ִ� ���·� �����ؼ� ����,������ ����!!

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
	int operator[](int idx) const //const�� ���� �����ε�
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
		cout << ref[idx] << endl; //const�� ������ ����Ǿ� �־ [] �����ڸ� ���� ������ const�� �ƴϹǷ� �Ұ���
								  //-> [] �����ڸ� const�� �����ε��ϱ�
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