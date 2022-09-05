//					<Dynamic Cast>


//RTTI : ������� �ʴ� ���� �����Ѵ�.

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
	//UpCast : Derived �ʿ��� Base �������� ĳ���� -> ������ ���� ���� ������ ���� ������ �Ű��ִ� ���̹Ƿ� ���� x
	//DownCast : Up cast�� �ݴ�
	
	//===================== up cast =========

	////Cat kitty;
	////kitty.speak();

	//Cat* catPtr = new Cat();

	////catPtr->speak();
	////delete catPtr;

	//Animal* animalPtr = catPtr; //UpCast!!
	//animalPtr->speak();
	////animalPtr->knead(); ����� only �������� ������ �Ұ���
	//delete animalPtr;

	//Animal* animalPtr2 = static_cast<Animal*> (catPtr); //UpCast
	//animalPtr2->speak();
	//delete animalPtr2;

	
	//===================== down cast =========
	
	//Animal* animalDownPtr = new Cat();
	////Cat* catPtr2 = animalDownPtr; // implicit downcast -> ���� �߻�!!
	//Cat* catPtr2 = static_cast<Cat*>(animalDownPtr);
	//catPtr2->speak();
	//catPtr2->knead(); //����������.. �׷��� �ſ� ������ �ൿ!! -> dynamic cast�� ���� ���� �����ϰ� ����� ����..

	////animalDownPtr->speak();
	////animalDownPtr->knead(); �Ұ���
	//delete catPtr2;

	
	//===================== dynamic cast =========

	Animal* animalPtr = new Animal();
	
	Cat* catptr = dynamic_cast<Cat*>(animalPtr); //Cast �Ϸ��� Ÿ�԰� �������� Ÿ���� ���� ������ nullptr ��ȯ�Ѵ�.
	
	if (catptr == nullptr)
	{
		std::cout << "not a cat object" << std::endl;
		return 0;
	}
	catptr->speak();
	catptr->knead();

	//�׷��� ���� Ŭ���� ������ �� ������ٸ�, ����� �ʿ䰡 ���� ����Դϴ�...
	return 0;
}