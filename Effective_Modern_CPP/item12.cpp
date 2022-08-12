//ITEM 12 : Declare overriding functions override

#include<iostream>
class Base
{
public:
	virtual void doWork(); //���� �Լ�
};

class Derived :public Base
{
public:
	virtual void doWork(); //������ virtual ��������
};

int main()
{
	std::unique_ptr<Base> upb = std::make_unique<Derived>();
	upb->doWork();//Derived Ŭ���� �Լ� ȣ��ȴ�.
}


//----------------------
class Base
{
public:
	virtual void mf1() const;
	virtual void mf2(int x);
	virtual void mf3()&;
	virtual void mf4()const;
};

class Derived:public Base
{
public:
	//������ �Լ��� override �ٿ��ֱ�
	virtual void mf1() const override;
	virtual void mf2(int x) override;
	virtual void mf3()& override;
	void mf4()const override; //virtual ��� �ȴ�.
};


//---------------------
//��� �Լ��� ���� ������ ������ ���� �ϱ�
#include<vector>

class Widget
{
public:
	using Datatype = std::vector<double>;

	Datatype& data() & //lvalue�� Widget�� ���� lvalue��ȯ
	{
		return values;
	}
	Datatype&& data() &&//rvalue�� Widget�� ���� rvalue��ȯ
	{
		return std::move(values);
	} 

private:
	Datatype values;
};

int main()
{
	Widget w;
	Widget makeWidget();//���丮 �Լ� rvalue��ȯ

	auto val1 = w.data();//���� ����
	auto val2 = makeWidget().data();//�̵�(move) ����
}