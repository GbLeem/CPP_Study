//Base�� ��ȿ���� : x, mf1, mf2, mf3
//Derived�� ��ȿ���� : mf1, mf4

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
	mf2(); //Derived ������ �������� ���� -> Base�� ��ȿ������ �˻�
}