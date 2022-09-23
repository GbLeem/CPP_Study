//						<vector loop>

//<for loop>
//1. index base
//2. iterator
//3. range base -> 가장 안전

#include<chrono>
#include<iostream>
#include<vector>

//누가 가장 빠른가?! -> case마다 달라짐 
//가장 안전하고 가독성 좋은 것은 range base이다.
int main()
{
	std::cout << "how many elements" << std::endl;
	std::size_t n;
	std::cin >> n;

	std::vector<int>numsA(n, 1);
	std::vector<int>numsB(n, 1);
	std::vector<int>numsC(n, 1);

	auto start = std::chrono::high_resolution_clock::now();
	//index base
	for (int i = 0; i < 1000; ++i)
	{
		for (std::size_t idx = 0; idx < numsA.size(); ++idx)
		{
			numsA[idx] *= 2;
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double>diff = end - start;
	std::cout << "idx loop" << diff.count() << "s\n";

	//iterator base
	start = std::chrono::high_resolution_clock::now();
	for (auto iter = numsB.begin(); iter != numsB.end(); ++iter)
	{
		(*iter) *= 2;
	}
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	std::cout << "iter loop" << diff.count() << "s\n";

	//ranged for loop
	start = std::chrono::high_resolution_clock::now();
	for (auto& num : numsC)
	{
		num *= 2;
	}
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	std::cout << "for ranged loop" << diff.count() << "s\n";

	return 0;
}


// for loop 안에서 벡터의 크기가 변하는 경우 index base의 for loop 써야한다.
int main()
{
	std::vector<int>nums{ 0,1,0,1 };

	//idx base => 0 1 0 1 2 2 출력 (정확함!)
	for (std::size_t idx = 0; idx < nums.size(); ++idx)
	{
		if (nums[idx] == 0)
		{
			nums.emplace_back(2);
		}
	} 

	//iter bas => 런타임 에러
	for (auto iter = nums.begin(); iter != nums.end(); ++iter)
	{
		if (*iter==0)
		{
			nums.emplace_back(2); //오류 발생함
		}
	}

	//for ranged base =>  0 1 0 1 2
	for (auto& num : nums)
	{
		if (num == 0)
		{
			nums.emplace_back(2);
		}
	}
	for (const int n : nums)
	{
		std::cout << n << " ";
	}
	std::cout << std::endl;
}