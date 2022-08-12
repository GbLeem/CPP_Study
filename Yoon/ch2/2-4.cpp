//1.
//#include<cstring>
//#include<iostream>
//
//int main()
//{
//	const char* name = "Leem HJ";
//	const char* temp = "good";
//	char str[20] = "abc";
//	std::cout << strlen(name) << std::endl;
//	strcat_s(str, name);
//	std::cout << str << std::endl;
//	strcpy_s(str, name);
//	std::cout << str << std::endl;
//	std::cout << strcmp("abc", "ddd")<<std::endl;
//}


//2.
#include<ctime>
#include<cstdlib>
#include<iostream>

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		std::cout << rand() % 100 << std::endl;
	}
}