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
	//std::string b = s; //wrong! s�� �ش� ��� lvalue�̴�.
	std::string b = std::move(s);
}
int main()
{
	//std::string a = "good c++";
	//std::cout << "a: " << a << std::endl;
	//
	//std::string b = std::move(a);
	//std::cout << "b: " << b << std::endl;
	//std::cout << "a: " << a << std::endl; //�ƹ��͵� ��� x
	//std::move�� ���� ownership�� b���� �Ѱ���

	std::string a = "abc";
	storeByLRef(a);
	std::cout << "a: " << a << std::endl;
}
