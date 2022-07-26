//Base�� ��ȿ���� : x, mf1(2��), mf2, mf3(2��)
//Derived�� ��ȿ���� : mf1, mf3, mf4

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

	d.mf1(); //Derived ȣ��
	d.mf1(x); //Derived::mf1 �� Base::mf1�� ����
	d.mf2(); //Base ȣ��
	d.mf3(); //Derived ȣ��
	d.mf3(x); //Derived::mf3�� Base::mf3�� ����
}