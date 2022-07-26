//Base의 유효범위 : x, mf1, mf2, mf3
//Derived의 유효범위 : mf1, mf4

class Base
{
private:
	int x;

public:
	virtual void mf1() = 0;
	virtual void mf2();
	void mf3();
};

class Derived : public Base
{
public:
	virtual void mf1();
	void mf4();
};

void Derived::mf4()
{
	mf2(); //Derived 범위에 존재하지 않음 -> Base의 유효범위를 검색
}