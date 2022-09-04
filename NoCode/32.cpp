//						<Virtual Table>


#include<array>
#include<iostream>

class Animal
{
public:
	virtual void speak()
	{
		std::cout << "Animal" << std::endl;
	}
	//virtual ~Animal() = default;
private:
	double height;
};

class Cat : public Animal
{
public:
	void speak() override
	{
		std::cout << "Cat" << std::endl;
	}
private:
	double weight;
};

int main()
{
	//speak 를 virtual, override 하면 사이즈가 더욱 늘어난다.
	//-> virtal table을 가리키는 포인터 변수(8byte)를 가지게 된다.
	//각 오브젝트 당 다른 virtual table을 가지게 된다.

	std::cout << "animal size : " << sizeof(Animal) << std::endl; //16
	std::cout << "cat size : " << sizeof(Cat) << std::endl;		  //24

	Animal* polyAnimal = new Cat();
	polyAnimal->speak(); //Cat 출력!! (virtual table이 어떤 것인지를 생각해보기)
	delete polyAnimal;

	return 0;
}