//protected ����� ������ ������ ���

class Base
{
private:
	int privateNum;
protected:
	int protectedNum;
public:
	int publicNum;
};

class Derived1 : public Base
{

};


class Derived2 : protected Base
{
	//protected���� ���� �����(public���) protected�� ������Ѽ� ���
};

class Derived3 : private Base
{
	//private���� ���� �����(protected�� public ���) private�� ������Ѽ� ���
};

int main()
{
	Derived1 dr1;
	dr1.publicNum = 10; //�̰͸� ����

	Derived2 dr2;	
	//�Ұ���

	Derived3 dr3;
	//�Ұ���
}