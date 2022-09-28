//				<Vector Intro>

//1. dynamic size array
//2. sequence container

#include<iostream>
#include<vector>
//int main()
//{
//	int* numsPtr = new int[5];
//	for (int i = 0; i < 5; ++i)
//	{
//		numsPtr[i] = i;
//	}
//	delete[] numsPtr; //delete 쓰지 않으면 문제 생김
//
//	//std::vector -> delete 필요없음
//	std::vector<int> numsVec(5);
//	for (int i = 0; i < 5; ++i)
//	{
//		numsVec[i] = i;
//	}
//}


int main()
{
	std::vector<int>nums{ 0,1,2,3,4 };
	std::cout << nums.size() << std::endl; //element의 갯수 : 5
	nums.emplace_back(5); //맨 뒤에 숫자 삽입
	nums.pop_back();//맨 뒤에것 삭제

	//vector iterate 방법1
	for (std::size_t idx = 0; idx < nums.size(); ++idx)
	{
		std::cout << nums[idx] << std::endl;
	}
	//vector iterate 방법2
	for (auto iter= nums.begin();iter!=nums.end(); ++iter)
	{
		std::cout << (*iter) << std::endl;
	}
	////vector iterate 방법3 : ranged for 가장 좋은 방식
	for (const int& num : nums)
	{
		std::cout << num << std::endl;
	}
}

class Cat
{
public:
	explicit Cat(int age)
		:mAge{age}
	{}
	void speak() const
	{
		std::cout << "Cat " << mAge << std::endl;
	}
private:
	int mAge;
};

int main()
{
	std::vector<Cat>catVec;
	catVec.emplace_back(Cat{ 1 });
	catVec.emplace_back(Cat{ 2 });
	catVec.emplace_back(Cat{ 3 });
	catVec.emplace_back(Cat{ 4 });

	for (const auto& cats : catVec)
	{
		cats.speak();
	}
}