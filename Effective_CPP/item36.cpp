class Base
{
public:
	void mf();
};

class Derived :public Base
{
public:
	void mf(); //Base::mf()�� ������. -> ��ӹ��� �񰡻� �Լ��� ���������� ����
};

int main()
{
	Derived x;
	Base* pB = &x;
	pB->mf(); //Base::mf ȣ��

	Derived* pD = &x;
	pD->mf(); //Derived::mf ȣ��
}