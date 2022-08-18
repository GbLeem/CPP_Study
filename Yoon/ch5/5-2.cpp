//**깊은 복사 얕은 복사** 

//디폴트 복사 생성자는 shallow copy를 한다.

//#include<iostream>
//using namespace std;
//
//class Person
//{
//private:
//	char* name;
//	int age;
//public:
//	Person(const char* myname, int myage)
//	{
//		int len = strlen(myname) + 1;
//		name = new char[len];
//		strcpy_s(name, len, myname);
//		age = myage;
//	}
//
//	Person(const Person& copy) //복사 생성자 정의 : 깊은 복사
//		:age(copy.age)
//	{
//		name = new char[strlen(copy.name) + 1];
//		int size = strlen(copy.name) + 1;
//		strcpy_s(name, size, copy.name);
//	}
//
//	void ShowPersonInfo() const
//	{
//		cout << "이름 : " << name << endl;
//		cout << "나이 : " << age << endl;
//	}
//	~Person()
//	{
//		delete[]name;
//		cout << "call destructor" << endl;
//	}
//};
//
//int main()
//{
//	Person man1("Leem hj", 25);
//	Person man2 = man1;
//	man1.ShowPersonInfo();
//	man2.ShowPersonInfo();
//	return 0;
//}

//위의 문제점은 얕은 복사를 통해 만들어진 객체가 소멸하면서 원래 본래 객체가 가리키던 문자열이 소멸되므로
//문제가 발생한다.


//문제 1.
#include<iostream>
using namespace std;

enum COMP_POS
{
	CLERK,
	SENIOR,
	ASSIST,
	MANAGER
};

class NameCard
{
private:
	char* Name;
	const char* company;
	const char* phone;
	int rank;

public:
	NameCard(const char* name, const char* company, const char* phone, COMP_POS pos)
		: company(company)
		, phone(phone)
		, rank(pos)
	{
		Name = new char[strlen(name) + 1];
		int size = strlen(name) + 1;
		strcpy_s(Name, size, name);
	}

	NameCard(const NameCard &copy)
		: company(copy.company)
		, phone(copy.phone)
		, rank(copy.rank)
	{
		Name = new char[strlen(copy.Name) + 1];
		int size = strlen(copy.Name) + 1;
		strcpy_s(Name, size, copy.Name);
	}
	const char* CheckPos(int rank) const
	{
		switch (rank)
		{
		case 0:
			return "사원";
		case 1:
			return "주임";
		case 2:
			return "대리";
		case 3:
			return "과장";
		default:
			break;
		}
	}

	void ShowNameCardInfo() const
	{
		cout << "이름 : " << Name << endl;
		cout << "회사 : " << company << endl;
		cout << "전화번호 : " << phone << endl;
		cout << "직급 : " << CheckPos(rank) << endl;
		cout << endl;
	}
};

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSenior;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
}