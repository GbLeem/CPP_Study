//				<OOP intro>


//Abstraction : class �� �𵨸� ����
//Encapsulation : ������ ����� 
//Inheritance : 
//Polymorphism -> function overloading => static
//				  function overrding => dynamic


//class�� definition
// �޸𸮸� �����ϴ� �͵��� object

#include<iostream>

class Cat
{
public:
	void Speak()
	{
		std::cout << "hi" << std::endl;
	}
	void SetAge(int age)
	{
		mAge = age;
	}
	int GetAge() const
	{
		return mAge;
	}
private:
	int mAge;
};

int main()
{

}