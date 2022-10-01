//				<std::multiset>


#include<iostream>
#include<set>
#include<string>
struct customFn
{
	bool operator() (const int lhs, const int rhs) const
	{
		return lhs > rhs;
	}
};

class Cat
{
public:
	Cat(int age, std::string name)
		:mAge(age)
		,mName(name)
	{}

	void speak() const
	{
		std::cout << mAge << " " << mName << std::endl;
	}

	int age() const
	{
		return mAge;
	}
	//함수 앞의 const : 리턴 값을 상수화
	//함수 뒤의 const : 멤버 변수를 수정하지 않을거임
	const std::string& name() const
	{
		return mName;
	}
private:
	int mAge;
	std::string mName;
};
bool operator < (const Cat &cat1, const Cat &cat2) //operator 만들어주기
{
	return cat1.age() < cat2.age();
}

//int main()
//{
//	std::set<int, customFn>nums{ 1,2,3,4,5 };
//
//	nums.emplace(-1);
//	nums.emplace(100);
//	nums.emplace(2);
//	//100 5 4 3 2 1 -1 출력
//
//	for (const int num : nums)
//	{
//		std::cout << num << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

//int main()
//{
//	std::set<Cat> cats; // < 오퍼레이터가 없어서 에러 발생 -> operator만들어주기
//	cats.emplace(1, "kitty");
//	cats.emplace(2, "nabi");
//	cats.emplace(2, "meow"); //set의 특징에 의해 set에 들어오지 않음(2 중복)
//
//	for (const auto &cat : cats)
//	{
//		cat.speak();
//	}
//	std::cout << std::endl;
//}

int main()
{
	std::multiset<int> nums{ 1,2,7,7,4,5,5 }; //정렬해줌

	for (const auto& num : nums)
	{
		std::cout << num << " "; //1 2 4 5 5 7 7 출력
	}
	std::cout << std::endl;
}