//				<Various Templates>


//class template 예시 -> vector
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


//Aliasing template (Aliasing: 별명)
//C++ 11 이전의 typedef

#include<iostream>
#include<vector>

template<typename T>
using myKey = std::vector<std::array<T, 64>>

int main()
{
	//Aliasing 예시
	//using myType = std::vector<std::array<uint8_t,64>>;  이렇게 복잡한 경우 사용
	using myInt = int;
	myInt a{ 10 };
	std::cout << a << std::endl;

	//Aliasing template 예시
	myKey<int> intKeys;
	myKey<double> doubleKeys;

	return 0;
}


//variable template
//c++20 부터 pi같은 수가 template로 만들어져 있는 것이 추가되었다.

#include<iostream>

template<class T>
constexpr T pi = T(3.1415926535897932385L);

int main()
{
	int intPi = pi<int>;
	float floatPi = pi<float>;

	return 0;
}