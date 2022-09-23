//						<erase, remove>


//벡터의 여러 element를 지우는 방법

#include<iostream>
#include<vector>
#include<string>

class Cat
{
public:
	Cat(std::string name, int age)
		:mName{ std::move(name) }
		, mAge{ age }
	{}
	void speak() const
	{
		std::cout << "cat " << mName << " " << mAge << std::endl;
	}
	int age() const
	{
		return mAge;
	}
private:
	std::string mName;
	int mAge;
};
int main()
{
	std::vector<int>nums{ 0,1,0,1,0,1,0 };

	//nums.erase(std::remove(nums.begin(), nums.end(), 0), nums.end());

	auto iter = std::remove(nums.begin(), nums.end(), 0); //remove는 iterator 를 반환함
	//-> remove O(n)의 시간 복잡도

	for (int num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	nums.erase(iter, nums.end());

	for (int num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	//===========================
	//람다 expression으로 짝수 삭제
	std::vector<int>nums2{ 0,1,2,3,4,5,6 };
	nums2.erase(std::remove_if(nums2.begin(), nums2.end(), [](int n)
		{
			if (n % 2 == 0)
				return true;
			return false; 
		}), nums2.end());

	for (int num2 : nums2)
	{
		std::cout << num2 << " ";
	}
	std::cout << std::endl;
	//=============================
	//int가 아닌 다른 오브젝트 삭제

	std::vector<Cat>cats;
	cats.reserve(4);
	cats.emplace_back("cat1", 1);
	cats.emplace_back("cat2", 2);
	cats.emplace_back("cat3", 3);
	cats.emplace_back("cat4", 4);

	cats.erase(std::remove_if(cats.begin(), cats.end(), [](const Cat& other)
		{
			if (other.age() % 2 == 0)
				return true;
			return false;
		}), cats.end());
	for (auto& cat : cats)
	{
		cat.speak();
	}
	std::cout << std::endl;

	return 0;
}