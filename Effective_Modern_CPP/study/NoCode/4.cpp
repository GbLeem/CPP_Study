//			<Stack Frame>

#include<iostream>

//void foo()
//{
//	int a;
//	int b;
//}
//
//void bar()
//{
//	Cat cat;
//	Dog dog;
//}
//
//int main()
//{
//	int a;
//	double b;
//
//	foo();
//	bar();
//
//	return 0;
//}

//메모리 스택은 변수 단위로 쌓이는 것이 아니라 stack frame단위로
//function call에 따라 쌓이고 해제된다.

//메모리가 쌓이는 중간에 argument나 return address 등이 사이사이에 들어간다.


class Cat
{
public:
	Cat()
	{
		m_age = 1;
	}
	~Cat();
	void AddAge(int arg)
	{
		m_age += arg;
	}
private:
	int m_age;
};

int main()
{
	Cat cat;
	cat.AddAge(10);

	return 0;
}


//맨 처음부터(위부터)
//1. main 쌓임 (4byte)
//2. Cat의 생성자->생성자 끝나면서 삭제
//3. AddAge() 쌓임 -> return instructor address / argument /this 
				// 를 포함한 stack frame 
				// this : member variable을 다루기 위한 주소
//4. AddAge() 끝나면서 삭제
//5. Cat 소멸자 생성-> 삭제
//6. main 삭제

