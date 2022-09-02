#include<string>
#include<iostream>

class Cat
{
public:
	void SetName1(std::string name)
	{
		mName = name;
	}
	void SetName2(std::string &&name) 
	{
		mName = std::move(name);
	}
	void SetName3(const std::string& name)
	{
		mName = std::move(name);
	}
	void SetName4(std::string name) //가장 좋은 방식
	{
		mName = std::move(name);
	}
private:
	std::string mName;
};

int main()
{
	Cat kitty;
	std::string s = "kitty";

	kitty.SetName1(s);//2 copy
	kitty.SetName1("nabi");

	//kitty.SetName2(s); //compile error
	//kitty.SetName2("nabi");

	kitty.SetName3(s); //1 copy
	kitty.SetName3("nabi"); //1 copy

	kitty.SetName4(s); //1 copy
	kitty.SetName4("nabi"); //0 copy (copy elision)-> 컴파일러 최적화

}