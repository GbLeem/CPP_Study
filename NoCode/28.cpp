//						<operator overloading>

//https://en.cppreference.com/w/cpp/language/operators

//function overloading : 함수 이름은 같지만 파라메터가 다를 때
//						-> static polymorphism (<-> dynamic polymorphism(use virtual keyword))


//operator overloading

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
class Cat
{
public:
	Cat(std::string name, int age)
		:mName(std::move(name))
		, mAge(age)
	{
	}
	const std::string& name() const
	{
		return mName;
	}
	int age() const
	{
		return mAge;
	}
	void print(std::ostream& os)const
	{
		os << mName << " " << mAge << std::endl;
	}
private:
	std::string mName;
	int mAge;
};

bool operator==(const Cat& c1, const Cat& c2)
{
	if (c1.age() == c2.age() && c1.name() == c2.name())
		return true;
	return false;
}

bool operator<(const Cat& c1, const Cat& c2)
{
	if (c1.age() < c2.age())
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const Cat& c)
{
	return os << c.name() << " " << c.age();
}

int main()
{
	Cat kitty{ "kitty",1 };
	Cat nabi{ "nabi",2 };

	kitty.print(std::cout);
	nabi.print(std::cout);

	if (kitty == nabi)						// == overloading
		std::cout << "same" << std::endl;
	else
		std::cout << "not same" << std::endl;

	if (kitty < nabi)						// < overloading
		std::cout << "nabi is old" << std::endl;
	else
		std::cout << "kitty is old" << std::endl;

	std::cout << kitty << std::endl;		// << overloading
	std::cout << nabi << std::endl;

	return 0;
}