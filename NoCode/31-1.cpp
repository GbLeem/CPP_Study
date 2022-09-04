//						<Virtual Function>



#include<iostream>

class Animal
{
public:
	Animal()
	{
		std::cout << "animal constructor" << std::endl;
	}
	virtual ~Animal() //virtual key word �߰�!!!
	{
		std::cout << "animal destructor" << std::endl;
	}
};

class Cat : public Animal
{
public:
	Cat()
	{
		std::cout << "cat constructor" << std::endl;
	}
	~Cat()
	{
		std::cout << "cat destructor" << std::endl;
	}
};

int main()
{
	//Animal animal;
	//Cat cat;

	//Animal* ptr = new Animal();
	//delete ptr;

	//Cat* ptr = new Cat();
	//delete ptr;

	Animal* polyCat = new Cat(); //cat destructor�� ȣ����� �ʴ� ������ �߻��մϴٿ�
	delete polyCat; 


	//** Base class �� destructor�� ������ virtual public Ȥ�� protected ���� �մϴ�!! **
	return 0;
}