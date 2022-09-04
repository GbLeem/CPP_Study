//					<Inheritance Intro>



//상속을 사용하는 이유
//1. class relationship
//2. code resuse
//3. class interface consistency(abstract/interface, pure/virtual function)
//4. dynamic function binding(virtual function, virtual table)


#include<iostream>

class Animal
{
public:
	void sleep() const
	{
		std::cout << "I'm sleeping" << std::endl;
	}
};

class Human :public Animal
{
public:
	void driveCar() const
	{
		std::cout << "I'm driving" << std::endl;
	}
};

class Base
{
private:
	int pri;
protected:
	int pro;
public:
	void setPRI(int n)
	{
		pri = n;
	}
	void setPRO(int n)
	{
		pro = n;
	}
};

class Derived1 :public Base
{
public:
	void test()
	{
		Base::pro = 100; //protected, public 접근 가능
		//Base::pri = 1; private는 접근 불가능
	}
};

class Derived2 :protected Base //Base의 public을 protected로 바꿔서 상속
{
public:
	void test()
	{
		Base::pro = 100;
	}
};

class Derived3 :private Base //Base의 모든 것이 private로 보임
{
public:
	void test()
	{
		Base::pro = 100;
	}
};

int main()
{
	//Human me;
	//me.driveCar();
	//me.sleep();

	Derived1 derived1;
	derived1.setPRI(100);
	derived1.setPRO(100);

	Derived2 derived2;
	//derived2.setPRI(100); protected가 되므로 사용 불가능!
	//derived2.setPRO(100);

	return 0;
}

//================================================
class A
{
public:
	int x;
protected:
	int y;
private:
	int z;
};

class B : public A
{
	// x is public
	// y is protected
	// z is not accessible from B
};

class C : protected A
{
	// x is protected
	// y is protected
	// z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
	// x is private
	// y is private
	// z is not accessible from D
};