//디폴트 대입 연산자 문제점
//-> 생성자 내에서 동적 할당을 하는 경우 디폴트 대입 연산자의 문제 발생
//해결1. deep copy를 하도록 구현
//해결2. 메모리 누수가 발생하지 않도록, deep cop에 앞서 메모리 해제의 과정 필요

#include<iostream>
#include<cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
		:age(myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "call destructor" << endl;
	} 

	Person& operator=(const Person& ref) //deep copy와 메모리 누수 방지 해주는 연산자 오버로딩
	{
		delete[]name;
		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy_s(name, len, ref.name);
		age = ref.age;
		return *this;
	}
};

int main()
{
	Person man1("Leem", 26);
	Person man2("Kim", 25);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;

	//출력 과정에서 소멸자 한번만 호출된다... -> 문제 발생(swallow copy)가 일어나서 문제가 생긴것
	//대입 연산자 오버로딩으로 해결
}

//Derived 클래스에서 대입 연산자에 대한 아무런 명시가 없다면 base클래스의 대입 연산자가 호출되지 않는다.
//Derived 클래스에서 Base클래스의 연산자에 대한 명시를 하자
//ex)
// First& operator=(const First& ref) { ... } -> Base 클래스 정의
// Second& operator=(const Second& ref)
//{
//	...
//	First::operator=(ref);					  ->Derived 클래스에서 명시하기
//	...
//}
