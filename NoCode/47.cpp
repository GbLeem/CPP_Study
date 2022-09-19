//				<Template Concept>
//C++20 ���� ���� -> �� ������ template
//https://en.cppreference.com/w/cpp/concepts
//https://en.cppreference.com/w/cpp/language/constraints

//first �� last�� iterator�� �־�޶�� ���������...iterator�� �ƴ� �ٸ����� �ִ��� �������� �ȴ�
//-> ��ġ���� ��� �߻�
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

//����� ���� concept �����
template<typename T>
concept Summable = std::integral<T> || std::floating_point<T>;

//operator�� ���� concept ����
template<typename T>
concept Addable = requires(T x)
{
	x + x;
	x - x;
};

//����� ���� concept �ݿ��� ���ø�
template<typename T>
T sum3(T a, T b) requires Summable<T>
{
	return a + b;
}

int main()
{
	std::cout << sum1<int>(10, 10) << std::endl;
	//���� �̷� ������ ��ġ �ʰ� integer�� �ǰ� �����!->template concept ���
	std::cout << sum1<std::string>("abc", "def") << std::endl; //-> ������ ���� �߻���

	std::cout << sum2<int>(10, 10) << std::endl;
	//std::cout << sum2<std::string>("abc", "def") << std::endl; //by requires
	return 0;
}