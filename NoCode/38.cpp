//					<I/O inheritance>
//https://en.cppreference.com/w/cpp/io



//c++ ���̺귯�� ����� ������ stream�� ���ؼ� �̿��� ����~~
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
	kitty.print(ofs);//iostrem ���� �Ʒ��� �ִ� fstream�� �̿��� ����
	nabi.print(ofs);

	ofs.close();
	return 0;
}