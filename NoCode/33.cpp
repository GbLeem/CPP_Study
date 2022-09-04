//						<Pure Virtual Function>


//pure virtal function : = 0 으로 표시된 것
//abstract class : pure virtal function이 하나라도 있는 클래스

#include<array>
#include<iostream>

class Animal //abstract class --> object 생성 불가능!!
{
public:
	virtual void speak() = 0; //pure virtal function
	virtual ~Animal() = default;
private:
	double height;
};

class Cat : public Animal
{
public:
	void speak() override //pure virtal function은 무조건 override 해야한다!
	{
		std::cout << "Cat" << std::endl;
	}
private:
	double weight;
};

int main()
{
	//Animal abs; 오류
	Cat kitty;

	return 0;
}

//-----------------------------------------


class Monster				//**interface class** : 내부에 implementation x, member variable x
{
public:
	virtual int attack() = 0;
	void walk()
	{
		///
	}
	virtual ~Monster() = default;
protected:
	int attackDmg;
	float moveSpeed;
};

class Skeleton :public Monster
{
public:
	int attack() override
	{
		//각각의 몬스터 공격 특성을 작성..
	}
	Skeleton()
	{
		attackDmg = 10;
		moveSpeed = 20.5;
	}
};
//위의 코드까지는 ok.. BUT 아래처럼 새로운 클래스가 추가된다면..

class Dragon : public Monster //만약 Monster에서 walk를 만들어두었는데... 날아다니는 것이 나와버리면 Base클래스도 수정을 해야함
{
	//다른 여러 작업들이 추가된다.
	//필요없는 함수들, 변수들도 가지게 된다.
	//-> 유지 보수 좋지 않음
	//해결 : 내부에 implementation x, member variable x
};
