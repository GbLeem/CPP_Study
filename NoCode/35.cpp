//						<Virtual Inheritance>


#include<iostream>

class Animal
{
public:
	virtual void speak()
	{
		std::cout << "Animal" << std::endl;
	}
private:
	double animalData;
};

class Lion :virtual public Animal
{
public:
	virtual void speak()
	{
		std::cout << "Lion" << std::endl;
	}
private:
	double lionData;
};

int main()
{
	std::cout << sizeof(Lion) << std::endl;

	Animal* polyAnimal = new Lion();
	polyAnimal->speak();
	delete polyAnimal;

	return 0;
}


//virtual ����� �ƴ� ���
//Animal Ŭ������ *VT, animalData
//Lion Ŭ������ *VT, animalData, lionData => 24 byte

//virtual ����� ���
//Animal Ŭ������ ������ ����.
//Lion Ŭ������ *VT(animal), animalData, *VT(lion), lionData => 32 byte
//���� main �ڵ�ó�� ����ϰԵ� ��� Lion VT�� Lion::speak�� ���� �ּҸ� ����Ű�� �ȴ�.
//Lion speak������ offset�� �����ϴµ�, Lion�� ���� ���� *VT(animal)�� ���� ��ŭ �������ִ����� �˷��ִ� offset���̴�.
//offset�� �ִ������� �������� ������ DerivedŬ������ ũ�⸦ ��Ÿ���� ���ؼ��̴�.
//-> ���̾Ƹ�� ������ ��� �������� �ߺ��� ���� ���ؼ� virtual inheritance�� ����Ѵ�!