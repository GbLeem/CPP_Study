//				<Various Templates>


//class template ���� -> vector
//std::vector<int> ints;
//std::vector<double> doubles;

#include<vector>
#include<iostream>

template<typename T>
class Stack
{
public:
	void push(T elem)
	{
		mVec.emplace_back(std::move(elem));
	}

	bool pop(T& elem)
	{
		if (mVec.size() == 0)
			return false;
		elem = mVec[mVec.size() - 1];
		mVec.pop_back();
		return true;
	}
private:
	std::vector<T> mVec;
};

int main()
{
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);

	int n;
	while (stack.pop(n))
		std::cout << n << std::endl;
}


//Aliasing template (Aliasing: ����)
//C++ 11 ������ typedef

#include<iostream>
#include<vector>

template<typename T>
using myKey = std::vector<std::array<T, 64>>

int main()
{
	//Aliasing ����
	//using myType = std::vector<std::array<uint8_t,64>>;  �̷��� ������ ��� ���
	using myInt = int;
	myInt a{ 10 };
	std::cout << a << std::endl;

	//Aliasing template ����
	myKey<int> intKeys;
	myKey<double> doubleKeys;

	return 0;
}


//variable template
//c++20 ���� pi���� ���� template�� ������� �ִ� ���� �߰��Ǿ���.

#include<iostream>

template<class T>
constexpr T pi = T(3.1415926535897932385L);

int main()
{
	int intPi = pi<int>;
	float floatPi = pi<float>;

	return 0;
}