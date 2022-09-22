//					<std::vector>

//vector�� time complexity
//random access O(1)
//insert removal at the end O(1)
//insert removal linear in distance O(n)

#include<iostream>
#include<string>
#include<vector>

class Cat
{
public:
	explicit Cat(std::string name, int age)
		:mName{ name }
		, mAge{ age }
	{}
	void speak() const
	{
		std::cout << "Cat " << mName << mAge << std::endl;
	}
private:
	std::string mName;
	int mAge;
};

int main()
{
	std::vector<int>nums(10000, 1); //1�� 10000�� ���� 

	//nums�� vectorù��° ������ ����Ű�� vector�� ����� �˰��ֱ� ������ O(1)
	nums.emplace_back(2);
	nums.pop_back();

	nums.emplace(nums.begin(), 3); //��� ��ĭ�� ������ move�ؾ��� -> O(n)
	nums.erase(nums.begin()); //��� ��ĭ�� �������� move�ؾ��� -> O(n)
	//O(n) complexity �� ���Ǵ� ���� �� �����غ��� ���°��� ����.


	//push_back() VS emplace_back()
	std::vector<Cat>cats;
	cats.emplace_back(Cat{ "cat0",0 });
	cats.emplace_back(Cat{ "cat1",1 });

	//cats.emplace_back(Cat{ "kitty",2 }); //temp ��ü�� ������ �� move operation�� �ѹ� �۵��Ѵ�.
	cats.emplace_back("kitty", 2); // temp ��ü�� �������� �ʰ� �ٷ� �����ϴ� ���!
	//C++17���� emplace_back�� object�� reference�� ��ȯ�Ѵ�. (�Ʒ� ����)
	//Cat& cat = cats.emplace_back("kitty", 2);


	//���� �ڵ庸�� optimized!!
	cats.emplace_back( "cat0",0 );
	cats.emplace_back( "cat1",1 );

	
	Cat nabi{ "nabi",3 };
	cats.emplace_back(nabi);// copy
	cats.emplace_back(std::move(nabi));// move


	for (const auto& cat : cats)
	{
		cat.speak();
	}

	return 0;
}