//ITEM 26 : Avoid overloading on universal references

#include<set>
#include<string>
#include<chrono>

//����ȭ ��Ű��
std::multiset<std::string> names; //���� �ڷᱸ��

template<typename T>
void logAndAdd(T&& name)
{
	auto now = std::chrono::system_clock::now(); //���� �ð� ���

	log(now, "logAndAdd"); //�α׿� ����ϱ�

	names.emplace(std::forward<T>(name)); //�̸��� ���� �ڷᱸ���� �߰��ϱ�
}

int main()
{
	std::string petName("Darla");

	logAndAdd(petName); // lval ����
	logAndAdd(std::string("Persephone")); // rval move
	logAndAdd("Patty Dog"); //multiset �ȿ� string ��ü�� ����
}

//�Ϻ� ���� ������
std::string nameFromIdx(int idx);

class Person
{
public:
	//template<typename T>
	//explicit Person(T&& n) //�Ϻ� ���� ������
	//	:name(std::forward<T>(n))

	explicit Person(Person& n) //�Ϻ����� ���ø����� �ν��Ͻ�ȭ�ȴ�.
		:name(std::forward<Person&>(n)) 
	{
	}

	explicit Person(int idx) //int���� �޴� ������
		:name(nameFromIdx(idx))
	{
	}
	
	Person(const Person& rhs);
	Person(Person&& rhs);

private:
	std::string name;
};

class SpecialPerson :public Person
{
public:
	SpecialPerson(const SpecialPerson& rhs) //���� ������
		:Person(rhs)						//base Ŭ������ �Ϻ� ���� ������ ȣ��
	{
	}

	SpecialPerson(SpecialPerson&& rhs) //�̵� ������
		:Person(std::move(rhs))		   //base Ŭ������ �Ϻ� ���� ������ ȣ��
	{
	}
};