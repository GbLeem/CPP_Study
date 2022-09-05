//					<Dynamic Cast>


//RTTI : 사용하지 않는 것을 권장한다.

#include<iostream>

class Animal
{
public:
	virtual ~Animal() = default;
	virtual void speak()
	{
		std::cout << "animal" << std::endl;
	}
private:
	double animalData;
};

class Cat : public Animal
{
public:
	void speak() override
	{
		std::cout << "cat" << std::endl;
	}
	void knead()
	{
		std::cout << "cat only" << std::endl;
	}

private:
	double catData;
};

class Dog : public Animal
{
public:
	void speak() override
	{
		std::cout << "dog" << std::endl;
	}
	void wagTail()
	{
		std::cout << "dog only" << std::endl;
	}
private:
	double dogData;
};

int main()
{
	//UpCast : Derived 쪽에서 Base 쪽으로의 캐스팅 -> 정보가 많은 쪽을 정보가 적은 쪽으로 옮겨주는 것이므로 문제 x
	//DownCast : Up cast의 반대
	
	//===================== up cast =========

	////Cat kitty;
	////kitty.speak();

	//Cat* catPtr = new Cat();

	////catPtr->speak();
	////delete catPtr;

	//Animal* animalPtr = catPtr; //UpCast!!
	//animalPtr->speak();
	////animalPtr->knead(); 고양이 only 정보에는 접근이 불가능
	//delete animalPtr;

	//Animal* animalPtr2 = static_cast<Animal*> (catPtr); //UpCast
	//animalPtr2->speak();
	//delete animalPtr2;

	
	//===================== down cast =========
	
	//Animal* animalDownPtr = new Cat();
	////Cat* catPtr2 = animalDownPtr; // implicit downcast -> 오류 발생!!
	//Cat* catPtr2 = static_cast<Cat*>(animalDownPtr);
	//catPtr2->speak();
	//catPtr2->knead(); //가능해진다.. 그러나 매우 위험한 행동!! -> dynamic cast를 통해 조금 안전하게 만들기 가능..

	////animalDownPtr->speak();
	////animalDownPtr->knead(); 불가능
	//delete catPtr2;

	
	//===================== dynamic cast =========

	Animal* animalPtr = new Animal();
	
	Cat* catptr = dynamic_cast<Cat*>(animalPtr); //Cast 하려는 타입과 포인터의 타입이 같지 않으면 nullptr 반환한다.
	
	if (catptr == nullptr)
	{
		std::cout << "not a cat object" << std::endl;
		return 0;
	}
	catptr->speak();
	catptr->knead();

	//그러나 원래 클래스 구조를 잘 만들었다면, 사용할 필요가 없는 기능입니당...
	return 0;
}