#ifndef __ARRAY_TEMPLATE_H_
#define __ARRAY_TEMPLATE_H_

#include<iostream>
#include<cstdlib>
using namespace std;

template<typename T>
class BoundCheckArray
{
public:
	BoundCheckArray(const BoundCheckArray& arr) = default;
	BoundCheckArray& operator=(const BoundCheckArray & arr) = default;
	BoundCheckArray(int len);
	T& operator[](int idx);
	T operator[](int idx)const;
	int GetArrLen() const;
	~BoundCheckArray();

private:
	T* arr;
	int arrlen;
};

template<typename T>
BoundCheckArray<T>::BoundCheckArray(int len)
	:arrlen(len)
{
	arr = new T[len];
}

template<typename T>
T& BoundCheckArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "out of bound" << endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
T BoundCheckArray<T>::operator[](int idx)const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "out of bound" << endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
int BoundCheckArray<T>::GetArrLen() const
{
	return arrlen;
}

template<typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[]arr;
}


#endif 
