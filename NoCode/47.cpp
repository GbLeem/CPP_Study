//				<Template Concept>
//C++20 부터 도입 -> 더 안전한 template
//https://en.cppreference.com/w/cpp/concepts
//https://en.cppreference.com/w/cpp/language/constraints

//first 와 last는 iterator를 넣어달라고 만들었지만...iterator가 아닌 다른값을 넣더라도 컴파일이 된다
//-> 원치않은 결과 발생
template<typename Iter, typename T>
Iter find(Iter first, Iter last, const T& val)
{
	while (first != last)
	{
		if (*first == val)
			return first;
		first++;
	}
	return last;
}

#include<iostream>
#include<string>
#include<concepts>

//only integer numbers
template<typename T>
T sum1(T a, T b)
{
	static_assert(std::integral<T>, "only integral types");
	return a + b;
}

template<typename T>
T sum2(T a, T b) requires std::integral<T>
{
	return a + b;
}

//사용자 지정 concept 만들기
template<typename T>
concept Summable = std::integral<T> || std::floating_point<T>;

//operator를 통한 concept 지정
template<typename T>
concept Addable = requires(T x)
{
	x + x;
	x - x;
};

//사용자 지정 concept 반영된 템플릿
template<typename T>
T sum3(T a, T b) requires Summable<T>
{
	return a + b;
}

int main()
{
	std::cout << sum1<int>(10, 10) << std::endl;
	//만약 이런 동작을 원치 않고 integer만 되게 만들기!->template concept 사용
	std::cout << sum1<std::string>("abc", "def") << std::endl; //-> 컴파일 에러 발생함

	std::cout << sum2<int>(10, 10) << std::endl;
	//std::cout << sum2<std::string>("abc", "def") << std::endl; //by requires
	return 0;
}