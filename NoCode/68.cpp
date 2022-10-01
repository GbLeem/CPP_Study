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
	//�Լ� ���� const : ���� ���� ���ȭ
	//�Լ� ���� const : ��� ������ �������� ��������
	const std::string& name() const
	{
		return mName;
	}
private:
	int mAge;
	std::string mName;
};
bool operator < (const Cat &cat1, const Cat &cat2) //operator ������ֱ�
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
//	//100 5 4 3 2 1 -1 ���
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
//	std::set<Cat> cats; // < ���۷����Ͱ� ��� ���� �߻� -> operator������ֱ�
//	cats.emplace(1, "kitty");
//	cats.emplace(2, "nabi");
//	cats.emplace(2, "meow"); //set�� Ư¡�� ���� set�� ������ ����(2 �ߺ�)
//
//	for (const auto &cat : cats)
//	{
//		cat.speak();
//	}
//	std::cout << std::endl;
//}

int main()
{
	std::multiset<int> nums{ 1,2,7,7,4,5,5 }; //��������

	for (const auto& num : nums)
	{
		std::cout << num << " "; //1 2 4 5 5 7 7 ���
	}
	std::cout << std::endl;
}