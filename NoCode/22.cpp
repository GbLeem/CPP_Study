//				<OOP intro>


//Abstraction : class 의 모델링 과정
//Encapsulation : 데이터 숨기기 
//Inheritance : 
//Polymorphism -> function overloading => static
//				  function overrding => dynamic


//class는 definition
// 메모리를 차지하는 것들을 object

#include<iostream>

class Cat
{
public:
	void Speak()
	{
		std::cout << "hi" << std::endl;
	}
	void SetAge(int age)
	{
		mAge = age;
	}
	int GetAge() const
	{
		return mAge;
	}
private:
	int mAge;
};

int main()
{

}