//				<hash set>

#include<iostream>
#include<string>
#include<unordered_set>

class Cat
{
public:
	Cat(int age, std::string name)
		:mAge(age)
		, mName(name)
	{}

	void speak() const
	{
		std::cout << mAge << " " << mName << std::endl;
	}

	int age() const
	{
		return mAge;
	}
	const std::string& name() const
	{
		return mName;
	}
private:
	int mAge;
	std::string mName;
};

struct CatHash //Cat hash 정의
{
	std::size_t operator()(Cat const& c) const noexcept
	{
		std::size_t h1 = std::hash<int>{}(c.age());
		std::size_t h2 = std::hash<std::string>{}(c.name());
		return h1 ^ h2;
	}
};

namespace std //namespace에 넣기
{
	template<>
	struct hash<Cat>
	{
		std::size_t operator()(Cat const& c) const noexcept
		{
			std::size_t h1 = std::hash<int>{}(c.age());
			std::size_t h2 = std::hash<std::string>{}(c.name());
			return h1 ^ h2;
		}
	};
}
bool operator ==(const Cat& c1, const Cat& c2) //equality 정의
{
	return (c1.age() == c2.age() && c1.name() == c2.name());
}

int main()
{
	Cat kitty{ 1,"kitty" };
	Cat nabi{ 2,"nabi" };

	 //std::unordered_set<Cat>cats; //고양이 hash값과 equality가 정의되어있지 않기 때문에->정의해주기

	std::unordered_set<Cat, CatHash>cats;// 해결!!
	//std::unordered_multiset<Cat, CatHash>cats; //중복 허용

	//std::unordered_set<Cat>cats; //namespace에 넣으면 CatHash를 따로 안써줘도 된다.

	cats.emplace(kitty);
	cats.emplace(nabi);
	cats.emplace(2, "nabi");

	for (const auto& cat : cats)
	{
		cat.speak();
	}
	return 0;
}