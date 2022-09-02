//				<std::move>


#include<string>
#include<iostream>

void storeByLRef(const std::string& s) //1 copy
{
	std::string b = std::move(s);
	std::cout << "b: " << b << std::endl;
}

void storeByRRef(std::string&& s) //0 copy
{
	//std::string b = s; //wrong! s는 해당 경우 lvalue이다.
	std::string b = std::move(s);
}
int main()
{
	//std::string a = "good c++";
	//std::cout << "a: " << a << std::endl;
	//
	//std::string b = std::move(a);
	//std::cout << "b: " << b << std::endl;
	//std::cout << "a: " << a << std::endl; //아무것도 출력 x
	//std::move를 통해 ownership을 b에게 넘겨줌

	std::string a = "abc";
	storeByLRef(a);
	std::cout << "a: " << a << std::endl;
}
