//���� ������

class Widget
{
private:
	int num1;
	int num2;

public:
	Widget(int n1, int n2)
		:num1(n1)
		, num2(n2)
	{

	}
	Widget(const Widget& temp)
		:num1(temp.num1)
		, num2(temp.num2)
	{

	}
};

int main()
{
	Widget num1(10,20);
	Widget num2 = num1;//Widget num2(num1) �̶� ���� �� : ������ ��ȯ �Ѵ�.
}


//explicit Ű����
//������ ��ȯ �����ش�.
//explicit Widget(const Widget& temp)
//	:num1(temp.num1)
//	, num2(temp.num2)
//{
//
//}
//��ó�� �����ϸ� ���� ���� ���� x

class A
{
private:
	int num;
public:
	explicit A(int n)
		:num(n)
	{

	}
};

int main()
{
	//A a = 3; explicit ���� ����� ��� �Ұ� / explicit ���ٸ� ���� �����ڷ� ��ȯ
	A aa(3); //���� ������ ȣ��
}