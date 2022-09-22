//					<std::vector>

//vector의 time complexity
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
	std::vector<int>nums(10000, 1); //1을 10000개 넣음 

	//nums는 vector첫번째 공간을 가리키고 vector의 사이즈를 알고있기 때문에 O(1)
	nums.emplace_back(2);
	nums.pop_back();

	nums.emplace(nums.begin(), 3); //모두 한칸씩 옆으로 move해야함 -> O(n)
	nums.erase(nums.begin()); //모두 한칸씩 앞쪽으로 move해야함 -> O(n)
	//O(n) complexity 가 사용되는 경우는 잘 생각해보고 쓰는것이 좋다.


	//push_back() VS emplace_back()
	std::vector<Cat>cats;
	cats.emplace_back(Cat{ "cat0",0 });
	cats.emplace_back(Cat{ "cat1",1 });

	//cats.emplace_back(Cat{ "kitty",2 }); //temp 객체가 생성된 후 move operation이 한번 작동한다.
	cats.emplace_back("kitty", 2); // temp 객체가 생성되지 않고 바로 삽입하는 방식!
	//C++17부터 emplace_back은 object의 reference를 반환한다. (아래 예시)
	//Cat& cat = cats.emplace_back("kitty", 2);


	//위의 코드보다 optimized!!
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