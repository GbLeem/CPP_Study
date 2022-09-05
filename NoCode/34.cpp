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
//	//Liger Object�� ��� LionData, LionVT pointer / TigerData, TigerVT pointer / LigerData => 40 byte
//
//	Lion* polyLion = new Liger(); // polyLion �� LionData, LionVT pointer�� �� �� �ִ�.(LionVT�� LigerVT�� ����Ų��)
//	polyLion->speak();
//	delete polyLion;
//
//	Liger* ligerPtr = new Liger(); //ligerPtr�� ������ ����� 40 ����Ʈ ������ ��� ���� �����ϸ�, 
//								   //LionVT pointer�� TigerVT pointer�� �� �� LigerVT�� ����Ű�� �ȴ�.
//	ligerPtr->speak();
//	delete ligerPtr;
//	return 0;
//}


//					<Diamond Inheritance>
// Virtual inheritance �� ���� �ذ�
int main()
{
	Liger liger;
	liger.speak(); //Animal constructor �ι� ȣ�� -> virtual public inheritance ���!

	return 0;
}