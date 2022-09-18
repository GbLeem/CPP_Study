//			<C++ template Introduction>


//���ø� ����
// Function 
// Class
// Alias
// Variable
// C++20 : Concept(���ø� ���α׷��� �Ǽ� ����)


//function template ����
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
	//����1)
	int maxI = std::max<int>(1, 5);
	float maxF = std::max<float>(1.2f, 2.5f);

	std::cout << maxI << std::endl;
	std::cout << maxF << std::endl;

	//����2)
	std::vector<int> vecI;
	std::vector<float> vecF;

	//����3)
	int resI = add<int>(1, 2);
	auto res = add(1.2, 2.2); //type deduction���� �˾Ƽ� doubleŸ�� add�� ���������.
}