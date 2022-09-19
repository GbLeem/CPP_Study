//				<higher orfer function>


//higher orfer function : 함수를 argument로 받는 혹은 함수를 결과로 내는 function 

#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

int main()
{
	std::vector<int> nums{ 1,2,3,4,5,6,7,8,9,10 };

	//========================================================
	//홀수 걸러줌
	auto filterOdd = [](int n)
	{
		return n % 2 == 1;
	};
	nums.erase(std::remove_if(nums.begin(), nums.end(), filterOdd),nums.end());

	/*nums.erase(std::remove_if(nums.begin(), nums.end(), [](int n)
		{
			return n % 2 == 1;
		}), nums.end());*/
	//========================================================
	//sorting
	std::sort(nums.begin(), nums.end(), [](int a, int b)
		{
			return a > b;
		});
	//========================================================
	//5에 가까운 수부터 sorting
	std::sort(nums.begin(), nums.end(), [](int a, int b)
		{
			return std::abs(a - 5) < std::abs(b - 5);
		});
	//========================================================
	//reduce -> 합 구현
	int sum = std::reduce(nums.begin(), nums.end(), 0, [](int a, int b)
	{
		return a + b;
	});

	std::cout << sum << std::endl;
	//========================================================
	//reduce -> 곱 구현
	int multi = std::reduce(nums.begin(), nums.end(), 1, [](int a, int b)
		{
			return a * b;
		});

	std::cout << multi << std::endl;
	//========================================================

	for (int num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;

}