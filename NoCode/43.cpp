//			<C++ template Introduction>


//템플릿 종류
// Function 
// Class
// Alias
// Variable
// C++20 : Concept(템플릿 프로그래밍 실수 방지)


//function template 예시
template<typename T>
T add(T a, T b)
{
	return a + b;
}


#include<algorithm>
#include<iostream>
#include<vector>
int main()
{
	//예시1)
	int maxI = std::max<int>(1, 5);
	float maxF = std::max<float>(1.2f, 2.5f);

	std::cout << maxI << std::endl;
	std::cout << maxF << std::endl;

	//예시2)
	std::vector<int> vecI;
	std::vector<float> vecF;

	//예시3)
	int resI = add<int>(1, 2);
	auto res = add(1.2, 2.2); //type deduction으로 알아서 double타입 add가 만들어진다.
}