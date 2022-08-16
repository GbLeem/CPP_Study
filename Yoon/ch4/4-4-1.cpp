//클래스와 배열

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
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}
	Person()
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char* myname, int myage)
	{
		name = myname;
		age = myage;
	}
	void showPersonInfo()const
	{
		cout << "이름 : " << name << ", ";
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor" << endl;
	}
};

int main()
{
	//객체 배열
	/*Person perr[3];
	char namestr[100];
	char* strptr;
	int age;
	int len;

	for (int i = 0; i < 3; ++i)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;
		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy_s(strptr, len, namestr);
		perr[i].SetPersonInfo(strptr, age);
	}

	perr[0].showPersonInfo();
	perr[1].showPersonInfo();
	perr[2].showPersonInfo();*/


	//객체 포인터 배열
	Person* perr[3];
	char namestr[100];
	int age;

	for (int i = 0; i < 3; ++i)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;
		perr[i] = new Person(namestr, age);
	}

	perr[0]->showPersonInfo();
	perr[1]->showPersonInfo();
	perr[2]->showPersonInfo();

	delete perr[0];
	delete perr[1];
	delete perr[2];

	return 0;
}