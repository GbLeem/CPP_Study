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
	Person me("Leem", 26); //Stack �޸𸮿� �Ҵ�
	Person* pPtr = new Person; //pPtr�� stack�� Person�� Heap���� ����
}