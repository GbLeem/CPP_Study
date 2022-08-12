//ITEM 12 : Declare overriding functions override

#include<iostream>
class Base
{
public:
	virtual void doWork(); //가상 함수
};

class Derived :public Base
{
public:
	virtual void doWork(); //재정의 virtual 생략가능
};

int main()
{
	std::unique_ptr<Base> upb = std::make_unique<Derived>();
	upb->doWork();//Derived 클래스 함수 호출된다.
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
	//재정의 함수에 override 붙여주기
	virtual void mf1() const override;
	virtual void mf2(int x) override;
	virtual void mf3()& override;
	void mf4()const override; //virtual 없어도 된다.
};


//---------------------
//멤버 함수에 참조 한정자 있을때 주의 하기
#include<vector>

class Widget
{
public:
	using Datatype = std::vector<double>;

	Datatype& data() & //lvalue에 Widget에 대해 lvalue반환
	{
		return values;
	}
	Datatype&& data() &&//rvalue에 Widget에 대해 rvalue반환
	{
		return std::move(values);
	} 

private:
	Datatype values;
};

int main()
{
	Widget w;
	Widget makeWidget();//팩토리 함수 rvalue반환

	auto val1 = w.data();//복사 생성
	auto val2 = makeWidget().data();//이동(move) 생성
}