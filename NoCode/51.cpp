//				<higher orfer function>


//higher orfer function : �Լ��� argument�� �޴� Ȥ�� �Լ��� ����� ���� function 

#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

int main()
{
	std::vector<int> nums{ 1,2,3,4,5,6,7,8,9,10 };

	//========================================================
	//Ȧ�� �ɷ���
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
	//5�� ����� ������ sorting
	std::sort(nums.begin(), nums.end(), [](int a, int b)
		{
			return std::abs(a - 5) < std::abs(b - 5);
		});
	//========================================================
	//reduce -> �� ����
	int sum = std::reduce(nums.begin(), nums.end(), 0, [](int a, int b)
	{
		return a + b;
	});

	std::cout << sum << std::endl;
	//========================================================
	//reduce -> �� ����
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