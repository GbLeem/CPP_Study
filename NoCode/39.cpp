//							<Smart Pointer>


//Unique_ptr
//Shared_ptr 
//��� ���� :  Resource Acquisition Is Initialization
//-> object�� resource�� life cycle�� ��ġ��Ű��
//-> memory leak ����

//object => smart ptr
//resource => heap memory, thread, file access, mutex...

#include<iostream>
#include<memory>
#include<vector>

class Cat
{
public:
	Cat()
		:mAge{0}
	{
		std::cout << "cat constructor" << std::endl;
	}
	~Cat() noexcept
	{
		std::cout << "cat desturctor" << std::endl;
	}
private:
	int mAge;
};

void foo()
{
	std::cout << "foo function" << std::endl;
	std::vector<Cat> cat(5);					//vector�� ��쵵 �˾Ƽ� �޸� ���� ����
}
//int main()
//{	
//	//Cat* catRPtr = new Cat{ 3 };
//	//delete catRPtr;
//
//	//std::unique_ptr<Cat> catPtr = std::make_unique<Cat>(3); //delete ���� ������ ���� �ʾƵ� �˾Ƽ� delete ���ش�.
//
//	std::cout << "before scope" << std::endl;
//	{
//		std::unique_ptr<Cat> catSPtr = std::make_unique<Cat>(3); //scope base�� life cycle
//	}
//	std::cout << "after scope" << std::endl; 
//
//	return 0;
//}

int main()
{
	std::cout << "before foo" << std::endl;
	foo();
	std::cout << "after foo" << std::endl;
}