#include<string>

class Person
{
public:
	Person();
	virtual ~Person();

private:
	std::string name;
	std::string address;
};

class Student : public Person
{
public:
	Student();
	~Student();

private:
	std::string schoolname;
	std::string schooladdress;
};

int main()
{
	//bool validateStudent(Student s);
	bool validateStudent(const Student & s); //���� ���� ���޺��� �����ü ������ ����! 
	Student plato;
	bool platoIsOk = validateStudent(plato);
}