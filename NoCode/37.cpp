//						<Object Slicing>


//C++ 상속에서 원치 않은 결과가 나오는 경우!
//Derived 클래스에서 Base클래스로 copy가 되는 경우 Derived 클래스 만의 정보가 잘려나가는 현상

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

	//object slicing을 막기 위해서는 copy constructor를 사용하지 못하게 만들어 버리기!
	//그러나 copy constructor를 막아버리면 Derived 클래스 간의 copy constructor도 막아버린다..
	//-> copy constructor를 protected로 보내기.. 
	//=> 가장 좋은 방법은 base 클래스를 "순수 추상 클래스" 로 만들어 버리는 것이 최고다!!!

}

//!!정리!!
//<Inheritance problems>
//1. object slicing
//-> copy constructor를 없애주기
//2. operator overloading
//-> base에서 정의된 operator를 derived에서도 정의하기
//=> 가장 좋은 해결 방안은 Base 클래스는 pure abstract class로 만들기