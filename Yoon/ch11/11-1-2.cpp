//����Ʈ ���� ������ ������
//-> ������ ������ ���� �Ҵ��� �ϴ� ��� ����Ʈ ���� �������� ���� �߻�
//�ذ�1. deep copy�� �ϵ��� ����
//�ذ�2. �޸� ������ �߻����� �ʵ���, deep cop�� �ռ� �޸� ������ ���� �ʿ�

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
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "call destructor" << endl;
	} 

	Person& operator=(const Person& ref) //deep copy�� �޸� ���� ���� ���ִ� ������ �����ε�
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

	//��� �������� �Ҹ��� �ѹ��� ȣ��ȴ�... -> ���� �߻�(swallow copy)�� �Ͼ�� ������ �����
	//���� ������ �����ε����� �ذ�
}

//Derived Ŭ�������� ���� �����ڿ� ���� �ƹ��� ��ð� ���ٸ� baseŬ������ ���� �����ڰ� ȣ����� �ʴ´�.
//Derived Ŭ�������� BaseŬ������ �����ڿ� ���� ��ø� ����
//ex)
// First& operator=(const First& ref) { ... } -> Base Ŭ���� ����
// Second& operator=(const Second& ref)
//{
//	...
//	First::operator=(ref);					  ->Derived Ŭ�������� ����ϱ�
//	...
//}
