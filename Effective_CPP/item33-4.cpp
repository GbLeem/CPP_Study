class Base
{
private:
	int x;

public:
	virtual void mf1() = 0;
	virtual void mf1(int);
};

class Derived : private Base //private 상속!!
{
public:
	virtual void mf1() //전달함수(forwarding function) 기법 사용 -> int 들어있지 않은것만 사용하겠다!
					   //using을 사용하는 경우 그 이름에 해당하는 모든 것들이 파생 클래스로 들어와 버리는 문제가 있다
	{
		Base::mf1();
	}
};

int main()
{
	Derived d;
	int x;

	d.mf1();
	d.mf1(x); //Error! Base::mf1()은 가려져있다. (고의적으로 사용을 하지 않기)
}
