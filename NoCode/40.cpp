//							<Unique Pointer>


//exclusive ownership을 가진다 -> 하나의 오브젝트를 하나의 포인터만 가리킬 수 있는 것!
//Unique pointer는 class 에서 member variable로 pointer를 가져야 하는 경우 사용함
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
	// 위의 코드까지.. 새로운 Cat 오브젝트에 대해 4개의 포인터가 가리키고 있다.
	
	
	std::unique_ptr<Cat>catSPtr1 = std::make_unique<Cat>();
	//std::unique_ptr<Cat>catSPtr2 = catSPtr1; 불가능!!
	std::unique_ptr<Cat>catSPtr2 = std::move(catSPtr1); //가능.. ownership을 넘겨줌

	return 0;
}

//================== dynamic polymorphism 개선 예시 =============

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
			mAnimal = std::make_unique<Tiger>(); //better!! -> rule of three 를 고려하지 않아도 된다
		else
			//mAnimal = new Lion();
			mAnimal = std::make_unique<Lion>();
	}
private:
	//Animal* mAnimal;
	std::unique_ptr<Animal> mAnimal;
};