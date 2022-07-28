class Base
{
public:
	void mf();
};

class Derived :public Base
{
public:
	void mf(); //Base::mf()를 가린다. -> 상속받은 비가상 함수를 재정의하지 말자
};

int main()
{
	Derived x;
	Base* pB = &x;
	pB->mf(); //Base::mf 호출

	Derived* pD = &x;
	pD->mf(); //Derived::mf 호출
}