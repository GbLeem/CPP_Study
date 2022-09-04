//						<Virtual Function>



#include<iostream>

class Animal
{
public:
	Animal()
	{
		std::cout << "animal constructor" << std::endl;
	}
	virtual ~Animal() //virtual key word 추가!!!
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

	Animal* polyCat = new Cat(); //cat destructor가 호출되지 않는 문제가 발생합니다요
	delete polyCat; 


	//** Base class 의 destructor는 무조건 virtual public 혹은 protected 여야 합니다!! **
	return 0;
}