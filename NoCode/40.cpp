//							<Unique Pointer>


//exclusive ownership�� ������ -> �ϳ��� ������Ʈ�� �ϳ��� �����͸� ����ų �� �ִ� ��!
//Unique pointer�� class ���� member variable�� pointer�� ������ �ϴ� ��� �����
//ex) dynamic polymorphism

#include<iostream>
#include<memory>

class Cat
{
public:
	Cat()
		:mAge{ 0 }
	{
		std::cout << "Cat constructor" << std::endl;
	}
	~Cat()
	{
		std::cout << "Cat desturctor" << std::endl;
	}

private:
	int mAge;
};

void foo(Cat*ptr)
{
	Cat* fooPtr = ptr;
}

int main()
{
	//Cat* catRPtr = new Cat();
	//Cat* catRPtr2 = catRPtr;
	//foo(catRPtr);
	//delete catRPtr;
	// ���� �ڵ����.. ���ο� Cat ������Ʈ�� ���� 4���� �����Ͱ� ����Ű�� �ִ�.
	
	
	std::unique_ptr<Cat>catSPtr1 = std::make_unique<Cat>();
	//std::unique_ptr<Cat>catSPtr2 = catSPtr1; �Ұ���!!
	std::unique_ptr<Cat>catSPtr2 = std::move(catSPtr1); //����.. ownership�� �Ѱ���

	return 0;
}

//================== dynamic polymorphism ���� ���� =============

class Animal
{

};

class Tiger : public Animal
{
};
class Lion : public Animal
{
};

class Zoo
{
public:
	Zoo(int n)
	{
		if (n == 1)
			//mAnimal = new Tiger();
			mAnimal = std::make_unique<Tiger>(); //better!! -> rule of three �� ������� �ʾƵ� �ȴ�
		else
			//mAnimal = new Lion();
			mAnimal = std::make_unique<Lion>();
	}
private:
	//Animal* mAnimal;
	std::unique_ptr<Animal> mAnimal;
};