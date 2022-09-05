//					Multiple Inheritance


#include<iostream>

class Animal
{
public:
	Animal()
	{
		std::cout << "Animal constructor" << std::endl;
	}
	virtual ~Animal()
	{
		std::cout << "Animal destructor" << std::endl;
	}

	virtual void speak()
	{
		std::cout << "Animal" << std::endl;
	}
private:
	double AnimalData;
};

class Lion : virtual public Animal
{
public:
	Lion()
	{
		std::cout << "Lion constructor" << std::endl;
	}
	virtual ~Lion()
	{
		std::cout << "Lion destructor" << std::endl;
	}

	virtual void speak()
	{
		std::cout << "Lion" << std::endl;
	}
private:
	double LionData;
};

class Tiger : virtual public Animal
{
public:
	Tiger()
	{
		std::cout << "Tiger constructor" << std::endl;
	}
	virtual ~Tiger()
	{
		std::cout << "Tiger destructor" << std::endl;
	}

	virtual void speak()
	{
		std::cout << "Tiger" << std::endl;
	}
private:
	double TigerData;
};

class Liger : public Lion, public Tiger
{
public:
	Liger()
	{
		std::cout << "Liger constructor" << std::endl;
	}
	~Liger()
	{
		std::cout << "Liger destructor" << std::endl;
	}
	void speak()override
	{
		std::cout << "Liger" << std::endl;
	}
private:
	double LigerData;
};

//int main()
//{
//	//Liger liger;
//	//Liger.speak();
//	//
//	//std::cout << sizeof(Liger) << std::endl; //40 
//	//Liger Object의 경우 LionData, LionVT pointer / TigerData, TigerVT pointer / LigerData => 40 byte
//
//	Lion* polyLion = new Liger(); // polyLion 은 LionData, LionVT pointer만 볼 수 있다.(LionVT는 LigerVT를 가리킨다)
//	polyLion->speak();
//	delete polyLion;
//
//	Liger* ligerPtr = new Liger(); //ligerPtr은 위에서 언급한 40 바이트 정보에 모두 접근 가능하며, 
//								   //LionVT pointer와 TigerVT pointer는 둘 다 LigerVT를 가리키게 된다.
//	ligerPtr->speak();
//	delete ligerPtr;
//	return 0;
//}


//					<Diamond Inheritance>
// Virtual inheritance 로 문제 해결
int main()
{
	Liger liger;
	liger.speak(); //Animal constructor 두번 호출 -> virtual public inheritance 사용!

	return 0;
}