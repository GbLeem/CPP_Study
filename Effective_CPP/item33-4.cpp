class Base
{
private:
	int x;

public:
	virtual void mf1() = 0;
	virtual void mf1(int);
};

class Derived : private Base //private ���!!
{
public:
	virtual void mf1() //�����Լ�(forwarding function) ��� ��� -> int ������� �����͸� ����ϰڴ�!
					   //using�� ����ϴ� ��� �� �̸��� �ش��ϴ� ��� �͵��� �Ļ� Ŭ������ ���� ������ ������ �ִ�
	{
		Base::mf1();
	}
};

int main()
{
	Derived d;
	int x;

	d.mf1();
	d.mf1(x); //Error! Base::mf1()�� �������ִ�. (���������� ����� ���� �ʱ�)
}
