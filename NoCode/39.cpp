//							<Smart Pointer>


//Unique_ptr
//Shared_ptr 
//사용 이유 :  Resource Acquisition Is Initialization
//-> object와 resource의 life cycle을 일치시키기
//-> memory leak 방지

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
	std::vector<Cat> cat(5);					//vector의 경우도 알아서 메모리 관리 해줌
}
//int main()
//{	
//	//Cat* catRPtr = new Cat{ 3 };
//	//delete catRPtr;
//
//	//std::unique_ptr<Cat> catPtr = std::make_unique<Cat>(3); //delete 등의 관리를 하지 않아도 알아서 delete 해준다.
//
//	std::cout << "before scope" << std::endl;
//	{
//		std::unique_ptr<Cat> catSPtr = std::make_unique<Cat>(3); //scope base의 life cycle
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