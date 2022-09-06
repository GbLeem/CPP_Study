//							<Shared Pointer>


//Shared ownership�� ������!!
//�׷��� ��� pointer�� RAII ����� ���߾�� �Ѵ�.
//reference counter�� ������ �޸� leak�� �����Ѵ�.

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

class Dog
{
public:
	Dog()
	{
		std::cout << "Dog constructor" << std::endl;
	}
	~Dog()
	{
		std::cout << "Dog desturctor" << std::endl;
	}

	std::shared_ptr<Dog> mVar;//�޸� leka�� ��� variable
	std::shared_ptr<Dog> mFriend; //���� ���� �ϴ� �Ǽ��� ��� variable
};

int main()
{
	/*Cat* catptr1 = new Cat();
	Cat* catptr2 = catptr1;
	delete catptr1;*/


	//Shared pointer �� ���� ����
	//std::shared_ptr<Cat> catPtr1 = std::make_shared<Cat>();
	//std::cout << "count: " << catPtr1.use_count() << std::endl;
	//std::shared_ptr<Cat>catPtr2 = catPtr1;
	//std::cout << "count: " << catPtr1.use_count() << std::endl;


	//Shared pointer�� leak ����
	//std::shared_ptr<Dog>mPtr = std::make_shared <Dog>();
	//mPtr->mVar = mPtr; //�ڱ� �ڽ��� ����Ű�鼭 reference count�� �ö�
	//
	//std::cout << "count : " << mPtr.use_count() << std::endl;


	//���� �ϴ� �Ǽ� ����
	std::shared_ptr<Dog> dogPtr1 = std::make_unique<Dog>();
	std::shared_ptr<Dog> dogPtr2 = std::make_unique<Dog>();

	dogPtr1->mFriend = dogPtr2;
	dogPtr2->mFriend = dogPtr1; 
	// destructor ȣ���� ���� �ʾҴ�!! -> memory leak
	//circular reference�� �������!!! -> ������ �߻��մϴ�..

	return 0;
}