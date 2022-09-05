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


//virtual 상속이 아닌 경우
//Animal 클래스는 *VT, animalData
//Lion 클래스는 *VT, animalData, lionData => 24 byte

//virtual 상속의 경우
//Animal 클래스는 이전과 같다.
//Lion 클래스는 *VT(animal), animalData, *VT(lion), lionData => 32 byte
//위의 main 코드처럼 사용하게될 경우 Lion VT의 Lion::speak의 시작 주소를 가리키게 된다.
//Lion speak위에는 offset이 존재하는데, Lion에 대한 값이 *VT(animal)로 부터 얼만큼 떨어져있는지를 알려주는 offset값이다.
//offset이 있는이유는 동적으로 생성된 Derived클래스의 크기를 나타내기 위해서이다.
//-> 다이아몬드 구조의 경우 데이터의 중복을 막기 위해서 virtual inheritance를 사용한다!