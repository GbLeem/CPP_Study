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
	//speak �� virtual, override �ϸ� ����� ���� �þ��.
	//-> virtal table�� ����Ű�� ������ ����(8byte)�� ������ �ȴ�.
	//�� ������Ʈ �� �ٸ� virtual table�� ������ �ȴ�.

	std::cout << "animal size : " << sizeof(Animal) << std::endl; //16
	std::cout << "cat size : " << sizeof(Cat) << std::endl;		  //24

	Animal* polyAnimal = new Cat();
	polyAnimal->speak(); //Cat ���!! (virtual table�� � �������� �����غ���)
	delete polyAnimal;

	return 0;
}