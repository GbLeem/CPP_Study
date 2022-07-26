//Base의 유효범위 : x, mf1(2개), mf2, mf3(2개)
//Derived의 유효범위 : mf1(2개), mf3(2개), mf4

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

class Derived : public Base
{
public:
	using Base::mf1; //using 선언 
	using Base::mf3; //Base에 있는 것들 중 mf1과 mf3를 이름으로 가진 것을 Derived 유효범위로 가져옴

	virtual void mf1();
	void mf3();
	void mf4();
};

int main()
{
	Derived d;
	int x;

	d.mf1(); //Derived 호출
	d.mf1(x); //오류 사라짐! Base 호출
	d.mf2(); //Base 호출
	d.mf3(); //Derived 호출
	d.mf3(x); //오류 사라짐! Base 호출
}