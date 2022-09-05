//					<I/O inheritance>
//https://en.cppreference.com/w/cpp/io



//c++ 라이브러리 상속의 구조를 stream을 통해서 이용해 보기~~
#include<fstream>
#include<iostream>
#include<string>

class Cat
{
public:
	Cat(std::string name, int age)
		:mName(std::move(name))
		, mAge(age)
	{
	}
	/*void print()
	{
		std::cout << mName << ", " << mAge << "\n";
	}*/

	void print(std::ostream& os)
	{
		os << mName << ", " << mAge << "\n";
	}

	void setFromStream(std::istream& is)
	{
		//...
	}

private:
	std::string mName;
	int mAge;
};

int main()
{
	Cat kitty{ "kitty",3 };
	Cat nabi{ "nabi",2 };
	//kitty.print();
	//nabi.print();
	
	//kitty.print(std::cout);
	//nabi.print(std::cout);

	std::ofstream ofs{ "test.txt" };
	if (!ofs)
	{
		std::cout << "cannot open the file" << std::endl;
		return 0;
	}
	kitty.print(ofs);//iostrem 보다 아래에 있는 fstream을 이용한 예시
	nabi.print(ofs);

	ofs.close();
	return 0;
}