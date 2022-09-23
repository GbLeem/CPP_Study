//						<vector loop>

//<for loop>
//1. index base
//2. iterator
//3. range base -> ���� ����

#include<chrono>
#include<iostream>
#include<vector>

//���� ���� ������?! -> case���� �޶��� 
//���� �����ϰ� ������ ���� ���� range base�̴�.
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


// for loop �ȿ��� ������ ũ�Ⱑ ���ϴ� ��� index base�� for loop ����Ѵ�.
int main()
{
	std::vector<int>nums{ 0,1,0,1 };

	//idx base => 0 1 0 1 2 2 ��� (��Ȯ��!)
	for (std::size_t idx = 0; idx < nums.size(); ++idx)
	{
		if (nums[idx] == 0)
		{
			nums.emplace_back(2);
		}
	} 

	//iter bas => ��Ÿ�� ����
	for (auto iter = nums.begin(); iter != nums.end(); ++iter)
	{
		if (*iter==0)
		{
			nums.emplace_back(2); //���� �߻���
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