//						<Virtual Function>



#include<array>
#include<iostream>

class Animal
{
public:
	virtual void speak()
	{
		std::cout << "Animal" << std::endl;
	}
	virtual ~Animal() = default;
};

class Cat : public Animal
{
public:
	void speak() override
	{
		std::cout << "Cat" << std::endl;
	}
};

class Dog :public Animal
{
	void speak() override
	{
		std::cout << "Dog" << std::endl;
	}
};
 
int main()
{
	//int i = 0;
	//std::cin >> i;
	//
	//Animal* polyAnimal;
	// 
	//if (i == 1)						//runtime(dynamic) polymorphism
	//	polyAnimal = new Cat();
	//else
	//	polyAnimal = new Animal();
	//
	//polyAnimal->speak();
	//delete polyAnimal;


	std::array<Animal*, 5> animals;

	for (auto& animalPtr : animals)
	 {
		int i = 0;
		std::cin >> i;
		if (i == 1)						
			animalPtr = new Cat();
		else
			animalPtr = new Dog();
	}

	for (auto& animalPtr : animals)
	{
		animalPtr->speak();
		delete animalPtr;
	}

	return 0;
}