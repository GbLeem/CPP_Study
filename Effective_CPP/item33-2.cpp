//Base의 유효범위 : x, mf1(2개), mf2, mf3(2개)
//Derived의 유효범위 : mf1, mf3, mf4

class Base
{
private:
	int x;

public:
	virtual void mf1() = 0;
	virtual void mf1(int);
	virtual void mf2();

	void mf3();
	void mf3(double);
};

class Derived :public Base
{
public:
	virtual void mf1();
	void mf3();
	void mf4();
};

int main()
{
	Derived d;
	int x;

	d.mf1(); //Derived 호출
	d.mf1(x); //Derived::mf1 이 Base::mf1을 가림
	d.mf2(); //Base 호출
	d.mf3(); //Derived 호출
	d.mf3(x); //Derived::mf3가 Base::mf3를 가림
}