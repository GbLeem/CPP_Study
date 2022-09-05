//						<Object Slicing>


//C++ ��ӿ��� ��ġ ���� ����� ������ ���!
//Derived Ŭ�������� BaseŬ������ copy�� �Ǵ� ��� Derived Ŭ���� ���� ������ �߷������� ����

#include<iostream>

class Animal
{
public:
	Animal() = default;
	Animal& operator=(Animal other) = delete;

	virtual void speak()
	{
		std::cout << "animal" << std::endl;
	}
	virtual ~Animal() = default;

protected:
	Animal(const Animal& other) = delete; 

private:
	double animalData = 0.0f;
};

class Cat :public Animal
{
public:
	Cat(double d)
		:catData(d)
	{
	}
	void speak() override
	{
		std::cout << "Cat" << std::endl;
	}
private:
	double catData;
};

int main()
{
	Cat kitty{ 1.0 };
	kitty.speak();									    //cat

	Animal& animalRef = kitty;
	animalRef.speak();								    //cat

	std::cout << "-------------" << std::endl;

	//Animal animalObj = kitty; //copy constructor
	//animalObj.speak();								//animal -> object slicing

	return 0;

	//object slicing�� ���� ���ؼ��� copy constructor�� ������� ���ϰ� ����� ������!
	//�׷��� copy constructor�� ���ƹ����� Derived Ŭ���� ���� copy constructor�� ���ƹ�����..
	//-> copy constructor�� protected�� ������.. 
	//=> ���� ���� ����� base Ŭ������ "���� �߻� Ŭ����" �� ����� ������ ���� �ְ��!!!

}

//!!����!!
//<Inheritance problems>
//1. object slicing
//-> copy constructor�� �����ֱ�
//2. operator overloading
//-> base���� ���ǵ� operator�� derived������ �����ϱ�
//=> ���� ���� �ذ� ����� Base Ŭ������ pure abstract class�� �����