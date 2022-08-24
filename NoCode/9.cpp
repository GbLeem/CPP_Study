//				<Object Creation>

#include<iostream>
#include<string>
class Person
{
public:
	Person()
	{}
	Person(std::string name, int age)
		:name(name)
		,age(age)
	{}
private:
	std::string name;
	int age;
};

int main()
{
	Person me("Leem", 26); //Stack 메모리에 할당
	Person* pPtr = new Person; //pPtr은 stack에 Person은 Heap에서 생성
}