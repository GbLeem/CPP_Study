#include<iostream>
#include<string>

template<typename T>
class NameObject
{
public:
	NameObject(const char* name, const T& value)
	{
		namevalue = name;
		objectValue = value;
	}
	NameObject(const std::string name, const T& value)
	{
		namevalue = name;
		objectValue = value;
	}


public:
	std::string namevalue;
	T objectValue;
};

int main()
{
	NameObject<int> no1("Smallest Prime number", 2);
	NameObject<int> no2(no1); //���� ������ ȣ�� -> �����ڸ� ������ �ɹ��� ���� ���� ���� Ŭ������ ��츸 �ڵ� ���� �� ���
											  //-> �����ü�� ������ ����� ��쵵 ��������(��� ����� ������ �Ұ���)
											  //=> ���� ��쿡�� ���� ���� �����ڸ� �������־�� �Ѵ�.
	
	std::cout << no2.namevalue << ' ' << no2.objectValue;

	
}