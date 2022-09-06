//템플릿 인자

//template<typename T, int len> -> int len 과 같은 것을 넣을 수 있는데, 이것을 템플릿 인자라고 합니다

#include<iostream>
using namespace std;

template<typename T, int len>
class SimpleArray
{
public:
	T& operator[](int idx)
	{
		return arr[idx];
	}
	SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref)
	{
		for (int i = 0; i < len; ++i)
			arr[i] = ref.arr[i];
		return *this;
	}
private:
	T arr[len];
};

int main()
{
	SimpleArray<int, 5> i5arr1;
	for (int i = 0; i < 5; ++i)
		i5arr1[i] = i * 10;

	SimpleArray<int, 5> i5arr2;
	i5arr2 = i5arr1;
	for (int i = 0; i < 5; ++i)
		cout << i5arr2[i] << ", ";
	cout << endl;

	SimpleArray<int, 7> i7arr1;
	for (int i = 0; i < 7; ++i)
		i7arr1[i] = i * 10;

	SimpleArray<int, 7> i7arr2;
	i7arr2 = i7arr1;
	for (int i = 0; i < 7; ++i)
		cout << i7arr2[i] << ", ";
	cout << endl;

	//i7arr1 = i5arr1; 컴파일 에러~~!! <int, 5> 랑 <int, 7>은 다른 타입

	return 0;
}